.section .data
msg:
    .string "Hola, mundo\n"          # Mensaje a imprimir
result_msg:
    .string "El resultado es "        # Mensaje de resultado a imprimir
newline:
    .byte '\n'                       # Salto de línea

.section .text
.global _start

_start:
    # Inicialización de registros
    li x5, 12                        # Cargar valor 12 en x5
    mv x6, x5                        # Mover x5 a x6
    li x7, 1                         # Cargar valor 1 en x7

L000:
    li x8, 5                         # Cargar valor 5 en x8

    # Comparación para ver si x7 <= x8
    bgt x7, x8, L001                 # Si x7 <= x8, salta a L001

    # Bucle principal
    li x10, 2                        # Cargar valor 2 en x10
    mul x11, x10, x7                 # Multiplicar x10 y x7, guardar en x11

    # Incrementar x7
    addi x13, x7, 1                  # Sumar 1 a x7, guardar en x13
    mv x7, x13                       # Mover x13 a x7
    j L000                           # Saltar de nuevo a L000

L001:

    # Escribir el mensaje en la consola (sys_write)
    li a7, 64                        # Código de syscall para sys_write
    li a0, 1                         # Descriptor de archivo 1 (salida estándar)
    la a1, msg                       # Dirección del mensaje
    li a2, 12                        # Longitud del mensaje
    ecall                            # Invocar la llamada al sistema

    # Escribir "El resultado es " en la consola
    li a7, 64                        # Código de syscall para sys_write
    li a0, 1                         # Descriptor de archivo 1 (salida estándar)
    la a1, result_msg                # Dirección del mensaje de resultado
    li a2, 16                        # Longitud del mensaje de resultado
    ecall                            # Invocar la llamada al sistema

    # Escribir el número (resultado) en la consola (sys_write)
    mv x5, x7                        # Cargar el número calculado en x5
    addi x6, x5, 48                  # Convertir el número a su representación ASCII

    # Usar un buffer temporal en la pila
    addi sp, sp, -16                 # Reservar espacio en la pila
    sb x6, 0(sp)                     # Almacenar el carácter ASCII en la pila

    mv a1, sp                        # Mover la dirección de la pila a a1
    li a2, 1                         # Longitud del dígito (1 byte)

    # Escribir el dígito en la consola (sys_write)
    li a7, 64                        # Código de syscall para sys_write
    li a0, 1                         # Descriptor de archivo 1 (salida estándar)
    ecall                            # Invocar la llamada al sistema

    # Escribir el salto de línea en la consola (sys_write)
    li a7, 64                        # Código de syscall para sys_write
    li a0, 1                         # Descriptor de archivo 1 (salida estándar)
    la a1, newline                   # Dirección del salto de línea
    li a2, 1                         # Longitud del salto de línea (1 byte)
    ecall                            # Invocar la llamada al sistema

    # Terminar el programa (sys_exit)
    li a7, 93                        # Código de syscall para sys_exit
    li a0, 0                         # Código de salida 0
    ecall                            # Invocar la llamada al sistema
