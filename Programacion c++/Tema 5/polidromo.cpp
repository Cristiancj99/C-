#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
/**
@brief Modulo para pedir una cadena y comprobar su longitud
@param char vector Vector donde guardaremmos la cadena introducida por el usuario
@param int size.(por referencia) variable de tipo int a la que se le asignará el tamaño del vector
@param const int DIM (L) variable para ver el tamao máximo que nos permite una cadena
@RETURN Nada. es un procedimiento
@post  Size tendrá que ser mayor que 0 y menor que DIM
*/

void DimeSizeCadena (char vector [], int &size, const int DIM){
	size=0;
	cout << "Por favor, introduzcame la cadena de caracteres."<< endl;
	cin.getline (vector, DIM);
	while (vector[size]!= '\0'){
		size++;
	}
	cout << "Tamaño : " << size << endl;
	
}
/**
@brief  modulo que quita el espacio de una cadena
@pre  size 1 > 0.
@param Const char original. (L) variable de lectura para poder usarla para copiar el vector en otro eliminando los espacios
@param inst size1. Tamaño de la cadena 1.
@param char destino. vector donde se compiara el vector original sin espacios
@size. Tamaño cadena destino
@RETURN Nada. Es un procedimiento
@post  size2 tendrá que ser mayor que 0 y menor que size 1. 
*/
void quitaespacios (const char original [], int size1, char destino [], int &size2){

	size2=0;
	int i=0;
	for( i=0;i<size1; i++){ // bucle para copiar hasta que finaliza la cadena

		if (original[i] != ' '){ // si el caracter es distinto a espacio se copiará
			destino[size2]=original[i];
			size2++;	
			
		}
	}
	destino [i] = '\0';
}

/**
@brief Modulo que comprueba la cadena para ver si es polidroma
@pre   el tamaño (size) debe de ser menor que DIM 
@param  const char cadena. (LECTURA) cadena para copiarla en otro vector.
@param int size2 (L) variable que lleva el tamaño de la cadena.
@param bool polidromo (por REFERENCIA) variable utilizada para comprobar si la cadena es polidroma o no.
@RETURN Nada. Es un procedimiento
@post  polidromo true o false. Dependiendo de si se cumple o no la condicion
*/
void CompruebaCadena ( const char cadena[], int size2, bool &polidromo){

	for (int i=0; i < size2/2 && polidromo==true; i++){ // bucle para comprobar la cadena 
		if (cadena[i] != cadena[size2 -1 -i]) { // va comprobando el primer espacio con el ultimo
			polidromo = false;
		}

	}
}

/**
@brief modulo para dar las salidas del vector
@pre polidromo tendrá que ser o true o false
@param  bool polidromo. servirá apara comprobar si es polidromo o no
@RETURN Nada. es un procedimiento
*/

void Salidas ( bool polidromo){

	if (polidromo==true){
	
		cout << SOLUCION <<"la cadena es polidroma" << NORMAL<<endl;
		
	}
	else{
	
		cout << DEBUG<<"La cadena no es polidroma" << NORMAL<< endl;
	}
}

		


int main () {

	const int DIM_VECTOR=100;
	char cadena1[DIM_VECTOR];
	char cadena2 [DIM_VECTOR];// variable para guardar la cadena sin espacios
	int size1=0;
	int size2=0; // tamaño de la cadena sin espacios
	bool polidromo=true; // variable para comprobar si es polidromo o no

//invocación de las funciones

	DimeSizeCadena ( cadena1, size1, DIM_VECTOR);
	quitaespacios ( cadena1, size1, cadena2, size2);
	CompruebaCadena (cadena2, size2, polidromo);
	Salidas(polidromo);

}