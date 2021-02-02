/* Programa para calcular la tabla 
del 0 al 10 mediante un bucle */


#include <iostream>
using namespace std;
int main () { 

	int numero = 0.0;
	int progresion = 0.0;

	cout << " bienvenido al programa para calcular la tabla del 0 al 10. ";
	cout << "introduzca el numero del que desee realizar la tabla: ";
	cin >> numero;

	if ( ( numero >= 0 ) && ( numero <= 10) ){ // condición para que solo acepte del 1 al 10
		
		while ( progresion <= 10 ) { // bucle para repetir 10 veces el cout

			cout << numero << " x " << progresion << " = " << numero * progresion << endl;
			progresion = progresion + 1 ;
		}
	}
	else {
		cout << " numeros del 0 al 10, TONTO " << endl;
	}
}