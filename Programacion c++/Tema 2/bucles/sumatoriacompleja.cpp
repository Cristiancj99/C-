/* Programa para calcular la
una sumatoria compeja*/


#include <iostream>
using namespace std;
int main () {

	int numero= 0.0; // Variable que introducirá el usuario.
	int k=0.0; // itinerante.
	double sumatoria = 0.0; // variable para guardar la sumatoria.

	cout << "Bienvenid@ al programa para calcular la sumaoria de un número." << endl;
	cout << "Para comenzar, introdozca el número deseado : ";
	cin >> numero;

	for (k=1;k<=numero;k++){// bucle para que repita los cálculos.
		
		sumatoria = sumatoria + ( (2*k)-1);
	}

	cout << "La sumatoria de "<< numero << " es: "<< sumatoria << endl;
} 