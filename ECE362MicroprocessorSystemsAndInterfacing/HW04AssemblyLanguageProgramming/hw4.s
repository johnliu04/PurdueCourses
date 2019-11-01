.cpu cortex-m0
.thumb
.syntax unified
.fpu softvfp

//============================================================================
// Q1: hello
//============================================================================
.global hello
hello:
	push {lr}
	ldr r0,=greeting
	bl printf
	pop {pc}

greeting:
	.string "Hello, World!\n"
	.align 2

//============================================================================
// Q2: add2
//============================================================================
.global add2
add2:
	push {r4-r7,lr}
	movs r2,r1
	movs r1,r0
	adds r3,r1,r2
	ldr r0,=add2_format
	bl printf
	pop {r4-r7,pc}

add2_format:
	.string "%d + %d = %d\n"
	.align 2

//============================================================================
// Q3: add3
//============================================================================
.global add3
add3:
	push {r4-r7,lr}
	movs r3,r2
	movs r2,r1
	movs r1,r0

	adds r4,r1,r2
	adds r4,r3
	str r4,[sp,#0]

	ldr r0,=add3_format
	bl printf
	pop {r4-r7,pc}

add3_format:
	.string "%d + %d + %d = %d\n"
	.align 2

//============================================================================
// Q4: rotate6
//============================================================================
.global rotate6
rotate6:
	push {r4-r7,lr}
	ldr r4,[sp,#20]
	ldr r5,[sp,#24]
	cmp r0,#0
	beq rotat6_return
	movs r6,r5
	movs r5,r4
	sub sp,#4
	str r5,[sp,#0]
	movs r4,r3
	sub sp,#4
	str r4,[sp,#0]
	movs r3,r2
	movs r2,r1
	movs r1,r0
	movs r0,r6
	bl rotate6
	add sp,#8
	pop {r4-r7,pc}

rotat6_return:
	subs r5,r4
	subs r5,r3
	subs r5,r2
	subs r5,r1
	subs r5,r0
	movs r0,r5
	pop {r4-r7,pc}

//============================================================================
// Q5: low_pattern
//============================================================================
.type compare, %function  // You knew you needed this line.  Of course you did!
compare:
        ldr  r0,[r0]
        ldr  r1,[r1]
        subs r0,r1
        bx lr

.global low_pattern
low_pattern:
	push {r4-r7,lr}
	ldr r1,=0
	movs r4,r0
	sub sp,#400
	sub sp,#400
	mov r0,sp //beginning of array

low_pattern_loop:
	cmp r1, #200
	bge low_pattern_sort
	adds r2,r1,#1
	ldr r3,=255
	muls r2,r3
	ldr r3,=0xff
	ands r2,r3
	lsls r3,r1,#2
	str r2,[r0,r3]
	adds r1,#1
	b low_pattern_loop

low_pattern_sort:
	movs r5,r0
	ldr r1,=200
	ldr r2,=4
	ldr r3,=compare
	bl qsort
	lsls r4,r4,#2
	ldr r0,[r5,r4]
	add sp,#400
	add sp,#400
	pop {r4-r7,pc}

//============================================================================
// Q6: get_name
//============================================================================
.global get_name
get_name:
	push {r4-r7,lr}
	sub sp, #308
	ldr r0,=enter_name
	bl printf

	mov r0,sp //beginning of array
	bl gets

	movs r1,r0
	ldr r0,=helloprint
	bl printf
	add sp, #308
	pop {r4-r7,pc}

enter_name:
	.string "Enter your name: "
	.align 2

helloprint:
	.string "Hello, %s\n"
	.align 2
//============================================================================
// Q7: random_sum
//============================================================================
.global random_sum
random_sum:
	push {r4-r7,lr}
	sub sp, #80
	mov r7,sp //beginning of array
	push {r1,r2,r3}
	bl random
	pop {r1,r2,r3}
	str r0,[r7,#0] //x[0]
	ldr r5,=1
	movs r1,r0

random_sum_loop1:
	cmp r5,#20
	bge random_sum_done1
	push {r1,r2,r3}
	bl random
	pop {r1,r2,r3}
	subs r1,r0
	lsls r3,r5,#2
	str r1,[r7,r3]
	adds r5,#1
	b random_sum_loop1

random_sum_done1:
	ldr r2,=0
	ldr r0,=0 //sum

random_sum_loop2:
	cmp r2,#20
	bge random_sum_done2
	lsls r1,r2,#2
	ldr r3,[r7,r1]
	adds r0,r3
	adds r2,#1
	b random_sum_loop2

random_sum_done2:
	add sp,#80
	pop {r4-r7,pc}

//============================================================================
// Q8: fibn
//============================================================================
.global fibn
fibn:
	push {r4-r7,lr}
	movs r7,r0
	sub sp,#480
	mov r0,sp
	ldr r1,=0
	str r1,[r0,#0]
	ldr r1,=1
	str r1,[r0,#4]
	ldr r2,=2 //x

fibn_loop:
	cmp r2,#120
	bge fibn_done
	subs r3,r2,#2
	lsls r3,r3,#2
	ldr r1,[r0,r3]
	subs r3,r2,#1
	lsls r3,r3,#2
	ldr r4,[r0,r3]
	adds r4,r1
	lsls r3,r2,#2
	str r4,[r0,r3]
	adds r2,#1
	b fibn_loop

fibn_done:
	lsls r7,r7,#2
	ldr r0,[r0,r7]
	add sp,#480
	pop {r4-r7,pc}

//============================================================================
// Q9: fun
//============================================================================
.global fun
fun:
	push {r4-r7,lr}
	sub sp,#400
	mov r7,sp
	ldr r2,=0
	str r2,[r7,#0]
	ldr r3,=1

fun_loop1:
	cmp r3,#100
	bge fun_done1
	adds r4,r3,#7
	ldr r5,=37
	muls r5,r4
	adds r2,r5
	lsls r4,r3,#2
	str r2,[r7,r4]
	adds r3,#1
	b fun_loop1
fun_done1:
	movs r2,r0
	ldr r0,=0
fun_loop2:
	cmp r2,r1
	bgt fun_done
	lsls r3,r2,#2
	ldr r4,[r7,r3]
	adds r0,r4
	adds r2,#1
	b fun_loop2
fun_done:
	add sp,#400
	pop {r4-r7,pc}

//============================================================================
// Q10: sick
//============================================================================
.global sick
sick:
	push {r4-r7,lr}
	ldr r4,[sp,#20] //step
	sub sp,#400
	mov r7,sp
	ldr r5,=0
	str r5,[r7,#0]
	ldr r6,=1

sick_loop1:
	cmp r6,#100
	bge sick_done1
	push {r2}
	adds r2,r6
	muls r2,r3
	adds r5,r2
	lsls r2,r6,#2
	str r5,[r7,r2]
	pop {r2}
	adds r6,#1
	b sick_loop1

sick_done1:
	movs r2,r0
	ldr r0,=0 //sum
sick_loop2:
	cmp r2,r1
	bgt sick_done
	lsls r3,r2,#2
	ldr r5,[r7,r3]
	adds r0,r5
	adds r2,r4
	b sick_loop2

sick_done:
	add sp,#400
	pop {r4-r7,pc}

