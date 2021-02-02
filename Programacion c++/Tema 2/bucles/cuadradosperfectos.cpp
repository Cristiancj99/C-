
/* Programa para ver si un número
es cuadrado perfecto */


#include <iostream>
using namespace std;
int main () { 

	int numero = 0.0; // Numero del usuario.
	int progresion = 0.0; // Para comprobar las divisiones.
	int contador = 0.0; //para utilizarlo de ayuda


	cout << "bienvenidos al progrma para ver s un número es perfecto" << endl;

	cout << " Para comenzar, introduzca el número : ";
	cin >> numero;

	while ( progresion <= numero) { // para que compruebe hasta llegar al número introducido
		
		progresion = progresion + 1;
		
		if ( progresion * progresion == numero) {// si el cuadrado de progresion es numero se le suma 1 al contador.
			
			contador = contador + 1;
		}
	}

	if (contador == 1) { // si contador es 1 significa que el numero es cuadrado perfecto
		cout << "El número "<< numero << " es un cuadrado perfecto" << endl;
	}
	else {
		cout << "El número "<< numero << " no un cuadrado perfecto" << endl;
	}
}