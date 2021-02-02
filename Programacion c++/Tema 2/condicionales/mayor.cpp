/*Programa para calcular el número mayor*/


#include <iostream>
using namespace std;
int main () {
	float a= 0.0, b= 0.0; // Numeros que introducirán usuarios
//entradas
	cout << "Bienvenidos al programa para calcular si un es mayour que otro." << endl;
	cout << " introduzca dos números: ";
	cin >> a >> b;
	if (a > b) { // condición de que si a es mayor que b
	cout << " El número " <<a<< " es mayor que el número "<<b<< endl;
	}
	else
//salidas
	cout << " El número " <<b<< " es mayor que el número "<<a<< endl;

}
