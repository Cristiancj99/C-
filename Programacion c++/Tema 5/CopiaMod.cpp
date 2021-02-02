#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;

/**
@brief modulo para pedir la cantidad de numeros que ingresará el usuario en el vector
@pre util=0
@param int numero (por referencia) variable donde asignaremos el numero de numeros que ingresará el usuario
@RETURNNada. ES un procedimiento
@post  numero >0 && numero < DIM_VECTOR
*/
void PedirCantidad (int &numero){

	cout << "Cuantos números vas a ingresar: ";
	cin >> numero;
}
/**
@brief módulo que pide las entradas del vector 1
@pre  util_uno=0
@param  int vector [] vector que rellenaremos con los datos del usuario
@param int numero. variable a la que asignaremos la cantidad de numeros que ingresará el usuario
@param util_uno (por referencia) variable que sirve para llevar el estado en tiempo real de nuestro vector
@RETURN no devuelve nada, es un procedimiento
@post util_uno =< DIM_VECTOR
*/
void Pedirdatosentrada (int vector[], int numero, int &util_uno){

	PedirCantidad(numero);

	for (int i =0; i < numero; i++){

		cout << "Ingrese el contenido del vector";
		cin >> vector[i];
		util_uno++;
	}
}
/**
@brief Modulo que copia un vector en otro y da salida a todos los componentes del vector
@pre util_uno > 0 y < DIM_VECT, util_dos será menor o igual que util_uno
@param int dos[] vector de tipo int donde copiaremos el otro vector
@param const int uno [] (L)vector que llevará los valores a copiar en dos
@param int util_dos (por referencia). variable que servirá para seguir el estado de dos[]
@param int util_uno nos dirá la cantidad de espacios que están ocupados en uno[]
@RETURNNada. Es un procedimiento
@post  util_dos = util_uno
*/
void CopiaYSalida (int dos [],const int uno [], int &util_dos, int util_uno){

	for ( int i=0; i < util_uno ; i++){ // bucle para pegar y dar salida a los valores de uno en dos
		
		dos[i]=uno[i];
		cout << dos[i] << endl;
		util_dos ++;
	}
}
int main () {

	const int TAM_VECTOR=25; // tamaño del vector
	int uno [TAM_VECTOR]; // vector numero uno
	int dos [TAM_VECTOR]; // vector numero 2
	int util_uno=0;
	int util_dos=0, numeros=0;

	Pedirdatosentrada  (uno, numeros, util_uno);
	CopiaYSalida (dos, uno, util_dos, util_uno);
}
