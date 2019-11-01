.cpu cortex-m0
.thumb
.syntax unified
.fpu softvfp

.equ RCC,       0x40021000
.equ GPIOA,     0x48000000
.equ GPIOC,     0x48000800
.equ AHBENR,    0x14
.equ APB2ENR,   0x18
.equ APB1ENR,   0x1c
.equ IOPAEN,    0x20000
.equ IOPCEN,    0x80000
.equ SYSCFGCOMPEN, 1
.equ TIM3EN,    2
.equ MODER,     0x00
.equ OSPEEDR,   0x08
.equ PUPDR,     0x0c
.equ IDR,       0x10
.equ ODR,       0x14
.equ BSRR,      0x18
.equ BRR,       0x28
.equ PC8,       0x100

// SYSCFG control registers
.equ SYSCFG,    0x40010000
.equ EXTICR2,   0x0c

// NVIC control registers
.equ NVIC,      0xe000e000
.equ ISER,      0x100

// External interrupt control registers
.equ EXTI,      0x40010400
.equ IMR,       0
.equ RTSR,      0x8
.equ PR,        0x14

.equ TIM3,      0x40000400
.equ TIMCR1,    0x00
.equ DIER,      0x0c
.equ TIMSR,     0x10
.equ PSC,       0x28
.equ ARR,       0x2c

// Iinterrupt number for EXTI4_15 is 7.
.equ EXTI4_15_IRQn,  7
// Interrupt number for Timer 3 is 16.
.equ TIM3_IRQn,  16

//=====================================================================
// Q1
//=====================================================================
.global euclidean
euclidean:
	push {r4-r7,lr}
	cmp r0,r1
	beq euclidean_return1
	cmp r0,r1
	bgt euclidean_return2
	subs r1,r0
	b euclidean

euclidean_return1:
	pop {r4-r7,pc}

euclidean_return2:
	subs r0,r1
	b euclidean

//=====================================================================
// Q2
//=====================================================================
.global enable_porta
enable_porta:
	push {r4-r7,lr}
	ldr r0,=RCC
	ldr r1,[r0,#AHBENR]
	ldr r2,=0x00020000
	orrs r1,r2
	str r1,[r0,#AHBENR]
	pop {r4-r7,pc}

//=====================================================================
// Q3
//=====================================================================
.global enable_portc
enable_portc:
	push {r4-r7,lr}
	ldr r0,=RCC
	ldr r1,[r0,#AHBENR]
	ldr r2,=0x00080000
	orrs r1,r2
	str r1,[r0,#AHBENR]
	pop {r4-r7,pc}

//=====================================================================
// Q4
//=====================================================================
.global setup_pa4
setup_pa4:
	push {r4-r7,lr}
	ldr r0,=GPIOA
	ldr r1,[r0,#MODER]
	ldr r2,=0x00000300
	bics r1,r2
	str r1,[r0,#MODER]

	ldr r0,=GPIOA
	ldr r2,[r0,#PUPDR]
	ldr r1,=0x00000300
	bics r2,r1
	ldr r1,=0x00000100
	orrs r2,r1
	str r2,[r0,#PUPDR]
	pop {r4-r7,pc}

//=====================================================================
// Q5
//=====================================================================
.global setup_pa5
setup_pa5:
	push {r4-r7,lr}
	ldr r0,=GPIOA
	ldr r1,[r0,#MODER]
	ldr r2,=0x00000C00
	bics r1,r2
	str r1,[r0,#MODER]

	ldr r0,=GPIOA
	ldr r2,[r0,#PUPDR]
	ldr r1,=0x00000C00
	bics r2,r1
	ldr r1,=0x00000800
	orrs r2,r1
	str r2,[r0,#PUPDR]
	pop {r4-r7,pc}

//=====================================================================
// Q6
//=====================================================================
.global setup_pc8
setup_pc8:
	push {r4-r7,lr}
	ldr r0,=GPIOC
	ldr r1,[r0,#MODER]
	ldr r2,=0x00030000
	bics r1,r2
	ldr r2,=0x00010000
	orrs r1,r2
	str r1,[r0,#MODER]

	ldr r0,=GPIOC
	ldr r2,[r0,#OSPEEDR]
	ldr r1,=0x00030000
	orrs r2,r1
	str r2,[r0,#OSPEEDR]
	pop {r4-r7,pc}

//=====================================================================
// Q7
//=====================================================================
.global setup_pc9
setup_pc9:
	push {r4-r7,lr}
	ldr r0,=GPIOC
	ldr r1,[r0,#MODER]
	ldr r2,=0x000C0000
	bics r1,r2
	ldr r2,=0x00040000
	orrs r1,r2
	str r1,[r0,#MODER]

	ldr r0,=GPIOC
	ldr r2,[r0,#OSPEEDR]
	ldr r1,=0x000C0000
	bics r2,r1
	ldr r1,=0x00040000
	orrs r2,r1
	str r2,[r0,#OSPEEDR]
	pop {r4-r7,pc}

//=====================================================================
// Q8
//=====================================================================
.global action8
action8:
	push {r4-r7,lr}
	ldr r0,=GPIOA
	ldr r1,[r0,#IDR]
	lsrs r1,#4
	ldr r2,=1 //PA4
	ands r2,r1
	lsrs r1,#1
	ldr r3,=1 //PA5
	ands r3,r1
	cmp r2,r3
	bgt action8_0
	ldr r0,=GPIOC
	ldr r1,[r0,#ODR]
	ldr r2,=0x00000100
	orrs r1,r2
	str r1,[r0,#ODR]
	pop {r4-r7,pc}

action8_0:
	ldr r0,=GPIOC
	ldr r1,[r0,#ODR]
	ldr r2,=0x00000100
	bics r1,r2
	str r1,[r0,#ODR]
	pop {r4-r7,pc}

//=====================================================================
// Q9
//=====================================================================
.global action9
action9:
	push {r4-r7,lr}
	ldr r0,=GPIOA
	ldr r1,[r0,#IDR]
	lsrs r1,#4
	ldr r2,=1 //PA4
	ands r2,r1
	lsrs r1,#1
	ldr r3,=1 //PA5
	ands r3,r1
	cmp r3,r2
	bgt action9_0
	ldr r0,=GPIOC
	ldr r1,[r0,#ODR]
	ldr r2,=0x00000200
	orrs r1,r2
	str r1,[r0,#ODR]
	pop {r4-r7,pc}

action9_0:
	ldr r0,=GPIOC
	ldr r1,[r0,#ODR]
	ldr r2,=0x00000200
	bics r1,r2
	str r1,[r0,#ODR]
	pop {r4-r7,pc}

//=====================================================================
// Q10
//=====================================================================
.type EXTI4_15_IRQHandler, %function
.global EXTI4_15_IRQHandler
EXTI4_15_IRQHandler:
	push {r4-r7,lr}
	ldr r0,=EXTI
	ldr r1,[r0,#PR]
	ldr r2,=0x00000010
	orrs r1,r2
	str r1,[r0,#PR]

	ldr r0,=counter
	ldr r1,[r0]
	adds r1,#1
	str r1,[r0]
	pop {r4-r7,pc}

//=====================================================================
// Q11
//=====================================================================
.global enable_exti4
enable_exti4:
	//enable the 48 MHz system clock to the SYSCFG subsystem.
	push {r4-r7,lr}
	ldr r0,=RCC
	ldr r1,[r0,#APB2ENR]
	ldr r2,=SYSCFGCOMPEN
	orrs r1,r2
	str r1,[r0,#APB2ENR] //correct so far
	//set up the SYSCFG external interrupt configuration register 2 (see the FRM, page 177) to use pin PA4 for the interrupt source
	ldr r0,=SYSCFG
	ldr r1,[r0,#EXTICR2]
	ldr r2,=0xffff
	bics r1,r2
	ldr r2,=0x00004000
	orrs r1,r2
	str r1,[r0,#EXTICR2]
	//configure the EXTI_RTSR (see the FRM, page 224) to trigger on the rising edge of PA4
	ldr r0,=EXTI
	ldr r1,[r0,#RTSR]
	ldr r2,=0x00000010
	orrs r1,r2
	str r1,[r0,#RTSR]
	//set the EXTI_IMR to not ignore pin number 4
	ldr r0,=EXTI
	ldr r1,[r0,#IMR]
	ldr r2,=0x00000010
	orrs r1,r2
	str r1,[r0,#IMR]
	//configure the NVIC to enable the EXTI4_15_IRQHandler
	ldr r0,=NVIC
	ldr r1,=ISER
	ldr r2,=(1<<EXTI4_15_IRQn)
	str r2,[r0,r1]

	pop {r4-r7,pc}

//=====================================================================
// Q12
//=====================================================================
.type TIM3_IRQHandler, %function
.global TIM3_IRQHandler
TIM3_IRQHandler:
	push {r4-r7,lr}
	ldr r0,=GPIOC
	ldr r1,[r0,#ODR]
	ldr r2,=0x00000200
	eors r1,r2
	str r1,[r0,#ODR]

	ldr r0,=TIM3
	ldr r1,[r0,#TIMSR]
	ldr r2,=0x00000001
	bics r1,r2
	str r1,[r0,#TIMSR]
	pop {r4-r7,pc}

//=====================================================================
// Q13
//=====================================================================
.global enable_tim3
enable_tim3:
	push {r4-r7,lr}
	//Enables the 48 MHz system clock to the timer 3 subsystem.
	ldr r0,=RCC
	ldr r1,[r0,#APB1ENR]
	ldr r2,=TIM3EN
	orrs r1,r2
	str r1,[r0,#APB1ENR]
	//Configures the Auto-Reload Register and Prescaler of Timer 3 so that an update event occurs exactly twice per second.
	ldr r0,=TIM3
	ldr r1,=24000-1
	str r1,[r0,#ARR]
	ldr r1,=1000-1
	str r1,[r0,#PSC]
	//Set the DIER of Timer 3 so that an interrupt occurs on an update event.
	ldr r1,[r0,#DIER]
	ldr r2,=1
	orrs r1,r2
	str r1,[r0,#DIER]
	//Write the appropriate bit to the NVIC ISER so that the interrupt for the Timer 3 update event is enabled.
	ldr r0,=NVIC
	ldr r1,=ISER
	ldr r2,[r0,r1]
	ldr r3,=(1<<TIM3_IRQn)
	orrs r2,r3
	str r2,[r0,r1]
	//Enable the counter for Timer 3.
	ldr r0,=TIM3
	ldr r1,[r0,#TIMCR1]
	ldr r2,=0x00000001
	orrs r1,r2
	str r1,[r0,#TIMCR1]
	pop {r4-r7,pc}