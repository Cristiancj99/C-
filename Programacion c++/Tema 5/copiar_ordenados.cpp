#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;





/**
@brief modulo para pedir cuantos espacios del vector ocuparemos
@pre 
@param int n por referencia. 
@RETURN Nada. es un procedimiento
@post  n mayor que 0
*/

void PedirN(int &n){

	cout << "Por favor, introduzca cuantos números va a ocupar en el vector.";
	cin >>n;
}



/**
@brief Módulo que sirve para rellenar un vector
@pre util > DIM_VECTOR
@param 
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
@brief Módulo para pedir las entradas
@pre 
@param int vector1 vector para guardar los primeros numeros que introduzca el usuario
@param int util1 variable que utilizaremos para seruir el estado de vector1
@param int vector2 vector para guardar los segundos numeros que introduzca el usuario
@param int util2 variable que utilizaremos para seruir el estado de vector2
@param int n variable que tilizaremos para ver la cantidad de numeros que nos introducirá el usuario
@RETURN Nada. es un procedimiento
@post  las utiles serán mayor que 0
*/

void pedirEntradas( int vector1 [], int &util_vector1,int vector2 [], int &util_vector2, int n){

	PedirN (n);
	cout << CYAN<< "Empezaremos por el vector 1: "<< NORMAL;
	rellenarvector (n, vector1, util_vector1);
	cout << CYAN<< "Seguiremos con elvector 1: "<< NORMAL;
	rellenarvector (n, vector2, util_vector2);
}


/**
@brief 
@pre 
@param 
@RETURN
@post  
*/


void salidas ( const int vector[], const int util){

	for (int i=0; i<util; i++){

		cout << SOLUCION << vector[i] << NORMAL;
	}
}
/**
@brief módulo para copiar 2 vectores ordenados en otro.
@pre 
@param 
@RETURN
@post  
*/
	
void CopiarYordenar (const int vector1 [], const int util_vector1 , const int vector2 [], const int util_vector2, const int DIM) {
	const int DIM_AUX=30;
	int aux [DIM_AUX];
	int util_aux=0;
	int total = util_vector1 + util_vector2;
	int i=0, j=0;

	while (util_aux < total){

		if (vector1[i] < vector2[j]){
		
			aux [util_aux]=vector1[i];
			util_aux++;
			i++;
		}
		if (vector2[j] < vector1[i]){
		
			aux [util_aux]=vector2[j];
			util_aux++;
			j++;
		}
		if (vector2[j] == vector1[i]){
		
			aux [util_aux]=vector2[j];
			util_aux++;
			j++;

			aux [util_aux]=vector1[i];
			util_aux++;
			i++;
		}
		if  (i == util_vector1) {
			while (util_aux != total){
				aux [util_aux]= vector2[j];
				util_aux++;
				j++;
			}
		}
		if  (j == util_vector2) {
			while (util_aux != total){
				aux [util_aux]= vector1[i];
				util_aux++;
				i++;
			}
		}
	}
	salidas(aux, util_aux);
}
	

int main () {
	const int DIM_VECTOR=20;
	int vector1[DIM_VECTOR];
	int util_vector1=0;
	int vector2[DIM_VECTOR];
	int util_vector2=0;
	int n=0;


	pedirEntradas(vector1, util_vector1, vector2, util_vector2,n);
	CopiarYordenar ( vector1 , util_vector1, vector2,util_vector2, DIM_VECTOR);

}