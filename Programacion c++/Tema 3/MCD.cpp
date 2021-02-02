#include <iostream>
using namespace std;

//Declaración de funciones
/**
@brief módulo calcula el mcd de dos numeros
@pre a>0 y b>0
@param int n
@param int n1
@return devolverá el máximo comun divisor
@post MaxDiv >0
*/
int mcd ( int n, int n1){

int MaxDiv  = 0;

	for (int i = 1;i < n1 ;i++){ // proceso para calcular el MCD
		
		if (n%i == 0 && n1%i == 0){
			MaxDiv = i;
		}
	}
	return MaxDiv ;
}
/**
@brief módulo que filtra dos numeros hasta que 
@pre no tiene 
@param int a( variable por REFERENCIA)
@param int b( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post a>0 y b>0
*/
void entrada (int &a , int &b) {

	do{
		cout << "introduzca un número: ";
		cin >> a;
		cout << "Introduzca el 2 numero ( menor que el primero) ";
		cin >> b;
	}while (b>= a);
}


int main () {

	int a=0, b=0;
	int res= 0;

	entrada ( a, b);
	res= mcd (a, b);
//salidas
	cout << " el máximo comun divisor de " << a << " y " << b << " es " << res <<endl;
} 