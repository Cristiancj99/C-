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
@param int m. por referencia. variable de tipo int donde asignaremos el valor introducido
@RETURN devolverá una variable int que llevará asignada el numero ntroducido por el usuario
@post  m tendrá que ser mayor a 0 y menor a la DIM
*/
int  pedirm (int &m){

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
void rellenarvector ( int num, int vector [], int &util_vector) {

	pedirm(num);
	for (int i=0; i<num; i++){
		
		cout << "P or favor, diganos los numeros que desea";
		cin >> vector[i];
		util_vector++;
	}
}
/**
@brief modulo que ordena un vector de menor a mayor por el metodo de la busqueda de insercion entrada: 5 4 2 salida: 2 4 5.
@pre util_vector tendrá que ser mayor que 0 
@param int vector [] será que vector que ordenaremos.
@param int util_vector variable de tipo int que utilizaremos para manejar el espacio ocupado del vector.
@RETURN Nada. es un procedimiento 
@post  El vector tendrá que estar ordenado de menor a mayor. y la util se deberá de mantener igual
*/

void BusquedaInsercion ( int vector [], int util_vector){

	int valor =0;
	int i =0;
	
	for (int izqda=1; izqda< util_vector; izqda++){

		valor= vector[izqda]; // tomo el valor de la parte que me toca insertar en la parte ordenada
		
		for (i=izqda;( (i > 0 )&& (valor < vector[i-1]) ); i--){ // en este for se busca en la posición donde se tiene que insetar y desplaza los demás elementos.

			vector [i]=vector [i-1];
		}
	vector [i]=valor;
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
/**
@brief módulo que sirve para buscar un valor en un vector con la busqueda binaria
@pre El vector deberá de estar ordenado y la util deberá de ser >0
@param const int VECTOR [] vector en el que realizaremos la busqueda de un valor
@param int util_vector variable de tipo int que nos dirá el estado del vector
@param bool encontrado. variable que sirve para ver si es encontrado el valor
@RETURN Devolverá  una posición de un vector o si no está el elemento un bool
@post  posición llevará la posicion del elemento buscado
*/
int BusquedaBinaria ( const int VECTOR[], int util_vector, int numero){
	int izq=0;
	int dcha=util_vector -1;
	int centro= (izq+dcha)/2;

	while ( (izq <= dcha) && ( VECTOR[centro] != numero) ){ // bucle para comprobar el vector

		if (numero < VECTOR[centro]){ // si numero es menor que v de centro, dca será menor que el centro

			dcha=centro-1;
		}
		else{ // si es mayor, izqda será mayor que centro
			izq=centro + 1;
		}
		centro = (izq + dcha)/2;
	} 
	if (izq > dcha){
		return 0;
	}
	else{

		return centro;
	}
}
int main () {
	const int DIM_VECTOR=10;
	int vector [DIM_VECTOR];
	int util_vector=0;
	int posicion=0;
	int num=0;

	rellenarvector (num, vector, util_vector);
	BusquedaInsercion ( vector, util_vector);
	ImprimeVector ( vector , util_vector);
	cout << "Por Fvor, introduzca el nuero a buscar: ";
	cin >> num;
	posicion=BusquedaBinaria ( vector,util_vector,num);

	if (posicion != 0){
		
		cout << "El número " << vector [posicion] << " está en la posición " << posicion << endl;
	}
	else{

		cout << DEBUG << "ERROOOOR!!! numero no encontrado" <<NORMAL << endl;
	}

}