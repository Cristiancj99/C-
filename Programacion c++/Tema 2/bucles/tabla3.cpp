#include <iostream>
using namespace std;
int main () {

	int numero = 0.0; 
	
	cout << "bienvenido al programa para calcular la tabla del 1 al 10"<<endl;
	cout << "Introduzca un número del 1 al 10: ";
	cin >> numero;

	if ( (numero >=0) && ( numero <= 10) ) { // para que el número sea de 1 al 10.

		for ( int progresion=0.0; progresion <= 10; progresion= progresion + 1 ) { // bucle para que repita 10 veces el cout
		
			cout << numero << " x " << progresion << " = " <<  numero * progresion << endl;
		}
	}
	else {
	cout <<"NUMEROS DEL 1 AL 10!." << endl;
	}
}