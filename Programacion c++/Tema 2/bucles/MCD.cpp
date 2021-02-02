/* Programa para calcular el MCD
de dos números*/


#include <iostream>
using namespace std;
int main () {

	int a=0.0, b = 0.0; //Variables dadas por el usuario
	int i =0.0; // variable de iteración
	double division = 0.0; // para comprobar el resto.

	cout <<"Bienvenidos al programa para calcular el m.c.d"<<endl;
	cout << "Comenzaremos por introducir los dos números: ";
	cin >> a >> b;

	
		for ( i=a;i>=1;i--){
			
			division = b % i;

			if ( ( division == 0) && ( a % i == 0)) { // condición para ver si es divisor en los 2.
				cout << "el máximo comun divisor es: "<< i << endl;
				break; // para que la primera vez que coincidan salga del bucle.
			}
		}
}
