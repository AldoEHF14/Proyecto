
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Map para almacenar las variables TAC y sus registros en RISC-V
unordered_map<string, string> registerMap;
int regCounter = 0;  // t0 será el primer registro que usemos
string label_j;
string previous_condition; 
// Función que asigna registros temporales a variables
string getRegister(string var) {
    if (registerMap.find(var) == registerMap.end()) {
        registerMap[var] = "t" + to_string(regCounter++);
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
            cout << "\t\tli " << getRegister(var) << ", " << value << endl;
        } else {
            cout << "\t\tmv " << getRegister(var) << ", " << getRegister(value) << endl;
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
	//label_j(&label);
        ss >> cond >> junk >> label;
	label_j = label;
        //cout << label_j << endl;
	string new_instruction = previous_condition + label;
	cout << "\t\t"+new_instruction << endl;
        //cout << "beqz " << getRegister(cond) << ", " << label << endl;
        return;
    }

	

// Comparaciones y saltos (ejemplo: if t1 <= t2 goto L001)
    if (tac.find("<=") != string::npos) {
        string var1 = token;
        string op, var2, label;
        ss >> op >> var2 >> label;
        //cout << "\t\tble " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " <= " << getRegister(var2) << ", saltar a " << label << endl;
        previous_condition = "ble " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
	return;
    }
    if (tac.find(">=") != string::npos) {
        string var1 = token;
        string op, var2, label;
        ss >> op >> var2 >> label;
        //cout << "bge " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " >= " << getRegister(var2) << ", saltar a " << label << endl;
        previous_condition = "bge " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
        return;
    }
    if (tac.find('<') != string::npos) {
        string var1 = token;
        string op, var2, label;
        ss >> op >> var2 >> label;
        //cout << "blt " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " < " << getRegister(var2) << ", saltar a " << label << endl;
        previous_condition = "blt " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
        return;
    }
    if (tac.find('>') != string::npos) {
        string var1 = token;
        string op, var2, label;
        ss >> op >> var2 >> label;
        //cout << "bgt " << getRegister(var1) << ", " << getRegister(var2) << ", " << label << "       # Si " << getRegister(var1) << " > " << getRegister(var2) << ", saltar a " << label << endl;
        previous_condition = "bgt " + getRegister(var1) + ", " + getRegister(var2) + ", "; 
        return;
    }







    // Saltos (ejemplo: goto L001)
    if (token == "goto") {
        string label;
        ss >> label;
	cout << "\t\tj " << label << endl;
        return;
    }

    // Operaciones aritméticas y comparaciones
    string leftVar, eq, op1, op, op2;
    leftVar = token;
    ss >> eq >> op1 >> op >> op2;

    // Si uno de los operandos es un número, lo cargamos en un registro si no tiene ya un registro asignado
    if (isdigit(op1[0]) && registerMap.find(op1) == registerMap.end()) {
        cout << "\t\tli " << getRegister(op1) << ", " << op1 << endl;
    }
    if (isdigit(op2[0]) && registerMap.find(op2) == registerMap.end()) {
        cout << "\t\tli " << getRegister(op2) << ", " << op2 << endl;
    }

    // Traducción de operaciones según el operador
    if (op == "*") {
        cout << "\t\tmul " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
    } else if (op == "+") {
        // Aquí, si el operando es un inmediato, se usa `addi`
        if (isdigit(op2[0])) {
            cout << "\t\taddi " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << op2 << endl;
        } else {
            cout << "\t\tadd " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
        }
    } else if (op == "<=") {
	//cout << "sle " << getRegister(leftVar) << ", " << getRegister(op1) << ", " << getRegister(op2) << endl;
        string cond, junk, label;
        if (token == "if_false") {
        	//string cond, junk, label;
		//label_j(&label);
        	ss >> cond >> junk >> label;
        	cout << "beqz " << getRegister(cond) << ", " << label << endl;
        	//return;
    	}   
	cout << "ble " << getRegister(op1) << ", " << getRegister(op2) << ", " << label << endl;
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

