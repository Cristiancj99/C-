#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
/**
@brief Módulo que sirve para rellenar un vector
@pre tamanio deberá de ser menor que la dimensión del vector y mayor que 0
@param int uno [] vector en el cual guardaremos todos los numeros que introducirá el usuario
@param int util_vector. (por referencia) Variable que servirá para poder seguir el estado de vector.
@param int tamanio variable donde asignaremos el numero de numeros que quiere introducir el usuario.
@RETURN Nada. Es un procedimiento
@post  util_uno>0 y < DIM_VECTOR y será igual que tamanio
*/

void RellenaVectorUno (int uno[],int &util_uno, int tamanio) {



	cout << "Por favor, dime cuantos números vas a introducir" << endl;

	cin >> tamanio;



	for (int i=0;i<tamanio;i++){

		

		cout << "Introduzca la posición " << i+1 << " = "<< endl;

		cin >>uno [i];

		util_uno ++;

	}


}

/**
@brief Módulo que copia un vector en otro eliminando, si tiene los caracteres repetidos.
@pre util_uno >0 y < DIM_TOTAL y util_dos ==0
@param const int uno [] vector en el que buscaremos los números repetidos
@param int util_uno variable de tio int que nos dirá los espacios ocupados de uno para poder recorrerlo
@param int dos []vector en el que copiaremos uno eliminando los numeros repetidos
@param int util_dos (por referencia) variable de tipo int que usaremos para saber cual es el siguiente espacio libre del vector y poder escribir en el
@RETURN Nada. es un procedimiento
@post   utl_dos <= util_uno.
*/
void ComprobarYCopiarRepes (const int uno [], int util_uno, int dos [], int &util_dos){



	for (int i=0;i<util_uno;i++){
		
		if (uno[i]!= uno [i + 1]){ // si el numero es distinto a la siguiente posición lo copiará, si no no.

			dos[util_dos] = uno [i];
			util_dos ++;
		}
	}

}
/**
@brief Módulo que sirve para imprimir un vector.
@pre util > 0.
@param const int dos [] vector constante del que leeremos sus espacios
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Nada. es un procedimiento.
@post  El programa imprimirá el vector correctamente.
*/
void imprimevector (const int dos [], int util_dos){

	for (int i=0;i<util_dos;i++){

		cout << "La posición " << i + 1 << "es " << dos [i]<< endl;
}




}
int main () {



	const int DIM_VECTOR=10;

	int uno [DIM_VECTOR];

	int util_uno=0;

	int dos [DIM_VECTOR];

	int util_dos=0;

	int tamanio=0;



	RellenaVectorUno(uno, util_uno, tamanio);
	ComprobarYCopiarRepes (uno ,  util_uno,dos ,util_dos);
	SalidasEjercicio (dos, util_dos);
}
