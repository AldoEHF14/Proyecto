#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Map para almacenar las variables TAC y sus registros en RISC-V
unordered_map<string, string> registerMap;
unordered_map<string, string> stringMap;

string previous_condition;
int regCounter = 5;  // t0 será el primer registro que usemos
int stringCounter = 0;
ofstream outputFile; // Archivo de salida para el ensamblador

// Función que asigna registros temporales a variables
string getRegister(string var) {
    if (registerMap.find(var) == registerMap.end()) {
        registerMap[var] = "x" + to_string(regCounter++);
    }
    return registerMap[var];
}


string getStringLabel(string str) {
	if (stringMap.find(str) == stringMap.end()) {
       		string label = "msg" + to_string(stringCounter++);
        	stringMap[str] = label;
    	}
    	return stringMap[str];
}


// Función que traduce una línea TAC a RISC-V
void translateTACtoRISCV(string tac) {
    stringstream ss(tac);
    string token;
    ss >> token;

    // Asignación de constante (ejemplo: mivariable = 12)
    if (tac.find('=') != string::npos && tac.find('+') == string::npos && tac.find('*') == string::npos && tac.find("<=") == string::npos && tac.find("<") == string::npos) {
        string var = token.substr(0, token.find('='));
        string value;
        ss >> value >> value;  // Obtenemos el valor después del '='
        if (isdigit(value[0])) {
            outputFile << "\tli " << getRegister(var) << ", " << value << endl;
        } else {
            outputFile << "\tmv " << getRegister(var) << ", " << getRegister(value) << endl;
        }
        return;
    }

    // Caso de etiquetas (ejemplo: L000:)
    if (token.back() == ':') {
        outputFile << token << endl;
        return;
    }

    // Condicionales (ejemplo: if_false t0 goto L001)
    if (token == "if_false") {
        string cond, junk, label;
        ss >> cond >> junk >> label;
        string new_instruction = previous_condition + label;
        outputFile << "\t" + new_instruction << endl;
        return;
    }

    if (tac.find("<=") != string::npos) {
        string var1 = token;
        string op, var2, label, value;
        ss >> op >> var2 >> label >> value;

        if (isdigit(value[0]) && registerMap.find(value) == registerMap.end()) {
            outputFile << "\tli " << getRegister(var1) << ", " << value << endl;
        }

        previous_condition = "ble " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        return;
    }

    if (tac.find("<") != string::npos) {
        string var1 = token;
        string op, var2, label, value;
        ss >> op >> var2 >> label >> value;

        if (isdigit(value[0]) && registerMap.find(value) == registerMap.end()) {
            outputFile << "\tli " << getRegister(var1) << ", " << value << endl;
        }

        previous_condition = "blt " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        return;
    }

    // Saltos (ejemplo: goto L001)
    if (token == "goto") {
        string label;
        ss >> label;
        outputFile << "\tj " << label << endl;
        return;
    }


// Impresión de cadenas o valores
    if (token == "print") {
        string var, var1, var2;
        ss >> var >> var1 >> var2;
	cout << var[0] << getRegister(var)  <<endl;
        //if (isdigit(var[0])) {  // Imprimir un número
            
	    outputFile << "\taddi a0, " << getRegister(var) << ", " << "48" << endl;
	    outputFile << "\tmv a1, a0" << endl;
	    outputFile << "\taddi sp, sp, -16 " << endl;
	    outputFile << "\tsb a1, 0(sp) " << endl;
	    outputFile << "\tmv a1, sp" << endl;
	   

	   outputFile << "\tli a2, 2" << endl;          // Longitud del valor a imprimir (1 carácter)
	   outputFile << "\tli a7, 64" << endl;          // Longitud del valor a imprimir (1 carácter)
	   outputFile << "\tli a0, 1" << endl;          // Longitud del valor a imprimir (1 carácter)

    outputFile << "\tecall" << endl;             // Llamada al sistema para escribir el salto de línea
    outputFile <<"\taddi sp, sp, 16" << endl;   // Restaurar el puntero de pila

    // Imprimir un salto de línea
    outputFile << "\tla a1, newline"<<endl;    // Cargar la dirección del salto de línea en a1
    outputFile << "\tli a2, 2" <<endl;          // Longitud del salto de línea (1 byte)
    outputFile << "\tli a7, 64" << endl;        // syscall 64: sys_write
    outputFile << "\tli a0, 1" << endl;          // Descriptor de archivo 1 (salida estándar)
    outputFile << "\tecall" << endl;             // Llamada al sistema para escribir el salto de línea
        return;
    }



    // Operaciones aritméticas y comparaciones
    string leftVar, eq, op1, op, op2;
    leftVar = token;
    ss >> eq >> op1 >> op >> op2;

    if (isdigit(op1[0]) && registerMap.find(op1) == registerMap.end()) {
        outputFile << "\tli " << getRegister(op1) << ", " << op1 << endl;
    }
    if (isdigit(op2[0]) && registerMap.find(op2) == registerMap.end()) {
        outputFile << "\tli " << getRegister(op2) << ", " << op2 << endl;
    }

    if (op == "*") {
        outputFile << "\tmul " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
    } else if (op == "+") {
        if (isdigit(op2[0])) {
            outputFile << "\taddi " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << op2 << endl;
        } else {
            outputFile << "\tadd " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
        }
    } else if (op == "print") {
            //outputFile << "\tecall " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
            outputFile << "\tecall " << endl;
    }
}

// Función que procesa el TAC leído desde el archivo
void processTAC(const vector<string>& tacLines) {


// Sección de datos para las cadenas
    //outputFile << ".section .data" << endl;
    for (const auto& pair : stringMap) {
        outputFile << pair.second << ":\n\t.string " << pair.first << endl;
    }
	
	
	
// Agregar cabecera de sección .text
    outputFile << ".data" << endl;
    outputFile << "\tnewline:" << endl;
    outputFile << "\t\t.asciz \"\\n\"" << endl;
    outputFile << "\t.text" << endl;
    outputFile << "\t.global _start" << endl;
    outputFile << "_start:" << endl;

    // Procesar cada línea de TAC
    for (const string& line : tacLines) {
        if (!line.empty()) {
            translateTACtoRISCV(line);
        }
    }

    // Finalizar el programa con la llamada a sys_exit
    outputFile << "\n\tli a7, 93" << endl;
    outputFile << "\tli a0, 0" << endl;
    outputFile << "\tecall" << endl;
}

// Función para leer el archivo TAC y almacenar las líneas en un vector
vector<string> readTACFromFile(const string& filename) {
    vector<string> tacLines;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            tacLines.push_back(line);
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }
    return tacLines;
}

int main() {
    // Nombre del archivo que contiene el código TAC
    string tacFilename = "tac_file.txt";
    // Nombre del archivo de salida ensamblador
    string asmFilename = "output.s";

    // Leer el archivo TAC
    vector<string> tacLines = readTACFromFile(tacFilename);

    // Abrir el archivo de salida para escribir el ensamblador
    outputFile.open(asmFilename);
    if (!outputFile.is_open()) {
        cerr << "Error al abrir el archivo de salida: " << asmFilename << endl;
        return 1;
    }

    // Procesar el TAC y generar el código RISC-V en el archivo
    processTAC(tacLines);

    // Cerrar el archivo de salida
    outputFile.close();

    return 0;
}

