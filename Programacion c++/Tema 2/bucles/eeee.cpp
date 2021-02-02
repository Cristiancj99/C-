/* Programa para calcular la 
aproximación del numero eee*/



#include <iostream>
using namespace std;
int main () {

	int i= 0.0, j = 0.0; // Variables itinerantes.
	double sumatoria = 0.0; // variable para ir guardando la sumatoria
	double factorial = 0.0;// variable para ir guardando la sumatoria
	int n = 0.0; // variable que asignará el usuario

	cout << "Bienvenid@s al programa para ver la aproximación de e"<< endl;
	cout << "Introduzca el valor de n para realizar la sumatoria.";
	cin >> n;

	sumatoria=0;

	for (i=0;i<n;i++){ // buble para que me vaya reiniciando el factorial cada vez y haciendo la sumatoria
		factorial = 1;		
		for (j=1;j<=i;j++){ // bucle para realizar el factorial
			factorial = factorial * j;
		}
		sumatoria += 1.0/factorial;  
		
	}

	cout << "La aproximación es: " << sumatoria << endl;
}