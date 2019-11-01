/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
extern autotest(void);

int rdir = 1, gdir = 1, bdir = 1;
//part 1
void tim1_init(void){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    //configure the GPIO, alternate functions, and channel outputs
    GPIOA->MODER &= ~(3<<16);
    GPIOA->MODER |= 2<<16;
    GPIOA->MODER &= ~(3<<18);
    GPIOA->MODER |= 2<<18;
    GPIOA->MODER &= ~(3<<20);
    GPIOA->MODER |= 2<<20;

    GPIOA->AFR[1] &= ~(15);
    GPIOA->AFR[1] |= 2;
    GPIOA->AFR[1] &= ~(15<<4);
    GPIOA->AFR[1] |= 2<<4;
    GPIOA->AFR[1] &= ~(15<<8);
    GPIOA->AFR[1] |= 2<<8;

    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    TIM1->CR1 &= ~TIM_CR1_DIR; //count up
    TIM1->CR1 &= ~TIM_CR1_CMS; //Edge-aligned mode

    //Configure channels 1, 2, and 3 to be in PWM mode 1
    TIM1->CCMR1 &= ~TIM_CCMR1_OC1M_0;
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
    TIM1->CCMR1 &= ~TIM_CCMR1_OC2M_0;
    TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
    TIM1->CCMR2 &= ~TIM_CCMR2_OC3M_0;
    TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;

    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;
    TIM1->CCMR1 |= TIM_CCMR1_OC2PE;
    TIM1->CCMR2 |= TIM_CCMR2_OC3PE;

    TIM1->BDTR |= TIM_BDTR_MOE;

    TIM1->CCMR1 &= ~TIM_CCMR1_CC1S;
    TIM1->CCMR1 &= ~TIM_CCMR1_CC2S;
    TIM1->CCMR2 &= ~TIM_CCMR2_CC3S;

    TIM1->CCER |= TIM_CCER_CC1E;
    TIM1->CCER |= TIM_CCER_CC2E;
    TIM1->CCER |= TIM_CCER_CC3E;

    TIM1->PSC = (48/2)-1; //Set the prescaler so that its output is exactly 2 MHz
    TIM1->ARR = (2000000/1000)-1; //the output on each pin is a 1000 Hz square wave

    TIM1->CCR1 = (1+TIM1->ARR)*0.06;
    TIM1->CCR2 = (1+TIM1->ARR)*0.3333;
    TIM1->CCR3 = (1+TIM1->ARR)*0.6667;

    TIM1->CR1 |= TIM_CR1_CEN; //enable timer counter
}
//part2
void tim3_init(void){
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->CR1 &= ~TIM_CR1_CMS; //Edge-aligned mode
    TIM3->CR1 &= ~TIM_CR1_DIR; //count up

    TIM3->DIER |= TIM_DIER_UIE; //enable the update interrupt

    TIM3->PSC = 480-1;
    TIM3->ARR = 200-1;

    TIM3->CR1 |= TIM_CR1_CEN; //enable timer counter

    NVIC->ISER[0] = 1<<TIM3_IRQn;
}

//part3
void TIM3_IRQHandler(void){
    TIM3->SR &= ~TIM_SR_UIF; //knowledge the TIM1 interrupt
    if (rdir == 1){
        TIM1->CCR3 = (TIM1->CCR3 * 517)>>9;
        if (TIM1->CCR3 >= (1+TIM1->ARR)*0.99){
            rdir = -1;
        }
    }
    else{
        TIM1->CCR3 = (TIM1->CCR3 * 506)>>9;
        if (TIM1->CCR3 <= (1+TIM1->ARR)*0.06){
            rdir = 1;
        }
    }

    if (gdir == 1){
        TIM1->CCR2 = (TIM1->CCR2 * 517)>>9;
        if (TIM1->CCR2 >= (1+TIM1->ARR)*0.99){
            gdir = -1;
        }
    }
    else{
        TIM1->CCR2 = (TIM1->CCR2 * 506)>>9;
        if (TIM1->CCR2 <= (1+TIM1->ARR)*0.06){
            gdir = 1;
        }
    }

    if (bdir == 1){
        TIM1->CCR1 = (TIM1->CCR1 * 517)>>9;
        if (TIM1->CCR1 >= (1+TIM1->ARR)*0.99){
            bdir = -1;
        }
    }
    else{
        TIM1->CCR1 = (TIM1->CCR1 * 506)>>9;
        if (TIM1->CCR1 <= (1+TIM1->ARR)*0.06){
            bdir = 1;
        }
    }
}

int main(void)
{
    autotest();
    tim1_init();
    tim3_init();
    while(1) asm("wfi");
    return 0;
}