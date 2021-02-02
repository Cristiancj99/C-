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
@brief modulo que ordena un vector de menor a mayor por el metodo de la busqueda de seleccion entrada: 5 4 2 salida: 2 4 5.
@pre util_vector tendrá que ser mayor que 0 
@param int vector [] será que vector que ordenaremos.
@param int util_vector variable de tipo int que utilizaremos para manejar el espacio ocupado del vector.
@RETURN Nada. es un procedimiento 
@post  El vector tendrá que estar ordenado de menor a mayor. y la util se deberá de mantener igual
*/

void BusquedaSeleccion ( int vector [], int util_vector){

	int menor_actual=0;
	int aux=0;
	
	for (int i=0; (i< util_vector-1);i++){ // la i nos indicará la primera posición del vector desordenado

		menor_actual=i;
		
		for (int j= i+1; j<util_vector; j++){

			if (vector [j] < vector [menor_actual]){

				menor_actual=j; // almacenará la posiión del número más chico de la parte desordenada
			}
		}
		aux = vector[i];
		vector [i] = vector [menor_actual]; // intercambio del elemento más pequeño del vector desordenado con la primera posición del vector desordenado 
		vector [menor_actual]= aux;
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
	int vector [DIM_VECTOR];
	int util_vector=0;
	int num=0;

	rellenarvector (num, vector, util_vector);
	BusquedaSeleccion ( vector, util_vector);
	ImprimeVector ( vector , util_vector);


}