/* Programa que te enumera todas 
las fichas de un dominó*/


#include <iostream>
using namespace std;
int main () {

	int i= 0.0, j = 0.0; // Variables itinerantes.
	int ficha=0.0; // Variable para ver el número de la ficha

	cout << "Bienvenid@s al programa pra ver las fichas de un dominó."<< endl;

	for (i=0;i<=6;i++){// Bucle para repetir 6 veces el otro bucle 
		
		for (j=i;j<=6;j++){ // repetir 6 veces este proceso
		
			ficha = ficha + 1;
			cout << "ficha " << ficha << " = " << i << " , " << j << endl;
		}
	}
}