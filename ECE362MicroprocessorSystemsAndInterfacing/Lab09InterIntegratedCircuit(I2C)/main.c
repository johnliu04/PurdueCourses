#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "fifo.h"

#define FAIL -1
#define SUCCESS 0
#define WR 0
#define RD 1

void serial_init(void);
void test_prob3(void);
void check_config(void);
void test_wiring(void);
void micro_wait(unsigned int);
uint8_t read_EEPROM(uint16_t);

//===========================================================================
// Check wait for the bus to be idle.
void I2C1_waitidle(void) {
    while ((I2C1->ISR & I2C_ISR_BUSY) == I2C_ISR_BUSY);  // while busy, wait.
}

int I2C1_checknack(void) {
    if (I2C1->ISR & I2C_ISR_NACKF)
        return 1;
    return 0;
}

void I2C1_clearnack(void) {
    I2C1->ICR |= I2C_ICR_NACKCF;
}

//===========================================================================
// Subroutines for step 2.
//===========================================================================
// Initialize I2C1
/*
1.  Enable clock to GPIOB
2.  Configure PB6 and PB7 to alternate functions I2C1_SCL and I2C1_SDA
3.  Enable clock to I2C1
4.  Set I2C1 to 7 bit mode
5.  Enable NACK generation for I2C1
6.  Configure the I2C1 timing register so that PSC is 6, SCLDEL is 3 and SDADEL is 1 and SCLH is 3 and SCLL is 1
7.  Disable own address1 and own address 2 and set the 7 bit own address to 1
8.  Enable I2C1
 */
void init_I2C1() {
    // Student code goes here
    //1.Enable clock to GPIOB.
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    //2.Configure PB6 and PB7 to alternate functions I2C1_SCL and I2C1_SDA.
    GPIOB->MODER |= 2<<(2*6) | 2<<(2*7);
    GPIOB->AFR[0] |= 1<<(4*6) | 1<<(4*7);

    //3.Enable the clock to I2C1 in the RCC.
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    //4.Set I2C1 to 7 bit mode.
    I2C1->CR2 &= ~I2C_CR2_ADD10; //0:7-bit mode 1:10-bit mode

    //5.Enable NACK generation for I2C1.
    I2C1->CR2 |= I2C_CR2_NACK;

    //6.Configure the I2C1 timing register so that PRESC is 4, SCLDEL is 3
    I2C1->TIMINGR = 0;
    I2C1->TIMINGR &= ~I2C_TIMINGR_PRESC; // Clear prescaler
    I2C1->TIMINGR |= 4 << 28;           // Set prescaler to 4
    I2C1->TIMINGR |= 3 << 20;           // SCLDEL
    //and SDADEL is 1 and SCLH is 3 and SCLL is 9.
    I2C1->TIMINGR |= 1 << 16;           // SDADEL
    I2C1->TIMINGR |= 3 << 8;            // SCLH
    I2C1->TIMINGR |= 9 << 0;            // SCLL

    //7.Disable own address1 and own address 2 and set the 7 bit own address to 1.
    // I2C "Own address" 1 register (I2C_OAR1)
    I2C1->OAR1 &= ~I2C_OAR1_OA1EN;      // Disable own address 1
    I2C1->OAR1 =   I2C_OAR1_OA1EN | 0x2;// Set 7-bit own address 1
    I2C1->OAR2 &= ~I2C_OAR2_OA2EN;      // Disable own address

    //8.Enable I2C1.
    I2C1->CR1 |= I2C_CR1_PE;            // Enable I2C1
    //---------End-----------
}


//===========================================================================
// Subroutines for step 3.
//===========================================================================
// See lab document for description
void I2C1_start(uint8_t addr, uint32_t dir) {
    // Student code goes here
    //a.Clear the SADD bits in I2C1_CR2.
    I2C1->CR2 &= ~(I2C_CR2_SADD | I2C_CR2_NBYTES |I2C_CR2_RELOAD | I2C_CR2_AUTOEND |I2C_CR2_RD_WRN | I2C_CR2_START | I2C_CR2_STOP);
    //b.Set the SADD address in I2C1_CR2.
    I2C1->CR2 |= (addr<<1) & I2C_CR2_SADD;
    //c.Check the direction bit with ‘RD’ (see #define).  If dir = = RD, then set the RD_WRN bit in CR2 register.
    if (dir == RD){
        I2C1->CR2 |= I2C_CR2_RD_WRN;
    }
    //d.Set the START bit in CR2 register.
    I2C1->CR2 |= I2C_CR2_START;

    //---------End-----------
}

// See lab document for description
void I2C1_stop() {
    // Student code goes here
    //a.Check if the STOPF flag is set in ISR register.  If so, return.
    if (I2C1->ISR & I2C_ISR_STOPF){
        return;
    }
    //b.Set the STOP bit in CR2.
    I2C1->CR2 |= I2C_CR2_STOP;
    //c.Wait for the STOPF flag to be set in ISR register.
    while(!(I2C1->ISR & I2C_ISR_STOPF));
    //d.Clear the STOPF flag by writing to the STOPCF bit in the ICR register
    I2C1->ICR |= I2C_ICR_STOPCF;

    //---------End-----------
}

// See lab document for description
int I2C1_senddata(uint8_t* data, uint32_t size) {
    // Student code goes here
    //a.Clear the NBYTES of CR2.
    I2C1->CR2 &= ~(I2C_CR2_NBYTES);
    //b.Set the NBYTES bits to the parameter size.
    I2C1->CR2 = (size<<16 & I2C_CR2_NBYTES);
    //c.Write a ‘for’ loop that iterates ‘size’ number of times.
    for (int i =0; i < size; i++){
        //i.Initialize a variable timeout to 0.
        int timeout = 0;
        //ii.Wait for I2C_ISR_TXIS to be 1.
        while(!(I2C1->ISR & I2C_ISR_TXIS)){
            //1.While waiting for the bit to be set increment timeout.
            timeout++;
            //2.If timeout exceeds 1000000,
            if (timeout > 1000000){
            //3.Return FAIL
                return FAIL;
            }
        }
        //iii.Set TXDR to data[i]; where i is the ith iteration of the ‘for’ loop.
        I2C1->TXDR = data[i];
    }
    //d.Wait until TC flag is set or the NACK flag is set.
    while(!(I2C1->ISR & I2C_ISR_TC) && !(I2C1->ISR & I2C_ISR_NACKF));
    //e.If NACKF flag is set, return FAIL.
    if (I2C1->ISR & I2C_ISR_NACKF){
        return FAIL;
    }
    //f.Else return success.
    return SUCCESS;

    //---------End-----------
}

// See lab document for description
int I2C1_readdata(int8_t* data, uint32_t size) {
    // Student code goes here
    //a.Clear the NBYTES of CR2.
    I2C1->CR2 &= ~(I2C_CR2_NBYTES);
    //b.Set the NBYTES bits to the parameter size.
    I2C1->CR2 = (size<<16 & I2C_CR2_NBYTES);
    //c.Write a ‘for’ loop that iterates ‘size’ number of times.
    for (int i =0; i < size; i++){
        //i.Initialize a variable timeout to 0.
        int timeout = 0;
        //ii.Wait for I2C_ISR_RXNE to be 1.
        while(!(I2C1->ISR & I2C_ISR_RXNE)){
            //1.While waiting for the bit to be set increment timeout.
            timeout++;
            //2.If timeout exceeds 1000000,
            if (timeout > 1000000){
            //3.Return FAIL
                return FAIL;
            }
        }
        //iii.Read RXDR to data[i]; where i is the ith iteration of the ‘for’ loop.
        data[i] = I2C1->RXDR;
    }
    //d.Wait until TC flag is set or the NACK flag is set.
    while(!(I2C1->ISR & I2C_ISR_TC) && !(I2C1->ISR & I2C_ISR_NACKF));
    //e.If NACKF flag is set, return FAIL.
    if (I2C1->ISR & I2C_ISR_NACKF){
        return FAIL;
    }
    //f.Else return success.
    return SUCCESS;
    //---------End-----------
}

//===========================================================================
// Subroutines for step 4.
//===========================================================================
// See lab document for description
void write_EEPROM(uint16_t wr_addr, uint8_t data) {
    // Student code goes here
    //1) Initialize an array write_buf[3] where the first element is the higher byte of parameter ‘wr_addr’,
        //the second element is the lower byte of ‘wr_addr’,
        //and the third element is ‘data’.
    uint8_t write_buf[3] = {(uint8_t)((wr_addr & 0xff00) >> 8), (uint8_t)(wr_addr & 0x00ff), data};
    //2) Call I2C1_waitidle().
    I2C1_waitidle();
    //3) Call I2C1_start() with I2C address of the EEPROM (see datasheet), with WR as the direction.
    I2C1_start((uint8_t)0x50,WR);
    //4) Call I2C1_senddata(write_buf, 3).
    I2C1_senddata(write_buf, 3);
    //5) Call I2C1_stop().
    I2C1_stop();
    //6) Wait for 5ms
    micro_wait(5000);

    //---------End-----------
}

//===========================================================================
// Subroutines for step 5.
//===========================================================================
// See lab document for description
void set_gpio(int pin) {
    // Student code goes here
    //accepts an argument for pin number.
    //This method sets the ‘pin’ to logic high on the GPIO expander
    uint8_t write_buf[2] = {0x00,1<<pin};
    I2C1_waitidle();
    I2C1_start((uint8_t)0x20,WR);
    I2C1_senddata(write_buf, 2);
    I2C1_stop();
    //micro_wait(5000);

    write_buf[0] = 0x09;
    I2C1_waitidle();
    I2C1_start((uint8_t)0x20,WR);
    I2C1_senddata(write_buf, 2);
    I2C1_stop();
    //micro_wait(5000);
    //---------End-----------
}

// See lab document for description
void clear_gpio(int pin) {
    // Student code goes here
    uint8_t write_buf[2] = {0x00,~(1<<pin)};
    I2C1_waitidle();
    I2C1_start((uint8_t)0x20,WR);
    I2C1_senddata(write_buf, 2);
    I2C1_stop();
    //micro_wait(5000);

    write_buf[0] = 0x09;
    I2C1_waitidle();
    I2C1_start((uint8_t)0x20,WR);
    I2C1_senddata(write_buf, 2);
    I2C1_stop();
    //micro_wait(5000);
    //---------End-----------
}

//===========================================================================
// End of student code.
//===========================================================================

void prob2() {
    init_I2C1();
    check_config();
}

void prob3() {
    test_prob3();
}

int eeprom_addr = 0x00;

// Act on a command read by prob4().
static void action(char **words) {
    if (words[0] != 0) {
        if (strcasecmp(words[0],"mv") == 0) {
            eeprom_addr = strtol(words[1], NULL, 16);
            printf("Address 0x%x\n", eeprom_addr);
            return;
        }
        if (strcasecmp(words[0],"rd") == 0) {
        	printf("Read value is: 0x%x\n", read_EEPROM(eeprom_addr));
            return;
        }
        if (strcasecmp(words[0],"wr") == 0) {
			int data = strtol(words[1], NULL, 16);
			write_EEPROM(eeprom_addr, data);
			printf("Cursor at 0x%x\n", eeprom_addr);
			printf("Writing successful\n");
			return;
        }

        printf("Unrecognized command: %s\n", words[0]);
    }
}

//===========================================================================
// Interact with the hardware.
// This subroutine waits for a line of input, breaks it apart into an
// array of words, and passes that array of words to the action()
// subroutine.
// The "display1" and "display2" are special words that tell it to
// keep everything after the first space together into words[1].
//
void prob4(void) {
	init_I2C1();
    printf("\nSTM32 EEPROM testbench.\n");
    printf("Interactive EEPROM read write tool\n");
    printf("- mv 0x\"address\", to move the cursor to move the cursor to address(hex)\n");
    printf("- rd to read data at cursor address\n");
    printf("- wr 0x\"data\" to write data at cursor\n");
    for(;;) {
        char buf[60];
        printf("> ");
        fgets(buf, sizeof buf - 1, stdin);
        int sz = strlen(buf);
        if (sz > 0)
            buf[sz-1] = '\0';
        char *words[7] = { 0,0,0,0,0,0,0 };
        int i;
        char *cp = buf;
        for(i=0; i<6; i++) {
            // strtok tokenizes a string, splitting it up into words that
            // are divided by any characters in the second argument.
            words[i] = strtok(cp," \t");
            // Once strtok() is initialized with the buffer,
            // subsequent calls should be made with NULL.
            cp = 0;
            if (words[i] == 0)
                break;
            if (i==0 && strcasecmp(words[0], "mv") == 0) {
                words[1] = strtok(cp, ""); // words[1] is rest of string
                break;
            }
            if (i==0 && strcasecmp(words[0], "rd") == 0) {
                break;
            }
            if (i==0 && strcasecmp(words[0], "wr") == 0) {
                words[1] = strtok(cp, ""); // words[1] is rest of string
                break;
            }
        }
        action(words);
    }
}

void prob5() {
	init_I2C1();
	while(1) {
		set_gpio(0);
		micro_wait(1000000);
		clear_gpio(0);
		micro_wait(1000000);
	}
}

int main(void)
{
	serial_init();

	//Open the serial terminal to see messages for each part
    //test_wiring();
    //prob2();
    //prob3();
    prob4();
    //prob5();
	while(1)
	    ;
}
