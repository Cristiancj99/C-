/* programa para calcular el numero
factorial*/



#include <iostream>
using namespace std;
int main () {

	int numero= 0.0; // variable introducida por el usuario.
	
	int factor= 1; // para calcular el factorial

	cout << "bienvenido al programa para calcular el número factorial de un número"<<endl;
	cout << "introduce el nḿero deseado: ";
	cin >> numero;
	
	if (numero < 0) { // si el número es negativo su factorial es 0.
		
		cout << " El número factorial de " << numero << " es 0." << endl;
	}

	else if ( numero == 0) { // si el número es 0 su factorial es 1.
		cout << " El número factorial de " << numero << " es 1 " <<endl;
	}

	else if ( numero >=1) { // proceso para calcularel factorial.

		for( int progresion=1; progresion <= numero; progresion = progresion + 1){
			factor = factor * progresion;
		}	
	
		cout << "El numero factorial de " << numero << " es: " << factor << endl;
	}

}