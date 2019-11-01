.cpu cortex-m0
.thumb
.syntax unified
.fpu softvfp

.global main
main:
		// put your code here.
        ldr r0, =size
        ldr r0, [r0]
        ldr r1, =source
        ldr r2, =result
        movs r3, #0 //index i
        movs r4, #0 //value helps
        movs r7, #0 //value

check:
		cmp r3, r0
		bge done
		movs r5,#0xf
		ands r4,r5
		movs r5,#4
		muls r5,r4
		adds r1,r5
		ldr r6,[r1] //n
		subs r1,r5

		movs r5,#1
		ands r5,r3
		cmp r5,#0
		beq if1

else1:
        subs r7,r6
        str r7,[r2]
        adds r2,#4
        adds r3,#1
        movs r4,r7
        b check

if1:
        adds r7,r6
        str r7,[r2]
        adds r2,#4
        adds r3,#1
        movs r4,r7
        b check

done:
		movs r1, #0
		movs r2, #0
		movs r3, #0
		movs r4, #0
		movs r5, #0
		movs r6, #0
		movs r7, #0
		b step2

step2:
		ldr r0, =str
        movs r1,#0 //x

check2:
        ldrb r2,[r0]
        cmp r2, #0
        beq done2
        movs r3,#1 //help
        ands r3,r2
        cmp r3, #1
        beq if2

else2:
        adds r0,#1
        adds r1,#1
        b check2

if2:
        movs r3,#0x20
        strb r3,[r0]
        adds r0,#1
        adds r1,#1
        ldrb r2,[r0]
        b check2
done2:
nop
nop
		wfi

.data
.align 4
size:
	.word 4
value:
	.word 0
result:
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
source:
	.word 2
	.word 3
	.word 5
	.word 7
	.word 11
	.word 13
	.word 17
	.word 19
	.word 23
	.word 29
	.word 31
	.word 37
	.word 41
	.word 43
	.word 47
	.word 53
	.word 59

str:
	.string "hello, 01234 world"
