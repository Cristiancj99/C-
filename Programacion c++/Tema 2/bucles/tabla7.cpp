/*Programa que te hace la tabla del 7 */


#include <iostream>
using namespace std;
int main () {
	
	int numero = 0.0 ;

	cout << "vamos a realizar la tabla del 7 " << endl;

	do { // bucle para repetir 10 veces el cout
		cout << " 7 x " << numero << " = " << 7 * numero << endl;
		numero= numero + 1;

	} while ( numero <= 10 );
}	