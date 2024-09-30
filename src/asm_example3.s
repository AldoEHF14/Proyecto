    .data
newline:
    .asciz "\n"   # Salto de línea

    .text
    .global _start

_start:
    # Inicialización del índice
    li t0, 0        # t0 = índice, lo inicializamos en 0
    li t1, 10       # t1 = número de iteraciones (límite del bucle)

loop:
    # Convertir el valor de t0 a ASCII y almacenarlo en a0
    addi a0, t0, 48   # Convertir el valor de t0 a su carácter ASCII ('0' = 48 en ASCII)
    
    # Imprimir el valor de t0
    mv a1, a0        # Mover el valor ASCII a a1 (puntero al valor a imprimir)
    li a2, 1         # Longitud del valor a imprimir (1 carácter)
    li a7, 64        # syscall 64: sys_write
    li a0, 1         # Descriptor de archivo 1 (salida estándar)
    ecall            # Llamada al sistema para escribir el valor

    # Imprimir un salto de línea
    la a1, newline   # Cargar la dirección del salto de línea en a1
    li a2, 1         # Longitud del salto de línea (1 byte)
    li a7, 64        # syscall 64: sys_write
    li a0, 1         # Descriptor de archivo 1 (salida estándar)
    ecall            # Llamada al sistema para escribir el salto de línea

    # Incrementar el índice
    addi t0, t0, 1   # t0 = t0 + 1

    # Condición de fin de bucle
    bge t0, t1, end  # Si t0 >= t1, salir del bucle

    # Volver al inicio del bucle
    j loop

end:
    # Salir del programa
    li a7, 93        # syscall 93: exit
    li a0, 0         # Código de salida 0 (éxito)
    ecall            # Llamada al sistema para salir

