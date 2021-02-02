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



	do { // filtro para los números menores o iguales que 0
	cout << "Introduzca un número  mayor que 0 para comprobar si es primo o compuesto: ";
	cin>> n;
	} while ( n <= 0);

	suprimo= esprimo(n); // llamamiento de la función

	if (suprimo == true) { 

		cout << "El número es primo "<<endl;
	}
	else 
		cout << "NUmero compuesto" << endl;
}
