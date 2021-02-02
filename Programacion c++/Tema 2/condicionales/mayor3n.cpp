/* Programa para calcular 
el mayor de tres números*/



#include <iostream>
using namespace std;
int main () {
 	double a= 0.0 , b = 0.0, c = 0.0;// variables que nos introducirá el usuario.

	cout << " bienvenidos al programa para calcular que número es mayor." << endl;

	cout << "para empezar, entroduzca tres números: ";
	cin >> a >> b >> c;

	if ( (a > b ) && ( a > c ) ) { // caso de que a es el mayor.
		cout << "el número mayor es : " << a << endl;
	}

	else {

		if ( (b > a ) && ( b > c ) ) { // caso de que b es mayor
			cout << "el número mayor es : " << b << endl;
		}

		else {

			if ( (c > a ) && ( c > b ) ) { // caso de que c es mayor.
				cout << "el número mayor es : " << c << endl;
			}

			else { // caso de todos los números iguales.
				cout << " todos los números son iguales." << endl;
			}
		}
	}
}