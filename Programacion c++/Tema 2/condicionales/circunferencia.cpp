/* Programa para calcular el radio
y la longitud de una circunerencia*/



#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double radio=0.0, area=0.0, longitud=0.0; // La variable area la introducirá el usuario y las otras las calcularemos.

	cout << " programa para calcular para cálcular el área y longitud del círculo" << endl;
	cout << "Introduzca un el radio de su  círculo: ";
	cin >> radio;

	area = 3.1415 * pow (radio, 2); // Calculos necesarios para obtener el area
	longitud = 2 * 3.1415 * radio; // Calculos necesarios para obtener la longitud.

	if (radio > 0) { // si el radio es maor que 0
		cout << " El radio introducido es: " << radio << " y es positivo."<< endl;
		cout << " El área de su circunferencia será : "<< area << endl;
		cout << " La longitud de su circunferencia será: " << longitud << endl;
	}

	if ( radio < 0 ) { // si el radio es menor que 0
		cout << "el radio de una circunferencia no puede ser negativo golf@!!!!" << endl;
	}

	if ( radio == 0 ) { // si el radio es 0
		cout << "si el radio es 0 no hay circunferencia golf@!!!!" << endl;
	}

}
