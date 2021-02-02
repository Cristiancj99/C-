/* programa para calcular la media de 
un satélite que recibe constantemente 
frecuencias. */


#include <iostream>
using namespace std;
int main () {

	int frecuencia= 0.0;
	int nfrecuencia= 0.0; // numero de frecuencias para después hacer la media.
	double media= 0.0; // media total
	double suma = 0.0; //variable para calcular la suma de las frecuencias.

	cout << "Bienvenidos al programa para calcular la media de las frecuencias" <<endl;

	cout << "intoduzca la frecuencia: ";
	cin >> frecuencia;

	while ( frecuencia != 0) { // bucle para que se repita el bucle hasta que se introduzca 0.

		cout << "continue las frecuencias: " << endl;
		cout << "para finalizar pulse 0 " << endl;
		nfrecuencia= nfrecuencia + 1;
		suma= suma + frecuencia; // calcular la suma total.
		cin >> frecuencia;
	}
	
	media = suma / nfrecuencia; // calcular la media.
	cout << "La media será de: " << media << endl;
}