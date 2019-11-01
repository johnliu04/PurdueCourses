#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <stdio.h>
#include <stdlib.h>

#define RATE 100000
#define N 1000
extern const short int wavetable[N];
int offset1 = 0;
int offset2 = 0;
int step1 = 554.365 * N / RATE * (1<<16); //C#
int step2 = 698.456 * N / RATE * (1<<16); //F

// This function
// 1) enables clock to port A,
// 2) sets PA0, PA1, PA2 and PA4 to analog mode
void setup_gpio() {
    /* Student code goes here */
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER0;
    GPIOA->MODER |= GPIO_MODER_MODER1;
    GPIOA->MODER |= GPIO_MODER_MODER2;
    GPIOA->MODER |= GPIO_MODER_MODER4;
}

// This function should enable the clock to the
// on board DAC, enable trigger,
// setup software trigger and finally enable the DAC.
void setup_dac() {
    /* Student code goes here */
    RCC->APB1ENR |= RCC_APB1ENR_DACEN; //Enable clock to DAC
    DAC->CR &= ~DAC_CR_EN1; //Disable DAC channel 1
    DAC->CR &= ~DAC_CR_BOFF1; //Do not turn buffer off
    DAC->CR |= DAC_CR_TEN1; //Enable trigger
    DAC->CR |= DAC_CR_TSEL1; //all ones. Select software trigger
    DAC->CR |= DAC_CR_EN1; //enable DAC channel 1

}

// This function should,
// enable clock to timer6,
// setup pre scalar and arr so that the interrupt is triggered every
// 10us, enable the timer 6 interrupt, and start the timer.
void setup_timer6() {
    /* Student code goes here */
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; //system clock enable
    TIM6->ARR = 24-1;
    TIM6->PSC = 20-1;
    TIM6->DIER |= TIM_DIER_UIE; //enable the update interrupt
    TIM6->CR1 |= TIM_CR1_CEN; //enable the timer counter

    NVIC->ISER[0] = 1<<TIM6_DAC_IRQn;
}


// This function should enable the clock to ADC,
// turn on the clocks, wait for ADC to be ready.
void setup_adc() {
    /* Student code goes here */
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //enable clock to ADC unit
    RCC->CR2 |= RCC_CR2_HSI14ON; //turn on hi-spd internal 14Mhz clock
    while(!(RCC->CR2 & RCC_CR2_HSI14RDY)); //wait the clock to be ready
    ADC1->CR |= ADC_CR_ADEN; //enable ADC
    while(!(ADC1->ISR & ADC_ISR_ADRDY)); //wait for ADC to be ready
    while((ADC1->CR & ADC_CR_ADSTART)); //wait for ADCstart to be 0
}

// This function should return the value from the ADC
// conversion of the channel specified by the “channel” variable.
// Make sure to set the right bit in channel selection
// register and do not forget to start adc conversion.
int read_adc_channel(unsigned int channel) {
    /* Student code goes here */
    ADC1->CHSELR = 0;
    ADC1->CHSELR |= 1<<channel;
    while(!(ADC1->ISR & ADC_ISR_ADRDY));
    ADC1->CR |= ADC_CR_ADSTART;
    while(!(ADC1->ISR & ADC_ISR_EOC));
    return ADC1->DR;
}

void TIM6_DAC_IRQHandler() {
    /* Student code goes here */
    DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1; //trigger DAC
    TIM6->SR &= ~TIM_SR_UIF; //Acknowledge the interrupt
    offset1 += step1;
    if ((offset1>>16) >= N)
        offset1 -= N<<16;
    offset2 += step2;
    if ((offset2>>16) >= N)
            offset2 -= N<<16;
    int sample = wavetable[offset1>>16];
    sample += wavetable[offset2>>16];
    sample = sample/34+2048;
    //sample = sample/17+2048;
    if (sample > 4095) sample = 4095;
    else if (sample < 0) sample = 0;
    DAC->DHR12R1 = sample;
}


int main(void)
{
    /* Student code goes here */
    init_wavetable();
    setup_gpio();
    setup_dac();
    setup_timer6();

    setup_adc();

    for (;;){
        int a1 = read_adc_channel(0);
        step1 = (200 + 800/4095.0 * a1) * N / RATE * (1<<16);
        int a2 = read_adc_channel(1);
        step2 = (200 + 800/4095.0 * a2) * N / RATE * (1<<16);
    }

}
