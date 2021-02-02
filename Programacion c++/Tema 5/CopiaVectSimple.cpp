#include <iostream>

using namespace std;



int main () {



	const int TAM_VECTOR=25; // tamaño del vector

	int uno [TAM_VECTOR]; // vector numero uno

	int dos [TAM_VECTOR]; // vector numero 2

	int util_uno=0;

	int util_dos=0, numeros=0, i=0;



	cout << "Bienveidos al pograma para copar un vector en otro"<< endl;



	do{ // pedimos un número para saber cuando parar de pedir numeros después

		cout << "Por favr, comience a introducir el numero de numeros que va a introducir";

		cin>> numeros;

	}while ( (numeros < 1) || (numeros > TAM_VECTOR ) );



	for (i=0; i < numeros ; i++){ // pedir el contenido del vector



		cout << "comience introduciendo los númmeros";

		cin >> uno [i];

		util_uno ++;

	}

		cout << "Has usado " << util_uno << " de " << TAM_VECTOR << endl; //DEBUG



	for ( i=0; i < util_uno ; i++){ // bucle para pegar y dar salida a los valores de uno en dos

		

		dos[i]=uno[i];

		cout << dos[i] << endl;

		util_dos ++;

	}

	cout << "comparación espaco usado en os dos vectores es de " << util_uno << " y " << util_dos << endl;

}