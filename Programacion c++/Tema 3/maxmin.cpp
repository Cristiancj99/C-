#include <iostream>
using namespace std;
//declaración de funciones

/** 
@brief módulo que filtra un numero hasta que es mayor que 0 y distinto de -1
@pre no tiene 
@param int n( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post n>0 o n!=-1
*/
void pedirNumeroFiltrado (int &n) {

	do{
		cout<< "Introduce un número entero ";
		cin >> n;
	}while ( (n<0) & (n!=-1) );
	
}
/** 
@brief modulo que calcula el máximo y el mínimo
@pre inicializar el máximo y el mínimo a n
@param int minimo( variable por REFERENCIA)
@param int maximo( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post (maximo > 0) y (minimo >0)
*/
void MaxMin (int &maximo, int &minimo) {
	int numero=01;
	pedirNumeroFiltrado(numero); 
	maximo= numero;
	minimo=numero;

	while ((numero>0)&& (numero != -1) ){
		pedirNumeroFiltrado(numero); 
		if (numero != -1) { // condicion para que si el numero es -1 no lo guarde
			if (numero < minimo){ 
				minimo = numero;
			}
			if (numero> maximo){
	
				maximo=numero;
			}
		}
	}
}

int main() {

	int maximo=0,minimo=0;
//Invocación de funciones
	MaxMin (maximo, minimo);
//Salidas.

	cout << "El número mas grande es: "<< maximo<< " y el mas pequeño es: "<< minimo << endl;
	
}
