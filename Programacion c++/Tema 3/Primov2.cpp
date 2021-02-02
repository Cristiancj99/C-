/* Programa para calcular si
un número es primo o no  */ 

#include <iostream>
using namespace std;
// declaración de funciones

bool esprimo ( int n){ // función para calcular un primo

	bool primo = true;

	for (int i = 2; ( (i<n) && (primo==true) ); i++) {

		if (n % i == 0){ // si el resto es 0, significárá que el número es divisible.
			
			primo =false;
		}
	}
	
	return primo;
}

int main () {

	bool suprimo = false;
	int n =0;

	cout << "Para comenzar, intoduzca 1 número mayor a 0: ";
	cin >> n;

	while ( n > 0) { // bucle para que me pida ua y otra vez la introducción de un número


		suprimo= esprimo(n); // llamamiento de la función

		if (suprimo == true) { 

			cout << "El número es primo "<<endl;
		}
		else 
			cout << "NUmero compuesto" << endl;

	
		cout << "continue escribiendo para comprobar. Para finalizar el programa escriba un número menor o igual a 0" << endl;
		cin >> n;
	}
}