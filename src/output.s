.section .text
.global _start
_start:
	li x5, 12
	mv x6, x5
	li x7, 1
L000:
	li x8, 5
	bgt x8, x7, L001
	li x9, 2
	mul x10, x9, x7
	li x11, 1
	addi x12, x7, 1
	mv x7, x12
	j L000
L001:
	li x13, 0
L002:
	li x14, 5
	bge x14, x13, L003
	mul x15, x9, x13
	j L002
L003:
	li x13, 0
L004:
	li x16, 3
	mul x17, x13, x16
	addi x18, x13, 1
	mv x13, x18
	li x19, 5
	bgt x19, x13, L005
	j L004
L005:
	li x20, 10
	bge x20, x13, L006
L006:

	li a7, 93
	li a0, 0
	ecall
