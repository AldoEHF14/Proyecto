#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Map para almacenar las variables TAC y sus registros en RISC-V
unordered_map<string, string> registerMap;
string previous_condition;
int regCounter = 5;  // t0 será el primer registro que usemos
ofstream outputFile; // Archivo de salida para el ensamblador

// Función que asigna registros temporales a variables
string getRegister(string var) {
    if (registerMap.find(var) == registerMap.end()) {
        registerMap[var] = "x" + to_string(regCounter++);
    }
    return registerMap[var];
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

        previous_condition = "bgt " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        return;
    }

    if (tac.find("<") != string::npos) {
        string var1 = token;
        string op, var2, label, value;
        ss >> op >> var2 >> label >> value;

        if (isdigit(value[0]) && registerMap.find(value) == registerMap.end()) {
            outputFile << "\tli " << getRegister(var1) << ", " << value << endl;
        }

        previous_condition = "bge " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        return;
    }

    // Saltos (ejemplo: goto L001)
    if (token == "goto") {
        string label;
        ss >> label;
        outputFile << "\tj " << label << endl;
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
    }
}

// Función que procesa el TAC leído desde el archivo
void processTAC(const vector<string>& tacLines) {
    // Agregar cabecera de sección .text
    outputFile << ".section .text" << endl;
    outputFile << ".global _start" << endl;
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

