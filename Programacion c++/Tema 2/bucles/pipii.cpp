/* programa para calcular la aproximación de PI*/


#include <iostream>
#include <cmath>
using namespace std;
int main () {

	int n = 0.0; //
	double acumulador = 0.0, valor= 0.0; 
	

	for (n=0; n<=100; n++){

		acumulador += ( pow (-1.0, n) / ( (2*n + 1)*(2*n + 1)*(2*n + 1))); // calculos de la expresion

	}	
	
	acumulador = acumulador * 32; // una vez realizada la sumatoria, tendremos que despejar x multiplicando por 32

	cout << "sumandos es: " << pow(acumulador, 1.0/3)<< endl; // ese calculo equivale a la raiz cúbca
}