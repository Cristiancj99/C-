#include <iostream>
using namespace std;
//declaracion de funciones
/**
@brief módulo que te pide un numero hasta que es mayor que 0 
@pre no tiene 
@param int n( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post n>0 
*/

void pedirnumero( int &n){

	do{
		cout<< "por favor, introduzca un valor positivo ";
		cin >> n;

	}while ( n<0);
}

/**
@brief módulo que calcula el cuno de un número mediante nicomano
@pre n>0
@param int n (variable filtrada en el anterior modulo)
@return devuelve el cubo de n 
@post resultado>0 
*/

int FuncionNicomaniatica (int n){
	int par =0, contador =1, resultado=0;

	par= n * (n -1); // fórmula para calcular el par anterior
	

	for ( int i=1; contador<= n; i+=2){ // bucle para que sume la primera vez 1 y después 2
		contador+=1; // para ver las veces que sumamos
		resultado += par+i; // variable acumuladora.
	}
	return resultado;
}
/**
@brief módulo que calcula el cuno de un número mediante nicomano
@pre n>0 y nicomano >0
@param int n (variable filtrada en el anterior modulo)
@param int nicomano(variable calculada en el anterior módulo)
@return no devuelve nada por que es un procedimiento
@post 
*/
void salida (int n, int nicomano){

	cout << " el cubo de " << n << " es " << nicomano << endl;

}




int main () {
	
	int n=0, nicomano=0;

	cout << "Bienvenido al fabuloso programa del nicomano modular"<< endl;

	pedirnumero(n);
	nicomano = FuncionNicomaniatica (n);
	salida (n, nicomano);

	cout << "Gracias por utilizar este magnífico programa!!" << endl; 

}
