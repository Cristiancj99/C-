/* Programa para calcular la media 
aritmética de tres números  */ 

#include <iostream>
using namespace std;

// Declaración de funciones

float mediatresn ( float n1,  float n2, float n3) {

	double media= 0.0;	
	media = ((n1+n2+n3)/3); // calculos necesarios para la media

	return media;
}

int main () {

	float n1=0.0, n2=0.0, n3=0.0; // Variables introducidas por el usuario
	float resultado= 0.0;

	cout << "Bienvenido al programa para calcular la media aritmética de 3 n" << endl;

	cout << " Introduzca 3 numeros: ";
	cin >> n1 >> n2 >> n3;

	resultado = mediatresn ( n1, n2, n3); // invocación de función

	cout << "La media de " << n1 << ", " << n2 << " y "<< n3<< " es " << resultado << endl;

}