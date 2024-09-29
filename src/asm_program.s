# Inicialización de registros
	li t0, 12       # Cargar valor 12 en t0
	mv t1, t0       # Mover t0 a t1
	li t2, 1        # Cargar valor 1 en t2
L000:
	li t3, 5        # Cargar valor 5 en t3

	# Comparación para ver si t2 <= t3
	ble t2, t3, L001  # Si t2 <= t3, salta a L001

	# Bucle principal
	li t5, 2        # Cargar valor 2 en t5
	mul t6, t5, t2  # Multiplicar t5 y t2, guardar en t6
	li t7, 1        # Cargar valor 1 en t7 (no usas la aquí)
	#addi t7, zero, 1

	addi t8, t2, 1  # Sumar 1 a t2, guardar en t8
	mv t2, t8       # Mover t8 a t2
	j L000          # Saltar de nuevo a L000

L001:
	li t9, 0        # Cargar valor 0 en t9

L002:
#slt t10, t9, t3   # Comparar si t9 < t3
#beqz t10, L003    # Si t9 >= t3, salta a L003

	blt t9, t3, L003
	mul t11, t5, t9   # Multiplicar t5 y t9, guardar en t11
	addi t9, t9, 1    # Incrementar t9 en 1
	j L002            # Saltar de nuevo a L002

L003:
	li t9, 0          # Reiniciar t9 a 0

L004:
	li t12, 3         # Cargar valor 3 en t12
	mul t13, t9, t12  # Multiplicar t9 y t12, guardar en t13
	addi t14, t9, 1   # Sumar 1 a t9
	mv t9, t14        # Mover t14 a t9

# Comparar si t9 <= t3
#slti t15, t9, t3  # Si t9 < t3, guardar 1 en t15, de lo contrario 0
#beqz t15, L005    # Si t15 es 0 (t9 >= t3), salta a L005

	ble t9, t3, L005
	j L004            # Saltar de nuevo a L004

L005:
	li t16, 10        # Cargar valor 10 en t16
#slt t17, t9, t16  # Comparar si t9 < t16
#beqz t17, L006    # Si t9 >= t16, salta a L006

	blt t9, t16, L006

L006:
# Fin del programa o más instrucciones aquí

