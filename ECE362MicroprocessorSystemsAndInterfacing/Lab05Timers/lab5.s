.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb

//=============================================================================
// ECE 362 Lab Experiment 5
// Timers
//
//=============================================================================

.equ  RCC,      0x40021000
.equ  APB1ENR,  0x1C
.equ  AHBENR,   0x14
.equ  TIM6EN,	0x10
.equ  GPIOCEN,  0x00080000
.equ  GPIOBEN,  0x00040000
.equ  GPIOAEN,  0x00020000

.equ  GPIOC,    0x48000800
.equ  GPIOB,    0x48000400
.equ  GPIOA,    0x48000000
.equ  MODER,    0x00
.equ  PUPDR,    0x0c
.equ  IDR,      0x10
.equ  ODR,      0x14
.equ  PC0,      0x01
.equ  PC1,      0x04
.equ  PC2,      0x10
.equ  PC3,      0x40
.equ  PIN8,     0x00000100

// NVIC control registers...
.equ NVIC,		0xe000e000
.equ ISER, 		0x100
.equ ICER, 		0x180
.equ ISPR, 		0x200
.equ ICPR, 		0x280

// TIM6 control registers
.equ  TIM6, 	0x40001000
.equ  CR1,		0x00
.equ  DIER,		0x0C
.equ  PSC,		0x28
.equ  ARR,		0x2C
.equ  TIM6_DAC_IRQn, 17
.equ  SR,		0x10

//=======================================================
// 6.1: Configure timer 6
//=======================================================
.global init_TIM6
init_TIM6:
	ldr r0,=RCC
	ldr r1,[r0,#APB1ENR]
	ldr r2,=TIM6EN
	orrs r1,r2
	str r1,[r0,#APB1ENR]

	ldr r0,=TIM6
	ldr r1,=480-1
	str r1,[r0,#PSC]
	ldr r1,=100-1
	str r1,[r0,#ARR]

	ldr r1,[r0,#DIER]
	ldr r2,=1
	orrs r1,r2
	str r1,[r0,#DIER]

	ldr r1,[r0,#CR1]
	orrs r1,r2
	str r1,[r0,#CR1]

	ldr r0,=NVIC
	ldr r1,=ISER
	ldr r2,=(1<<TIM6_DAC_IRQn)
	str r2,[r0,r1]
	bx lr // Student may remove this instruction.

//=======================================================
// 6.2: Confiure GPIO
//=======================================================
.global init_GPIO
init_GPIO:
	ldr r0,=RCC
	ldr r1,[r0,#AHBENR]
	ldr r2,=GPIOCEN
	orrs r1,r2
	ldr r2,=GPIOAEN
	orrs r1,r2
	str r1,[r0,#AHBENR]

	ldr r0,=GPIOC
	ldr r1,[r0,#MODER]
	ldr r2,=0x300FF
	bics r1,r2
	ldr r2,=0x10055
	orrs r1,r2
	str r1,[r0,#MODER]

	ldr r0,=GPIOA
	ldr r1,[r0,#MODER]
	ldr r2,=0xFF
	bics r1,r2
	ldr r2,=0x55
	orrs r1,r2
	str r1,[r0,#MODER]

	ldr r1,[r0,#PUPDR]
	ldr r2,=0xFF00
	bics r1,r2
	ldr r2,=0xAA00
	orrs r1,r2
	str r1,[r0,#PUPDR]
	bx lr // Student may remove this instruction.

//=======================================================
// 6.3 Blink blue LED using Timer 6 interrupt
// Write your interrupt service routine below.
//=======================================================
.type TIM6_DAC_IRQHandler, %function
.global TIM6_DAC_IRQHandler
TIM6_DAC_IRQHandler:
	push {r4-r7,lr}
	ldr r0,=TIM6
	ldr r1,[r0,#SR]
	ldr r2,=1
	bics r1,r2//UIF
	str r1,[r0,#SR]

	ldr r0,=tick
	ldr r1,[r0]
	adds r1,#1
	str r1,[r0]

	ldr r2,=1000
	cmp r1,r2
	bne TIM6_DAC_IRQHandlerelse

	//toggle (hint: XOR) bit 8 of GPIOC's ODR
	ldr r1,=GPIOC
	ldr r2,[r1,#ODR]
	ldr r3,=(1<<8)
	eors r2,r3
	str r2,[r1,#ODR]
	ldr r2,=0
	str r2,[r0]

TIM6_DAC_IRQHandlerelse:
	///*
	// Update the selected column
	ldr r0,=col
	ldr r1,[r0]
	adds r1,#1
	ldr r2,=3
	ands r1,r2
	str r1,[r0]

	ldr r0,=GPIOA
	ldr r3,=1
	lsls r3,r1
	str r3,[r0, #ODR]

	// index is the starting index of the four history variables
	// that represent the buttons in the selected column.
	lsls r1,#2
	movs r2,r1 //index
	ldr r0,=history

	// Left shift all of the history variables.
	ldrb r1,[r0,r2]
	lsls r1,#1
	strb r1,[r0,r2]
	adds r2,#1
	ldrb r1,[r0,r2]
	lsls r1,#1
	strb r1,[r0,r2]
	adds r2,#1
	ldrb r1,[r0,r2]
	lsls r1,#1
	strb r1,[r0,r2]
	adds r2,#1
	ldrb r1,[r0,r2]
	lsls r1,#1
	strb r1,[r0,r2]

	ldr r0,=GPIOA
	ldr r1,[r0,#IDR]
	lsrs r1,#4
	ldr r3,=0xf
	ands r1,r3 //row
	subs r2,#3 //index
	ldr r0,=history

	ldr r3,=0x1
	ldrb r4,[r0,r2]
	ands r3,r1
	orrs r4,r3
	strb r4,[r0,r2]
	adds r2,#1
	lsrs r1,#1
	ldr r3,=0x1
	ldrb r4,[r0,r2]
	ands r3,r1
	orrs r4,r3
	strb r4,[r0,r2]
	adds r2,#1
	lsrs r1,#1
	ldr r3,=0x1
	ldrb r4,[r0,r2]
	ands r3,r1
	orrs r4,r3
	strb r4,[r0,r2]
	adds r2,#1
	lsrs r1,#1
	ldr r3,=0x1
	ldrb r4,[r0,r2]
	ands r3,r1
	orrs r4,r3
	strb r4,[r0,r2]
	//*/
	pop {r4-r7,pc}
//=======================================================
// 6.5 Debounce keypad
//=======================================================
.global getKeyPressed
getKeyPressed:
	ldr r0,=history

getKeyPressedwhileloop:
	ldr r1,=0

getKeyPressedforloop:
	cmp r1,#16
	bge getKeyPressedwhileloop
	ldrb r2,[r0,r1]
	cmp r2,#1
	beq getKeyPressedreturn
	adds r1,#1
	b getKeyPressedforloop

getKeyPressedreturn:
	ldr r0,=tick
	ldr r2,=0
	str r2,[r0]
	movs r0,r1
	bx lr // Student may remove this instruction.

.global getKeyReleased
getKeyReleased:
	ldr r0,=history

getKeyReleasedwhileloop:
	ldr r1,=0

getKeyReleasedforloop:
	cmp r1,#16
	bge getKeyReleasedwhileloop
	ldrb r2,[r0,r1]
	ldr r3,=0xfe
	cmp r2,r3
	beq getKeyReleasedreturn
	adds r1,#1
	b getKeyReleasedforloop

getKeyReleasedreturn:
	ldr r0,=tick
	ldr r2,=0
	str r2,[r0]
	movs r0,r1
	bx lr // Student may remove this instruction.
