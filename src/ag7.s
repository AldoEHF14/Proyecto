    .data
newline:
    .asciz "\n"   # Salto de línea

    .text
    .global _start

_start:
    # Inicialización del índice
    li t0, 0        # t0 = índice, lo inicializamos en 0
    li t1, 100      # t1 = número de iteraciones (límite del bucle) (puedes ajustar este límite)

loop:
    # Guardar el valor original de t0
    mv t2, t0

    # Extraer y almacenar los dígitos en orden inverso (en la pila)
    li t3, 0        # t3 = contador de dígitos

print_digits:
    li t4, 10       # Divisor 10
    div t5, t2, t4  # t5 = t2 / 10 (dividimos el número entre 10)
    rem t6, t2, t4  # t6 = t2 % 10 (obtenemos el dígito menos significativo)
    
    addi t6, t6, 48 # Convertir el dígito en su valor ASCII ('0' = 48)
    
    addi sp, sp, -16  # Reservar espacio en la pila
    sb t6, 0(sp)      # Almacenar el dígito en la pila
    
    mv t2, t5        # Actualizar el número original con la división t2 = t2 / 10
    addi t3, t3, 1   # Incrementar el contador de dígitos
    
    bnez t2, print_digits # Si t2 != 0, seguir extrayendo dígitos

    # Ahora imprimimos los dígitos que están en la pila
print_loop:
    lb a0, 0(sp)    # Cargar el dígito desde la pila
    mv a1, a0       # Mover el valor de a0 a a1 (para imprimirlo)
    
    li a2, 1        # Longitud del valor a imprimir (1 carácter)
    li a7, 64       # syscall 64: sys_write
    li a0, 1        # Descriptor de archivo 1 (salida estándar)
    ecall           # Llamada al sistema para escribir el valor
    
    addi sp, sp, 16  # Restaurar el puntero de pila
    addi t3, t3, -1  # Reducir el contador de dígitos
    
    bnez t3, print_loop # Si todavía hay dígitos, imprimir el siguiente

    # Imprimir un salto de línea
    la a1, newline  # Cargar la dirección del salto de línea en a1
    li a2, 1        # Longitud del salto de línea (1 byte)
    li a7, 64       # syscall 64: sys_write
    li a0, 1        # Descriptor de archivo 1 (salida estándar)
    ecall           # Llamada al sistema para escribir el salto de línea

    # Incrementar el índice
    addi t0, t0, 1    # t0 = t0 + 1

    # Condición de fin de bucle
    bge t0, t1, end   # Si t0 >= t1, salir del bucle

    # Volver al inicio del bucle
    j loop

end:
    # Salir del programa
    li a7, 93         # syscall 93: exit
    li a0, 0          # Código de salida 0 (éxito)
    ecall             # Llamada al sistema para salir

