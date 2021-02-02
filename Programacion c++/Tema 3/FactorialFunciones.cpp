/* Programa para calcular un fatorial 
utilizando una función */ 



#include <iostream>
using namespace std;

// declaración de funciones.

int factorial ( int n) { // Función para calcular el factorial
	int acumulacion =1;

	for (int i=2; i<=n; i++){ // bucle acumulativo para el factorial

		acumulacion= (acumulacion * i);
	}
	return acumulacion;
}

int main () {

	int ResultadoFinal=0;
	int n = 0;

	cout << "Bienvenido al programa para el cálculo de un número fatorial" << endl;

	do{ // filtro para los números negativos.
		cout << "por favor, introduzca un número positivo: "<< endl;
		cin >> n;
	
	}while ( n <0);

	ResultadoFinal= factorial (n); // llamada a la función

	cout << "El factorial es: " << ResultadoFinal << endl;
}