#include <iostream>
using namespace std;
int main () {

	int dato = 0.0;

	do { 
		cin >> dato;
		cout << "Recibido: " << dato << endl;
	} while ( dato >= 0 );
		cout << " Fin de transmisión" << endl;
}