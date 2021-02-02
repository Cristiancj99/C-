/* programa para ver si un movimiento de la 
Reina el Caballo o la Torre son válidos.*/




#include <iostream>
#include <cmath>
using namespace std;
int main () {

	char f;
	int x1 = 0.0, y1 = 0.0;
	int x2=0.0, y2=0.0;

	cout << "INTRODUZCA UNA LETRA SEGÚN LO QUE QUIERA MOVER T(TORRE), una R (REINA), o C (CABALLO)"<<endl;
	cin >> f;

	cout << "introduzca la posicion inicial de su pieza";
	cin >> x1 >> y1;

	cout << "Introduzca la posición donde desea mover su ficha: ";
	cin >> x2 >> y2;


	switch (f) {

	case 'T' :
		if ( ( (y2 +y1 <= 7) && (y2-y1 >=1) && ( x2 == x1) ) || ( (x2 +x1 <= 7) && (x2-y1 >=1) && ( y2 == y1) ) ) { // movimientos podibles en vertical y en horizontal para la torre
			cout << "El movimiento es válido"<< endl;
		}

		else {
			cout << "El movimiento no es válido"<< endl;
		}
	break;
	
	case'R' : 
	
		if ( ( ( (y2 +y1 <= 7) && (y2-y1 >=1) && ( x2 == x1) ) || ( (x2 +x1 <= 7) && (x2-y1 >=1) && ( y2 == y1) ) )  ||  (abs ( x1-x2) ) ==  ( abs ( y1-y2) ) ){ // utilizamos el absoluto para los movimientos en diagonal.

			cout << "El movimiento es válido"<<endl;
		}
		else {
			cout << "el movimiento no es válido" << endl;
		}
	break;

	case 'C' : 

		if ( ( (y2 == y1 + 2) && ( (x2 == x1 -1) || ( x2 == x1+1) ) ) || ( (y2 == y1 - 2) && ( (x2 == x1 -1) || ( x2 == x1+1) ) ) || ( (x2 == x1 + 2) && ( (y2 == y1 -1) || ( y2 == y1+1) ) ) || ( (x2 == x1 - 2) && ( (y2 == y1 -1) || ( y2 == y1+1) ) ) ) {// todas las condiciones del caballo

		cout << "El movimiento es válido"<<endl;
		}
		else {
		cout << "El movimiento no es válido"<< endl;
		}
	break;

	}

}