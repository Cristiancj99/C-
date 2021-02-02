/* programa para hacer una calculadora mediante un 
switch*/


#include <iostream>
using namespace std;
int main () {
	


	double a = 0.0, b = 0.0;
	char r; // resultado.

	cout << "bienvenido a la supr calculadora 3000 6000" << endl;

	cout << " Introduzca dos números para realizar las cuentas: ";
	cin >> a >> b;

	cout << " escribe s(suma), r (resta),m (multiplicacion) y d (division) dependiendo de la operación que quieras hacer: "<<endl;
	cin >> r;

	switch (r) {

		case 's': // suma.
			cout<< "el resultado de su suma es de: " << a + b << endl;
		break;

		case 'r' : //resta
			cout << " El resultado de la resta es: " << a - b << endl;
		break;

		case 'm': //multiplicacion
			cout << " El resultado de la multiplicación es: " << a * b << endl;
		break;

		case 'd': // división
			if ( b != 0 ){ // si b es 0 no se puede dividir.
				cout << " El resultado de la división es: " << a / b << endl;
			}
			else {
				cout << " No se puede dividir entre 0." << endl;
			}
		break;
	
	default:
		cout << " introduzca alguno de los cuatro casos golf@!( cuidado con las mayúsculas)" << endl;
	}
}