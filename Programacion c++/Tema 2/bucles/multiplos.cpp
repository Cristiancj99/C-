/* 	Programa que calcula los multiplos de un
número en un intervalo*/



#include <iostream>
using namespace std;
int main () {

	int x1 = 0.0, x2 = 0.0; // variables para asignar el parámetro
	int numero= 0.0; // variable que se le asignará al numero introdcido por el usuario
	double division = 0.0; // variable para ir haciendo la división y poder comprobar.
	int progresion = 0.0; // variable itinerante.
// Entradas
	cout << " introduzca el intervalo en el que buscaremos los múltiplos: ";
	cin >> x1 >> x2;


	cout << "introduzca el numero para calcular sus múltiplos: ";
	cin >> numero;

	for ( progresion=x1; progresion <=x2; progresion++) { // bucle para que vaya comprobando cada número del intervalo
	
		division = progresion % numero;
		
		if (division == 0){
			cout << progresion << "Es un múltiplo de "<< numero <<endl;
 
		}
	}
}