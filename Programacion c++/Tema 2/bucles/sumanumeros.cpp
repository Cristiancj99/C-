#include <iostream>
using namespace std;
int main () {

	double suma= 0.0, numero = 0.0; // numero será la entrada del usuario

	cout << " vamos a realizar un programa para sumar varios números a la vez" << endl;


	do { // bucle para que se repita la petición de introducir el número.

		cout << "Introduzca el número a sumar: ";
		cin >> numero;

		if (!cin){ // filtro letras
			cout << " suma números, no letras. GOLF@" <<endl; 
		}

		else {
			suma = suma + numero;

			if ( numero != 0 ) { // para que muestre un mensaje cuando no es 0 indicando que cuando introduzca 0 finalizará el programa.
				cout << " cuando finalice de sumar números, introduzca 0 para obtener el resultado" <<endl;
			}

		}

	} while ( numero != 0 );

	cout << " El resultado de la suma es: " << suma << endl;
}