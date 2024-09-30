.data
	newline:
		.asciz "\n"
	.text
	.global _start
_start:
	li x5, 12
	mv x6, x5
	li x7, 1
L000:
	li x8, 5
	ble x8, x7, L001
	li x9, 2
	mul x10, x9, x7
	addi a0, x10, 48
	mv a1, a0
	addi sp, sp, -16 
	sb a1, 0(sp) 
	mv a1, sp
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
	addi sp, sp, 16
	la a1, newline
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
	li x11, 1
	addi x12, x7, 1
	mv x7, x12
	j L000
L001:
L002:
	li x13, 0
L003:
	li x14, 3
	mul x15, x13, x14
	addi a0, x15, 48
	mv a1, a0
	addi sp, sp, -16 
	sb a1, 0(sp) 
	mv a1, sp
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
	addi sp, sp, 16
	la a1, newline
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
	addi x16, x13, 1
	mv x13, x16
	li x17, 5
	ble x17, x13, L004
	j L003
L004:
	li x18, 10
	blt x18, x13, L005
	addi a0, x13, 48
	mv a1, a0
	addi sp, sp, -16 
	sb a1, 0(sp) 
	mv a1, sp
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
	addi sp, sp, 16
	la a1, newline
	li a2, 2
	li a7, 64
	li a0, 1
	ecall
L005:

	li a7, 93
	li a0, 0
	ecall
