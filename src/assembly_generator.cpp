#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  // Incluir este encabezado para usar isdigit()

#define MAX_REGS 7        // Número de registros temporales disponibles en RISC-V (t0 a t6)
#define MAX_LINE_LENGTH 100  // Longitud máxima de cada línea del archivo
#define MAX_VARS 100     // Máximo número de variables

int reg_count = 0;   // Contador de registros
char* regs[MAX_REGS] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6"};  // Nombres de los registros temporales
char* var_names[MAX_VARS]; // Arreglo para almacenar nombres de variables
char* var_regs[MAX_VARS]; // Arreglo para almacenar el registro asignado a cada variable
int var_count = 0; // Contador de variables

// Función para obtener el siguiente registro disponible
char* get_next_reg() {
    if (reg_count >= MAX_REGS) {
        printf("Error: No hay registros disponibles\n");
        return NULL;
    }
    return regs[reg_count++];
}

// Función para liberar un registro
void free_reg() {
    if (reg_count > 0) {
        reg_count--;
    } else {
        printf("Error: No hay registros para liberar\n");
    }
}

// Función para mapear una variable a un registro
char* map_var_to_reg(char* var) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_names[i], var) == 0) {
            return var_regs[i];
        }
    }
    if (var_count < MAX_VARS) {
        var_names[var_count] = strdup(var);
        var_regs[var_count] = get_next_reg();
        return var_regs[var_count++];
    }
    printf("Error: Se excedió el número máximo de variables.\n");
    return NULL;
}

// Función para traducir una instrucción de tres direcciones a ensamblador RISC-V
void translate_three_addr(char* line) {
    char var[20], op[5], arg1[20], arg2[20], label[20];
    // Inicializar las cadenas
    var[0] = op[0] = arg1[0] = arg2[0] = label[0] = '\0';
        // Verificar si la línea es un label
	//if (sscanf(line, "%[^:]:", label) == 1) {
	//	printf("%s:\n", label);  // Imprimir el label
    	//}
    // Verificar si es una asignación (var = expresión)
    if (sscanf(line, "%s = %s %s %s", var, arg1, op, arg2) == 4) {
        // Es una operación aritmética o lógica
        char* reg1 = map_var_to_reg(arg1);
        char* reg2 = map_var_to_reg(arg2);
        char* reg_result = map_var_to_reg(var);
        
        if (reg1 && reg2 && reg_result) {
            if (strcmp(op, "+") == 0) {
                printf("add %s, %s, %s\n", reg_result, reg1, reg2);  // Suma
            } else if (strcmp(op, "-") == 0) {
                printf("sub %s, %s, %s\n", reg_result, reg1, reg2);  // Resta
            } else if (strcmp(op, "*") == 0) {
                printf("mul %s, %s, %s\n", reg_result, reg1, reg2);  // Multiplicación
            } else if (strcmp(op, "<=") == 0) {
                printf("sle %s, %s, %s\n", reg_result, reg1, reg2);  // Menor o igual
            } else if (strcmp(op, "<") == 0) {
                printf("slt %s, %s, %s\n", reg_result, reg1, reg2);  // Menor que
            }
        }
        free_reg();  // Liberar registros después de la operación
        free_reg();
    }
    // Verificar si es una asignación simple (var = arg1)
    else if (sscanf(line, "%s = %s", var, arg1) == 2) {
        char* reg = get_next_reg();
        if (reg) {
            printf("li %s, %s\n", reg, arg1);  // Cargar inmediato: li t0, 12
            map_var_to_reg(var);
        }
        free_reg();  // Liberar el registro después de usarlo
    }
    // Verificar si es un salto condicional
    else if (sscanf(line, "if_false %s goto %s", arg1, label) == 2) {
        char* reg = map_var_to_reg(arg1);
        if (reg) {
            printf("beqz %s, %s\n", reg, label);  // Si es igual a 0: beqz t0, L001
        }
    }
    // Verificar si es un salto incondicional
    else if (sscanf(line, "goto %s", label) == 1) {
        printf("j %s\n", label);  // Salto: j L000
    }
    // Verificar si es una impresión
    else if (sscanf(line, "print %s", arg1) == 1) {
        char* reg = map_var_to_reg(arg1);
        if (reg) {
            printf("print %s\n", reg);  // Suposición: instrucción ficticia de print
        }
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    // Abrir el archivo de tres direcciones para leer
    file = fopen("tac_file.txt", "r");
    if (!file) {
        printf("Error: No se pudo abrir el archivo.\n");
        return 1;
    }
    // Leer cada línea del archivo y traducirla
    while (fgets(line, sizeof(line), file)) {
        // Eliminar el salto de línea al final
        line[strcspn(line, "\n")] = 0;
        // Traducir la instrucción a ensamblador
        translate_three_addr(line);
    }
    fclose(file);
    return 0;
}
