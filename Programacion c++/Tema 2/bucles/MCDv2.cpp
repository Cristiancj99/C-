/* Programa para calcular el 
mcd de dos números */



#include <iostream>
using namespace std;
int main () {

	int a=0.0, b = 0.0; //Variables dadas por el usuario
	int i =0.0; // variable de iteración
	double division = 0.0; // para comprobar el resto.
	bool mcd= false; // Lo utilizaremos para salir del bucle.

	cout <<"Bienvenidos al programa para calcular el m.c.d"<<endl;
	cout << "Comenzaremos por introducir los dos números: ";
	cin >> a >> b;


	if (a > 0 && b > 0 ){ // filtro para números negativos.
		for ( i=a;(i>=1 && mcd==false);i--){
			
			division = b % i;

			if ( ( division == 0) && ( a % i == 0)) { // condición para ver si es divisor en los 2.
				cout << "el máximo comun divisor es: "<< i << endl;
				mcd =true; // para que la primera vez que coincidan salga del bucle.
			}
		}
	}
	else {
		cout << "El programa no acepta númeos negativos.."<<endl;
	}
}
