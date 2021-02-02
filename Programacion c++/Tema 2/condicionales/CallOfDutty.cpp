/*programa para ver la relación de dos circunferencias.*/



#include <iostream>
#include <cmath>
using namespace std;
int main () {

	double x1= 0.0, y1 = 0.0;// centro circunferencia 1
	double radio1= 0.0; // área circunferencia 1
	double x2= 0.0, y2 = 0.0; // centro circunferencia 2
	double radio2= 0.0; // área círculo 2.
	double distancia= 0.0; // distancia entre centros



	cout << " Bienbenidos al simulador de tiro tira que te rajo."<< endl;
	cout << "Para comenzar introduzca el centro del objetivo (x, y ): ";
	cin >> x1 >> y1;
	cout << " ahora introduzca el radio: ";
	cin >> radio1;
	


	cout << "introduzca el centro de su posición (x, y ): ";
	cin >> x2 >> y2;
	cout << " ahora introduzca el radio: ";
	cin >> radio2;

	distancia= sqrt ( ( (x2 -x1) * (x2 - x1) ) + ( ( y2 - y1 ) * ( y2 - y1) ) ); // cálculos necesarios para obtener la dstancia.


	if ( ( (x1 == x2) && ( y1 == y2) ) && ( radio1 == radio2) ) { // circunferencias misma posición e iguales.
		cout << "Las dos posiciones son las mismas y son igual de grandes." <<endl;
	}

		if ( ( (x1 == x2) && ( y1 == y2) ) && ( radio1 != radio2) ) { // circunferencias concéntricas
			cout << "Las circunferencias son concéntricas."<< endl;
		}


		else if ( distancia == radio1 + radio2) { //circunferencias tangentes exteriores
			cout << "Las circunferencias son tangentes exteriores."<<endl;
		}

		else if  ( ( ( x1 != x2) && ( y1 != y2 ) ) && (distancia > radio1 + radio2) ){ // circunferencias exteriores
			cout << "Las ciercunferencias son exteriores"<< endl;
		}

		else if ( distancia < radio1 + radio2) { // circunferencias secantes.
			cout << "Las circunferencias son secantes."<< endl;
		}

		else if ( distancia == radio1 - radio2) { // tangentes interiores
			cout << "Las circunferencias son tangentes interiores."<< endl;
		} 

}
