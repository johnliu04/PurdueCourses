#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

void test_slow_division(void);
void test_wiring(void);
void test_SysTick(void);
void test_EXTI1(void);
void test_EXTI2(void);
void test_EXTI3(void);
void test_EXTI4(void);
void test_EXTI5(void);

unsigned int slow_division(unsigned int numer, unsigned int denom);
void init_systick();
void toggleD15();

int tick_counter = 0;
int seconds = 0;
int button_presses = 0;

void forever_division() {
	while(1) {
		slow_division(40000000, 6);
		toggleD15(); // A function provided in autotest.o
	}
}

void test_SysTick() {
	init_systick();
	forever_division();
}

void reaction_timer() {
	turnOnBlueLED();
	init_rtsr();
	init_imr();
	init_iser();
        enable_pb0();  // uncomment for last step
	init_systick();
	while(1);
}

int main(void)
{
    //test_slow_division();
        //test_wiring();
        //test_SysTick();
	//test_EXTI1();
	//test_EXTI2();
	//test_EXTI3();
	//test_EXTI4();
	//test_EXTI5();
	reaction_timer();
        while(1);
}
