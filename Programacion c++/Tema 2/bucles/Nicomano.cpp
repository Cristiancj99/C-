/* Programa para calcular el 
cubo de un número mediante nicómano*/


#include <iostream>
using namespace std;
int main () {

	int i = 0;
	int j= 0;
	float n= 0;
	int par = 0; // par anterior
	int resultado = 0; // variable acumuladora
	int contador =1; // variable para contar las veces que sumamos

	cout << "Bienvenidos al programa de Nicomano" << endl;
	cout << "Vamos a calcular los cubos.Introduzca el número: " << endl;
	cin >> n;

	par= n * (n -1); // fórmula para calcular el par anterior

		for ( i=1; contador<= n; i+=2){ // bucle para que sume la primera vez 1 y después 2
			contador+=1; // para ver las veces que sumamos
			resultado += par+i; // variable acumuladora.
		}
	cout << "El cubo de " << n << "es" << resultado << endl;
}
