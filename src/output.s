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
	mv x11, x10
	addi a0, x11, 0x30
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
	li x12, 1
	addi x13, x7, 1
	mv x7, x13
	j L000
L001:
	li x14, 1
L002:
	li x15, 3
	ble x15, x14, L003
	li x16, 3
	mul x17, x16, x14
	mv x18, x17
	addi a0, x18, 0x30
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
	addi x19, x14, 1
	mv x14, x19
	j L002
L003:
	li x20, 1
L004:
	mv x21, x20
	addi a0, x21, 0x30
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
	addi x22, x20, 1
	mv x20, x22
	li x23, 10
	ble x23, x20, L005
	j L004
L005:

	li a7, 93
	li a0, 0
	ecall
