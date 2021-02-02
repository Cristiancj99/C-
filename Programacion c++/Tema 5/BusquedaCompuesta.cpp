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
int  pedirm (int m){

	cout << "Por favor, introduzca el numero de numeros que vas a introducir" << endl;
	cin >> m;
	return m;
}
/**
@brief Módulo que sirve para rellenar un vector
@pre num deberá de ser menor que la dimensión del vector
@param int num variable donde asignaremos el numero de numeros que quiere introducir el usuario.
@param int vector [] vector en el cual guardaremos todos los numeros que introducirá el usuario
@param int util_vector. Variable que servirá para poder seguir el estado de vector.
@RETURN Nada. Es un procedimiento
@post  util_uno>0 y < DIM_VECTOR y será igual que m
*/
void rellenarvector ( int num, int vector [], int &util_vector){

	num=pedirm(num);
	for (int i=0; i<num; i++){
		
		cout << "Por favor, diganos los numeros que desea ";
		cin >> vector[i];
		util_vector++;
	}
}
/**
@brief modulo que sirve para buscar las posiciones de un ector que se repite un número en concreto
@pre util_original tendrá que ser > 0 y NumeroBuscar tendrá que ser una variable de tipo int .
@param const int ORIGINAL [] vector constante del que leeremos lo que vamos a copiar en el vector destino
@param int util_original. Nos dirá la siguiente posición libre y los espacios ocupados que tenemos del vector ORIGINAL.
@param const int destino [] vector en el cual guardaremos la posición de los números divisibles entre 3.
@param int util_destino. Nos dirá la siguiente posición libre y los espacios ocupados que tenemos del vector destino.
@param int NumeroBuscar. Número que buscaremos dentro del vector
@return Nada. Es un PROCEDIMIENTO
@post util_destino tendrá que ser menor o igual que util_original. 
*/
void BuscarPosiciones ( const int ORIGINAL [], int util_original, int destino [], int &util_destino, int NumeroBuscar){

	bool repetido =false; // booleano que utilizaremos para en caso de que no esté el numero poder dar salida.

	for (int i=0; i< util_original;i++) { // bucle para ver si se repite el número dentro del vector.

		if (ORIGINAL[i]  == NumeroBuscar){ // si el número se repite guardaremos la posición en un vector.
		
			destino [util_destino] = i;
			util_destino++;
			repetido=true;
		}
	}
	if (!repetido){
	cout << DEBUG << "El numero no está en el vector "<< NORMAL << endl;
	}
}
/**
@brief Módulo que sirve para dar las salidas del programa.
@pre util > 0.
@param const int VECTOR [] vector constante del que leeremos sus espacios
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Las salidas.
@post  El programa imprimirá el vector correctamente.
*/

void ImprimeVector ( const int VECTOR[], int util){

	for (int i=0; i<util ; i++){

		cout << SOLUCION << "La posición " << i << " del vector es " << VECTOR[i] << NORMAL <<endl;
	}
}
int main () {

	const int DIM_VECTOR=10;
	int vector[DIM_VECTOR];
	int util_vector=0;
	int n=0, NumeroBuscar=0;
	int VectorDestino [DIM_VECTOR];
	int util_vector_destino=0;

	rellenarvector (n, vector, util_vector);
	cout << "Por favor, introduzca un numero para ver si está en el vector";
	cin >> NumeroBuscar;
	BuscarPosiciones( vector, util_vector,VectorDestino, util_vector_destino, NumeroBuscar);
	ImprimeVector(VectorDestino,util_vector_destino);

}