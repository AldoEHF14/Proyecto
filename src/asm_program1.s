.section .data
msg:
    .string "Hola, mundo\n"

.section .text

   .global _start      # Definir la etiqueta de inicio global
_start:

	# Inicialización de registros
        li x5, 12       # Cargar valor 12 en x5
        mv x6, x5       # Mover x5 a x6
        li x7, 1        # Cargar valor 1 en x7
L000:
        li x8, 5        # Cargar valor 5 en x8

        # Comparación para ver si x7 <= x8
        ble x7, x8, L001  # Si x7 <= x8, salta a L001
        # Bucle principal
        li x10, 2        # Cargar valor 2 en x10
        mul x11, x10, x7  # Multiplicar x10 y x7, guardar en x11
        addi x12, zero, 1  # Cargar valor 1 en x12

        addi x13, x7, 1  # Sumar 1 a x7, guardar en x13
        mv x7, x13       # Mover x13 a x7
        j L000          # Saltar de nuevo a L000

L001:
        li x9, 0        # Cargar valor 0 en x9

L002:
        blt x9, x8, L003
        mul x14, x10, x9   # Multiplicar x10 y x9, guardar en x14
        addi x9, x9, 1    # Incrementar x9 en 1
        j L002            # Saltar de nuevo a L002

L003:
        li x9, 0          # Reiniciar x9 a 0

L004:
        li x15, 3         # Cargar valor 3 en x15
        mul x16, x9, x15  # Multiplicar x9 y x15, guardar en x16
        addi x17, x9, 1   # Sumar 1 a x9
        mv x9, x17        # Mover x17 a x9

        ble x9, x8, L005
        j L004            # Saltar de nuevo a L004

L005:
        li x18, 10        # Cargar valor 10 en x18

        blt x9, x18, L006

L006:
	# Fin del programa
	

    	# Escribir el mensaje en la consola (sys_write)
    	li a7, 64          # Código de llamada al sistema para sys_write
    	li a0, 1           # Descriptor de archivo 1 (salida estándar)
    	la a1, msg         # Dirección del mensaje
    	li a2, 12          # Longitud del mensaje
    	ecall              # Invocar la llamada al sistema

    # Terminar el programa (sys_exit)
    	li a7, 93          # Código de llamada al sistema para sys_exit
    	li a0, 0           # Código de salida 0
    	ecall              # Invocar la llamada al sistema







 # Finalizar el programa con una llamada al sistema para salir
	#li a7, 93           # Código de salida en RISC-V (syscall exit)
    	#ecall               # Llamada al sistema para terminar el programa

