#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;


/**
@brief modulo para ver el tamaño de un vector
@param int n pasado por referencia para guardar el numero
@RETURN Nada.
@post   n > 0
*/


void DimeTamanio (int &n){

	cout << "Por favor, digame cuantos numeros vas a ocupar: ";
	cin >> n;
}
/**
@brief Módulo que sirve para rellenar un vector
@pre util > DIM_VECTOR
@param int num nos indica la cantidad de numeros que intoduciremos en el vector
@param int vector es un vector que rellenaremos
@param int util_vector (por referencia) nos indicara como va nuestro vector en cada momento
@RETURN Nada. Es un procedimiento
@post  util_uno>0 y < DIM_VECTOR
*/
void rellenarvector ( int num, int vector [], int &util_vector){

	for (int i=0; i<num; i++){
		
		cout << "por favor, diganos los numeros que desea";
		cin >> vector[i];
		util_vector++;
	}
}

/**
@brief módulo para comprobar la moda de un vector.
@pre util_vector >O
@param comst int vector (L) vector que comprobaremos su moda
@param const int util. variable (L) que nos indicará el estado de nuestro vector
@RETURN devolverá un int actual que es la moda que hay en el vector actualmente
@post actual > 0
*/

int CalcularModa ( const int vector [], const int util){
	int maximo=0; // numero de repeticiones maximo
	int actual=0; // moda actual
	int repeticiones=0; // numero de veces que se repite un numero
	int numero=0;// numero actual que estamos comprobando


	for (int i =0; i<util; i++){ // bucle para comprobar cada uno de los componentes del vector
		numero = vector [i];
		repeticiones=0;
		for( int j=0;j<util;j++){ // bucle para comprobar un elemento con los demas de las cadenas
			
			if (numero == vector [j]){
				repeticiones ++;
				
			}
		}
		if (repeticiones > maximo){
			maximo=repeticiones;
			actual=numero;
		}
	}
	

	return actual;
}
 

int main () {
	const int DIM_VECTOR=20;
	int vector [DIM_VECTOR];
	int util_vector=0;
	int n=0;
	int moda=0;
//invocacion de las funciones
	DimeTamanio(n);
	rellenarvector( n, vector, util_vector);
	moda=CalcularModa(vector, util_vector);
	cout << SOLUCION << "La moda es: " << moda << NORMAL << endl;
}
	


