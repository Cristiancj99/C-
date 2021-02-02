/* Programa para calcular la sumatoria
de un número*/




#include <iostream>
using namespace std;
int main () {

	int numero= 0.0; // Variable que introducirá el usuario.
	int i=0.0; // itinerante.
	double sumatoria = 0.0; // variable para guardar la sumatoria.

	cout << "Bienvenid@ al programa para calcular la sumaoria de un número." << endl;
	cout << "Para comenzar, introdozca el número deseado : ";
	cin >> numero;

	for (i=1;i<=numero;i++){ // bucle para que se repita las iteraciones.
		
		sumatoria = sumatoria + ( (1.0-i) / i);
	}

	cout << "La sumatoria de "<< numero << " es: "<< sumatoria << endl;
}