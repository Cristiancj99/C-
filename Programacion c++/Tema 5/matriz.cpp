#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;

int main () {
	const int N_FILAS=20;
	const int N_COLUMNAS=20;
	int matriz [N_FILAS] [N_COLUMNAS]; // creamos una matriz de tipo int
	int util_columnas=0, util_filas=0;

	cout<< "Por favor, diganos cuantas columnas deseas ingresar: ";
	cin >> util_columnas;
	cout << "Ahora diganos el número de filas";
	cin >> util_filas;

	for (int f=0; f <util_filas;f++){ // bucle para rellenar la matriz
		for (int c=0; c < util_columnas; c++){ // bucle para rellenar las columnas, una vez llegue a la util se pasará a la siguiente fila
			
			cout << "Ingrese la parte del vector ( " << f << " , " << c << " )";
			cin >> matriz [f] [c];
		}
	}

	for (int f=0; f <util_filas;f++){ // bucle para imprimir una matriz
		
		
		for (int c=0; c < util_columnas; c++){ //  bucle para imprimir las columnas, una vez llegue a la util se pasará a la siguiente fila
	
			cout << SOLUCION << matriz [f] [c] << NORMAL;
		}
	cout << endl;
	}


}


