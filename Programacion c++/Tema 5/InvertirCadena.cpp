#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
/**
@brief módulo que pide una cadena de char y comprueba su tamaño.
@pre size = 0
@param  char cadena [] Vector que servirá para almacenar la cadena
@param int size (por referencia) variable de tipo int donde almacenaremos el tamaño de la cadena
@RETURN Nada. es un procedimiento
@post  size >0
*/

void DimeCadena (char cadena [], int &size){

	cout << "Por favor, digame su cadena: ";
	cin.getline(cadena, 30);
	
	while (cadena[size]!='\0'){ // bucle para ver el tamaño de la cadena
		size++;
	}
}
/**
@brief módulo que invierte una cadena 
@pre size > 0 y size < DIM_CADENA
@param const char cadena [] vector de donde leeremos la cadena que invertiremos
@param int size variable de tipo int que tiene asignado el tamaño de la cadena
@RETURN Nada. Es un Procedimiento
@post  se deberá de dar como salida un la misma cadena invertida.
*/
void invierte (const char cadena [], int size){
	char invertido [size];
	int j=size-1; // variable a la que le asignaremos la cantidad de char que hay en el vector
	int i=0;
	for(i=0; i<size; i++){ // bucle para copiar de manera invertida la cadena
		invertido [i]= cadena[j];
		j--;
	}
	invertido[i]='\0';
	cout << SOLUCION<< invertido<<NORMAL<<endl;
}

int main () {

	const int DIM_CADENA=30;
	char cadena [DIM_CADENA];
	int size=0;

	DimeCadena(cadena, size);
	invierte (cadena,size);
}