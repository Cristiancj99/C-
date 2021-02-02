/* Programa del satelite utilizando
un bucle for*/


#include <iostream>
using namespace std;
int main () {

	double numero = 0.0;// numero introducido por el usuario.
	double sumatoria= 0.0;// variable para calcular la suma.
	double media= 0; // para guardar las veces que se intoduce número
	

	cout << "bienvenidos al gran satélite." << endl;
		
	cout << "comience introduciendo su secuencia: ";
	cin >> numero;

	for  (sumatoria = 1; numero > 0; sumatoria = sumatoria + numero){
		
		cout << "siguiente frecuencia: ";
		cin >> numero;
		media= media + 1;
		}
	cout << " la media es de: " << sumatoria / media << endl;
}
