#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <stdint.h>
#include <stdio.h>

// These are function pointers.  They can be called like functions
// after you set them to point to other functions.
// e.g.  cmd = bitbang_cmd;
// They will be set by the stepX() subroutines to point to the new
// subroutines you write below.
void (*cmd)(char b) = 0;
void (*data)(char b) = 0;
void (*display1)(const char *) = 0;
void (*display2)(const char *) = 0;

int col = 0;
int8_t history[16] = {0};
int8_t lookup[16] = {1,4,7,0xe,2,5,8,0,3,6,9,0xf,0xa,0xb,0xc,0xd};
char char_lookup[16] = {'1','4','7','*','2','5','8','0','3','6','9','#','A','B','C','D'};
extern int count;

// Prototypes for subroutines in support.c
void generic_lcd_startup(void);
void countdown(void);
void step1(void);
void step2(void);
void step3(void);
void step4(void);
void step6(void);

// This array will be used with dma_display1() and dma_display2() to mix
// commands that set the cursor location at zero and 64 with characters.
//
uint16_t dispmem[34] = {
        0x080 + 0,
        0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
        0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
        0x080 + 64,
        0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
        0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
};

//=========================================================================
// Subroutines for step 2.
//=========================================================================
void spi_cmd(char b) {
    // Your code goes here.
    // wait for the TXE bit to be clear
    //indicating that the SPI channel 2 transmitter bit is empty.
    while((SPI2->SR & SPI_SR_TXE) == 0)
        ;// wait for the transmit buffer to be empty
    //deposit the data in the argument into the SPI channel 2 data register
    SPI2->DR = b;
}

void spi_data(char b) {
    // Your code goes here.
    // wait for the TXE bit to be clear
    //indicating that the SPI channel 2 transmitter bit is empty.
    while((SPI2->SR & SPI_SR_TXE) == 0)
        ;// wait for the transmit buffer to be empty
    //deposit the data in the argument into the SPI channel 2 data register
    //add in an extra 0x200 to the data written
    //so that it sets the register select bit as described in Section 5.4
    SPI2->DR = 0x200 + b;
}

void spi_init_lcd(void) {
    // Your code goes here.
    // configures the appropriate I/O pins so that they are routed to SPI channel 2.
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    //alternate function mode
    GPIOB->MODER &= ~(GPIO_MODER_MODER12);
    GPIOB->MODER &= ~(GPIO_MODER_MODER13);
    GPIOB->MODER &= ~(GPIO_MODER_MODER15);

    GPIOB->MODER |= (GPIO_MODER_MODER12_1);
    GPIOB->MODER |= (GPIO_MODER_MODER13_1);
    GPIOB->MODER |= (GPIO_MODER_MODER15_1);

    GPIOB->AFR[1] &= ~(GPIO_AFRH_AFRH4);
    GPIOB->AFR[1] &= ~(GPIO_AFRH_AFRH5);
    GPIOB->AFR[1] &= ~(GPIO_AFRH_AFRH7);

    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; //enable SPI2

    // initialize SPI channel 2 so that it is configured for bidirectional mode, with bidirectional output enabled
    SPI2->CR1 |= SPI_CR1_BIDIOE | SPI_CR1_BIDIMODE;
    //currently set as master, and the slowest possible baud rate.
    SPI2->CR1 |= SPI_CR1_MSTR;
    SPI2->CR1 |= SPI_CR1_BR;
    SPI2->CR1 &= ~SPI_CR1_BR_2;
    //SPI2->CR1 &= ~SPI_CR1_BR_0; //lowest frequency fPCLK/16

    // Configure the clock to be 0 when idle,
    SPI2->CR1 &= ~(SPI_CR1_CPOL);
    //and use the first clock transition as the data capture edge.
    SPI2->CR1 &= ~(SPI_CR1_CPHA);

    // configure it to use a 10-bit word size, 1001
    SPI2->CR2 |= SPI_CR2_DS_0 | SPI_CR2_DS_3;
    SPI2->CR2 &= ~(SPI_CR2_DS_1);
    SPI2->CR2 &= ~(SPI_CR2_DS_2);

    //slave select output enable, and automatic NSS pulse generation.
    SPI2->CR2 |= SPI_CR2_SSOE;
    SPI2->CR2 |= SPI_CR2_NSSP;

    // Enable the SPI2 channel by setting the SPE bit.
    SPI2->CR1 |= SPI_CR1_SPE;
    // invoke the initialization procedures for the LCD
    generic_lcd_startup();
}

//===========================================================================
// Subroutines for step 3.
//===========================================================================

// Display a string on line 1 using DMA.
void dma_display1(const char *s) {
    // Your code goes here.
    cmd(0x80 + 0);
    int x;
    for(x=0; x<16; x+=1)
        if (s[x] != '\0')
            dispmem[x+1] = s[x] + 0x200;
        else
            break;
    for(   ; x<16; x+=1)
        dispmem[x+1] = 0x220;

    //initialize the appropriate DMA channel
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR &= ~DMA_CCR_EN;
    DMA1_Channel5->CMAR = (uint32_t) dispmem;
    DMA1_Channel5->CPAR = (uint32_t) &(SPI2->DR);
    DMA1_Channel5->CNDTR = 17;

    //Do not turn on circular transfers, interrupts, or memory-to-memory flag
    DMA1_Channel5->CCR &= ~DMA_CCR_CIRC;
    DMA1_Channel5->CCR &= ~DMA_CCR_TEIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_HTIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_TCIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_MEM2MEM;
    //DMA1_Channel5->CCR &= ~0xffffffff; //turned off everything

    //set the direction of data transfer from memory to peripheral.
    DMA1_Channel5->CCR |= DMA_CCR_DIR;

    //The memory address should be incremented after each transfer,
    DMA1_Channel5->CCR |= DMA_CCR_MINC;
    DMA1_Channel5->CCR &= ~DMA_CCR_PINC;

    //16 bits
    DMA1_Channel5->CCR &= ~DMA_CCR_MSIZE;
    DMA1_Channel5->CCR &= ~DMA_CCR_PSIZE;
    DMA1_Channel5->CCR |= DMA_CCR_MSIZE_0;
    DMA1_Channel5->CCR |= DMA_CCR_PSIZE_0;

    DMA1_Channel5->CCR &= ~DMA_CCR_PL; //priority: 00 low
    SPI2->CR2 |= SPI_CR2_TXDMAEN;
    DMA1_Channel5->CCR |= DMA_CCR_EN; //engage
}

//===========================================================================
// Subroutines for Step 4.
//===========================================================================

void dma_spi_init_lcd(void) {
    // Your code goes here.
    spi_init_lcd();

    //initialize the appropriate DMA channel
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR &= ~DMA_CCR_EN;
    DMA1_Channel5->CMAR = (uint32_t) dispmem;
    DMA1_Channel5->CPAR = (uint32_t) &(SPI2->DR);
    DMA1_Channel5->CNDTR = 34;

    //Do not turn on interrupts, or memory-to-memory flag
    DMA1_Channel5->CCR &= ~DMA_CCR_TEIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_HTIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_TCIE;
    DMA1_Channel5->CCR &= ~DMA_CCR_MEM2MEM;
    //DMA1_Channel5->CCR &= ~0xffffffff; //turned off everything

    // configure the DMA operation to be circular
    DMA1_Channel5->CCR |= DMA_CCR_CIRC;
    //set the direction of data transfer from memory to peripheral.
    DMA1_Channel5->CCR |= DMA_CCR_DIR;

    //The memory address should be incremented after each transfer,
    DMA1_Channel5->CCR |= DMA_CCR_MINC;
    DMA1_Channel5->CCR &= ~DMA_CCR_PINC;

    //16 bits
    DMA1_Channel5->CCR &= ~DMA_CCR_MSIZE;
    DMA1_Channel5->CCR &= ~DMA_CCR_PSIZE;
    DMA1_Channel5->CCR |= DMA_CCR_MSIZE_0;
    DMA1_Channel5->CCR |= DMA_CCR_PSIZE_0;

    DMA1_Channel5->CCR &= ~DMA_CCR_PL; //priority: 00 low
    SPI2->CR2 |= SPI_CR2_TXDMAEN;
    DMA1_Channel5->CCR |= DMA_CCR_EN; //engage
}

// Display a string on line 1 by copying a string into the
// memory region circularly moved into the display by DMA.
void circdma_display1(const char *s) {
    // Your code goes here.
    cmd(0x80 + 0);
    int x;
    for(x=0; x<16; x+=1)
        if (s[x] != '\0')
            dispmem[x+1] = s[x] + 0x200;
        else
            break;
    for(   ; x<16; x+=1)
        dispmem[x+1] = 0x220;
}

//===========================================================================
// Display a string on line 2 by copying a string into the
// memory region circularly moved into the display by DMA.
void circdma_display2(const char *s) {
    // Your code goes here.
    cmd(0x80 + 0);
    int x;
    for(x=0; x<16; x+=1)
        if (s[x] != '\0')
            dispmem[x+18] = s[x] + 0x200;
        else
            break;
    for(   ; x<16; x+=1)
        dispmem[x+1] = 0x220;
}

//===========================================================================
// Subroutines for Step 6.
//===========================================================================
void init_keypad() {
    // Your code goes here.
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //enable the clock to port A

    //configure pins 0, 1, 2 and 3 as outputs
    GPIOA->MODER &= ~(3);
    GPIOA->MODER |= 1;

    GPIOA->MODER &= ~(3<<2);
    GPIOA->MODER |= 1<<2;

    GPIOA->MODER &= ~(3<<4);
    GPIOA->MODER |= 1<<4;

    GPIOA->MODER &= ~(3<<6);
    GPIOA->MODER |= 1<<6;

    // Configure pins 4, 5, 6 and 7 to be inputs with a pull-down resistor
    GPIOA->PUPDR &= ~(3<<8);
    GPIOA->PUPDR |= 2<<8;

    GPIOA->PUPDR &= ~(3<<10);
    GPIOA->PUPDR |= 2<<10;

    GPIOA->PUPDR &= ~(3<<12);
    GPIOA->PUPDR |= 2<<12;

    GPIOA->PUPDR &= ~(3<<14);
    GPIOA->PUPDR |= 2<<14;
}

void init_tim6(void) {
    // Your code goes here.
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

    //Set PSC and ARR values so that the timer update event occurs exactly once every 1ms.
    TIM6->PSC = 600-1;
    TIM6->ARR = 80-1;

    TIM6->CR1 |= TIM_CR1_CEN; //enable timer
    TIM6->DIER |= TIM_DIER_UIE;

    NVIC->ISER[0] = 1<<TIM6_DAC_IRQn;
}

void TIM6_DAC_IRQHandler() {
    // Your code goes here.
    TIM6->SR &= ~TIM_SR_UIF;

    int row = (GPIOA->IDR >> 4) & 0xf;
    //set a local variable “index” equal to col << 2
    int index = col<<2;
    //left shift “history[index]” by 1 and store it back
    history[index] = history[index]<<1;
    //AND “row” & 0x1 and OR it into “history[index]”
    history[index] |= row & 0x1;
    history[index+1] = history[index+1]<<1;
    history[index+1] |= (row>>1) & 0x1;
    history[index+2] = history[index+2]<<1;
    history[index+2] |= (row>>2) & 0x1;
    history[index+3] = history[index+3]<<1;
    history[index+3] |= (row>>3) & 0x1;

    if (++col > 3){
        col = 0;
    }
    GPIOA->ODR = (1<<col);
    countdown();
}

int main(void)
{
    //step1();
    //step2();
    //step3();
    //step4();
    step6();
}
