/*Programa que te calcula cualquier
tabla de multiplicaar*

#include <iostream>
using namespace std;
int main () {
	int numero1 = 0.0, numero2= 0.0;


// Pedimos las entradas al usuario.
	cout << "introduzca un número del 1 al 10 para hacer su tabla de mutiplicar: ";
	cin >> numero1;


	if ( (numero1 <= 10 ) && (numero1 >= 0 ) ) { // sólo números del 1 al 10.

		do { // Bucle para que se haga la tabla.
			cout << numero1 << " x " << numero2 << " = " << numero1 * numero2 << endl;
			numero2= numero2 + 1;
		} while ( numero2 <= 10);
	}

	else {
		cout << " Números del 1 al 10 chulo " << endl;
	}		

}
