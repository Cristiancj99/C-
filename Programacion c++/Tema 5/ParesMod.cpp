#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;


/**
@brief modulo para pedir el numero de numeros que introducirá el usuario
@pre el valor que introduzca el usuario tendrá que ser de tipo int.
@param int m. variable de tipo int donde asignaremos el valor introducido
@RETURN devolverá una variable int que llevará asignada el numero ntroducido por el usuario
@post  m tendrá que ser mayor a 0 y menor a la DIM
*/
void PedirCantidad (int &numero){

	cout << "Cuantos números vas a ingresar: ";
	cin >> numero;
}
/**
@brief Módulo que sirve para rellenar un vector
@pre num deberá de ser menor que la dimensión del vector
@param int num variable donde asignaremos el numero de numeros que quiere introducir el usuario.
@param int vector [] vector en el cual guardaremos todos los numeros que introducirá el usuario
@param int util_uno.(por referencia) Variable que servirá para poder seguir el estado de vector.
@RETURN Nada. Es un procedimiento
@post  util_uno>0 y < DIM_VECTOR y será igual que m
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
@brief Modulo que copia los numeros pares de un vector en otro y da salida a todos los componentes del vector
@pre util_uno > 0 y < DIM_VECT
@param int dos[] vector de tipo int donde copiaremos el otro vector
@param const int uno [] (L)vector que llevará los valores a copiar en dos
@param int util_dos (por referencia). variable que servirá para seguir el estado de dos[]
@param int util_uno nos dirá la cantidad de espacios que están ocupados en uno[]
@RETURNNada. Es un procedimiento
@post  util_dos <= util_uno
*/
void CopiaYSalida (int dos [], int uno [], int &util_dos, int util_uno){
	int k=0;

	for ( int i=0; i < util_uno ; i++){ // bucle para pegar y dar salida a los valores de uno en dos
		
		if (uno[i] % 2 ==0){
	
			dos[k]=uno[i];
			util_dos++;
			cout << "Numero par: " << dos[k] << endl;		
		
		}
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
