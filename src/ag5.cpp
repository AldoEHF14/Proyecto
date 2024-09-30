
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
            cout << "\tli " << getRegister(var) << ", " << value << endl;
        } else {
            cout << "\tmv " << getRegister(var) << ", " << getRegister(value) << endl;
        }
        return;
    }

    // Caso de etiquetas (ejemplo: L000:)
    if (token.back() == ':') {
        cout << token << endl;
        return;
    }

    // Condicionales (ejemplo: if_false t0 goto L001)
    if (token == "if_false") {
        string cond, junk, label;
        ss >> cond >> junk >> label;
        //cout << "beqz " << getRegister(cond) << ", " << label << endl;

string new_instruction = previous_condition + label;
        cout << "\t"+new_instruction << endl;

        return;
    }


	
if (tac.find("<=") != string::npos) {
        string var1 = token;
        string op, var2, label, value;
        ss >> op >> var2 >> label >> value;

	
// Mostrar `li` si el operando es un inmediato
 	//cout << value << endl;
        if (isdigit(value[0]) && registerMap.find(value) == registerMap.end()) {
            cout << "\tli " << getRegister(var1) << ", " << value << endl;
	    //return;
        }

        previous_condition = "bgt " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        //cout << previous_condition << label << endl;  // Mostrar la condición completa


        //cout << "\t\tble " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " <= " << getRegister(var2) << ", saltar a " << label << endl;
        //previous_condition = "ble " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
       return; 
    }


if (tac.find("<") != string::npos) {
        string var1 = token;
        string op, var2, label, value;
        ss >> op >> var2 >> label >> value;

	
// Mostrar `li` si el operando es un inmediato
 	//cout << value << endl;
        if (isdigit(value[0]) && registerMap.find(value) == registerMap.end()) {
            cout << "\tli " << getRegister(var1) << ", " << value << endl;
	    //return;
        }

        previous_condition = "bge " + getRegister(var1) + ", " + getRegister(var2) + ", ";
        //cout << previous_condition << label << endl;  // Mostrar la condición completa


        //cout << "\tble " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " <= " << getRegister(var2) << ", saltar a " << label << endl;
        //previous_condition = "ble " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
       return; 
    }













    

    // Saltos (ejemplo: goto L001)
    if (token == "goto") {
        string label;
        ss >> label;
        cout << "\tj " << label << endl;
        return;
    }

    // Operaciones aritméticas y comparaciones
    string leftVar, eq, op1, op, op2;
    leftVar = token;
    ss >> eq >> op1 >> op >> op2;

    // Si uno de los operandos es un número, lo cargamos en un registro si no tiene ya un registro asignado
    if (isdigit(op1[0]) && registerMap.find(op1) == registerMap.end()) {
        cout << "\tli " << getRegister(op1) << ", " << op1 << endl;
    }
    if (isdigit(op2[0]) && registerMap.find(op2) == registerMap.end()) {
        cout << "\tli " << getRegister(op2) << ", " << op2 << endl;
    }

    // Traducción de operaciones según el operador
    if (op == "*") {
        cout << "\tmul " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
    } else if (op == "+") {
        // Aquí, si el operando es un inmediato, se usa `addi`
        if (isdigit(op2[0])) {
            cout << "\taddi " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << op2 << endl;
        } else {
            cout << "\tadd " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
        }
    } else if (op == "<=") {
        //cout << "sle " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
    	
    } else if (op == "<") {
        cout << "slt " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
    } else if (op == "print") {
        // Pseudo-instrucción para imprimir (debería ser reemplazada con syscall o equivalente)
        cout << "# print " << getRegister(op1) << endl;
    }
}

// Función que procesa el TAC leído desde el archivo
void processTAC(const vector<string>& tacLines) {
    for (const string& line : tacLines) {
        if (!line.empty()) {
            translateTACtoRISCV(line);
        }
    }
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
    string filename = "tac_file.txt";

    // Leer el archivo TAC
    vector<string> tacLines = readTACFromFile(filename);

    // Procesar el TAC y generar el código RISC-V
    processTAC(tacLines);

    return 0;
}

