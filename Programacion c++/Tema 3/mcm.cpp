#include <iostream>
using namespace std;
/**
@brief módulo que filtra dos numeros hasta que 
@pre no tiene 
@param int a( variable por REFERENCIA)
@param int b( variable por REFERENCIA)
@return nada. es un procedimiento, con lo cual la salida se realiza mediante el parámetro formal
@post a>0 y b>0
*/
    
void entrada (int &a , int &b) { // función para pedir los datos de entrada

	do{ // filtro para que a sea mayor que b, si no da error
		cout << "introduzca un número: ";
		cin >> a;
		cout << "Introduzca el 2 numero ( menor que el primero) ";
		cin >> b;
	}while (b>= a);
}
/**
@brief módulo calcula el mcd de dos numeros
@pre a>0 y b>0
@param int a( variable por REFERENCIA)
@param int b( variable por REFERENCIA)
@return devolverá el máximo comun divisor
@post MaxDiv >0
*/
int mcd ( int n, int n1){ 

int MaxDiv  = 0;

	for (int i = 1;i < n1 ;i++){
		
		if (n%i == 0 && n1%i == 0){
			MaxDiv = i;
		}
	}
	return MaxDiv ;
}

/**
@brief módulo calcula el mcm de dos numeros
@pre a>0 y b>0 y MaxDiv>0
@param int a( variable por REFERENCIA)
@param int b( variable por REFERENCIA)
@param MaxDiv( variable calculada anteriormente)
@return devolverá el minimo común multiplo
@post MinimoMultiplo >0
*/

int mcm( int maxdiv, int n, int n1){


	int MinimoMultiplo=0;

	MinimoMultiplo = (n* n1) / maxdiv; //Proceso para calcular el mcm

	return MinimoMultiplo

}


void salidas (int maxdiv, int minmul){

	cout << " El MCD es: " << maxdiv << " Y el mcm es: " << minmul << endl;
}

int main () { 

	int n=0,n1= 0;
	int maxdiv = 0;
	int minmul=0;

	entrada (n,n1);
	maxdiv = mcd (n,n1);
	minmul=mcm ( maxdiv, n,n1);
	salidas (maxdiv,minmul);
}
