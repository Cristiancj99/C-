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
		
		cout << "P or favor, diganos los numeros que desea";
		cin >> vector[i];
		util_vector++;
	}
}
/**
@brief modulo que sirve para comprobar si un número está en el vector.
@pre util_vector tendrá que ser mayor que 0.
@param const int VECTOR []. (L) vector en el que comprobaremos si está un número
@param util_vector variable con la que tendremos el estado de nuestro vector.
@param int NumeroBuscar. variable que tendrá asignada el número que queremos buscar.
@param int n. variable para asignar el valor de la posición donde se encuentra el número
@RETURN Nada. Es un PROCEDIMIENTO
@post si el numero se repite n tendrá que tener su valor, si no la salida correcta del programa 
*/
void  BusquedaSimple (const int VECTOR[], int util_vector, int NumeroBuscar, int n){

	bool encontrado=false;

	for (int i=0;( (i<util_vector) && (encontrado==false) );i++){ // bucle para comprobar si el numero está en el vector
		

		if (VECTOR[i] == NumeroBuscar){ // si el contenido de vector [i] es igual al numero que buscmos, asignamos la posición a una variable y finalizamos el bucle
		
			n=i;
			encontrado= true;
		}
	}

	if (encontrado == true){
		cout << SOLUCION <<  "El número "<< NumeroBuscar << " se encuentra en la posición "<< n << NORMAL << endl;
	}
	else{

	cout << DEBUG<< "El número que está buscando no se encuentra en el vector. " << NORMAL << endl;

	}
}
int main () {

	const int DIM_VECTOR=10;
	int vector[DIM_VECTOR];
	int util_vector=0;
	int n=0, NumeroBuscar=0;

	rellenarvector (n, vector, util_vector);
	cout << "Por favor, introduzca un numero para ver si está en el vector";
	cin >> NumeroBuscar;
	BusquedaSimple ( vector, util_vector, NumeroBuscar, n);

}