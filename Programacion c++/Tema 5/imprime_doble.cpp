#include <iostream>

using namespace std;

/**
@brief Módulo que sirve para dar las salidas del programa.
@pre util > 0.
@param const int V [] vector constante del que leeremos sus espacios
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Nada. Es un procedimiento.
@post  El programa imprimirá el vector correctamente.
*/
void imprime_vector (const int V [], int util) {

	for (int i = 0; i<util; i++) {
		cout << v[i] << endl;
	}
}

/**
@brief Módulo que sirve para duplicar un vector e imprimirlo
@pre util > 0. y < DIM_VECTOR
@param int V [] vector del cual duplicaremos cada una de sus posiciones
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando duplicar.
@return nada. Es un procedimiento.
@post  el resultado de cada uno de los componentes del vector %2 deberá de ser == al vector original. La util se mantendrá igual.
*/
void imprime_doble (int v [], int util){

	for (int i=0;i<util;i++){ // bucle para recorrer el vector

		v[i] *=2; // cuentas para duplicar cada posición del vector
	}
	imprime_vector (v, util);
}

int main () {

	const int DIM_VECTOR=5;
	int vector [DIM_VECTOR]= {4, 2, 7};
	int util_vector=3;

	imprime_doble (vector, util_vector);
}