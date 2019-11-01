.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb

//===================================================================
// ECE 362 Lab Experiment 3
// General Purpose I/O
//===================================================================

.equ  RCC,      0x40021000
.equ  AHBENR,   0x14
.equ  GPIOCEN,  0x00080000
.equ  GPIOBEN,  0x00040000
.equ  GPIOAEN,  0x00020000
.equ  GPIOC,    0x48000800
.equ  GPIOB,    0x48000400
.equ  GPIOA,    0x48000000
.equ  MODER,    0x00
.equ  IDR,      0x10
.equ  ODR,      0x14
.equ  PC0,      0x01
.equ  PC1,      0x04
.equ  PC2,      0x10
.equ  PC3,      0x40
.equ  PIN8,     0x00000100


//===========================================================
// Enable Ports B and C in the RCC AHBENR
// No parameters.
// No expected return value.
.global enable_ports
enable_ports:
    push    {r0,r1,r2,lr}
    // Student code goes here
	ldr r0,=RCC
	ldr r1,[r0,#AHBENR]
	ldr r2,=0x000c0000
	orrs r1,r2
	str r1,[r0,#AHBENR]
    // End of student code
    pop     {r0,r1,r2,pc}

//===========================================================
// Set bits 0-3 of Port C to be outputs.
// No parameters.
// No expected return value.
.global port_c_output
port_c_output:
    push    {lr}
    // Student code goes here
	ldr r0, =GPIOC
	ldr r1, [r0,#MODER]
	ldr r2, =0x00000055
	orrs r1,r2
	ldr r2, =0x000000aa
	bics r1,r2
	str r1,[r0,#MODER]
    // End of student code
    pop     {pc}

//===========================================================
// Set the state of a single output pin to be high.
// Do not affect the other bits of the port.
// Parameter 1 is the GPIOx base address.
// Parameter 2 is the bit number of the pin.
// No expected return value.
.global setpin
setpin:
    push    {lr}
    // Student code goes here
	movs r2,#1
	lsls r2,r1
	ldr r3,[r0,#ODR]
	orrs r3,r2
	str r3,[r0,#ODR]
    // End of student code
    pop     {pc}

//===========================================================
// Set the state of a single output pin to be low.
// Do not affect the other bits of the port.
// Parameter 1 is the GPIOx base address.
// Parameter 2 is the bit number of the pin.
// No expected return value.
.global clrpin
clrpin:
    push    {lr}
    // Student code goes here
	movs r2,#1
	lsls r2,r1
	ldr r3,[r0,#ODR]
	bics r3,r2
	str r3,[r0,#ODR]
    // End of student code
    pop     {pc}

//===========================================================
// Get the state of the input data register of
// the specified GPIO.
// Parameter 1 is GPIOx base address.
// Parameter 2 is the bit number of the pin.
// The subroutine should return 0x1 if the pin is high
// or 0x0 if the pin is low.
.global getpin
getpin:
    push    {lr}
    // Student code goes here
	movs r2,#1
	ldr r0,[r0,#IDR]
	lsls r2,r1
	ands r0,r2
	lsrs r0,r1
    // End of student code
    pop     {pc}

//===========================================================
// Get the state of the input data register of
// the specified GPIO.
// Parameter 1 is GPIOx base address.
// Parameter 2 is the direction of the shift
//
// Perfroms the following logic
// 1) Read the current content of GPIOx-ODR
// 2) If R1 == 1
//      (a) Left shift the content by 1
//      (b) Check if value exceeds 8
//      (c) If so set it to 0x1
// 3) If R1 == 0
//      (a) Right shift the content by 1
//      (b) Check if value is 0
//      (c) If so set it to 0x8
// 4) Store the new value in ODR
// No return value
.global seq_led
seq_led:
    push    {lr}
    // Student code goes here
	ldr r2,[r0,#ODR]
	cmp r1,#1
	beq equal1

notequal0:
	lsrs r2,#1
	cmp r2,#0
	beq value8
	b final

equal1:
	lsls r2,#1
	cmp r2,#8
	bgt value1
	b final

value1:
	ldr r2,=0x1
	b final

value8:
	ldr r2,=0x8
	b final

final:
	str r2,[r0,#ODR]
    // End of student code
    pop     {pc}

.global main
main:
    // Uncomment the line below to test "enable_ports"
    //bl  test_enable_ports

    // Uncomment the line below to test "port_c_output"
    //bl  test_port_c_output

    // Uncomment the line below to test "setpin and clrpin"
    //bl  test_set_clrpin

    // Uncomment the line below to test "getpin"
    //bl  test_getpin

    // Uncomment the line below to test "getpin"
    //bl  test_wiring

    // Uncomment to run the LED sequencing program
    bl run_seq

inf_loop:
    b inf_loop
