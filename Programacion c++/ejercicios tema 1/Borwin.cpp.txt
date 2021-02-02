/* Programa para averiguar el método
de Borwein */

#include <iostream>
#include <cmath>
using namespace std;
int main () {	
	double pi0 = 0.0, pi1 = 0.0, pi2 = 0.0;
	double x0 = 0.0, x1 = 0.0, x2 = 0.0;
	double y1 = 0.0, y2 = 0.0;
	
	cout << "Bienvenidos al programa para calcular el número pi con el método Borwein" << endl;

//nos da los valores de x0, y1, pi0.
	x0 = sqrt(2);
	y1 = pow (2, (1.0/4.0));
	pi0 = 2 + sqrt(2);
// calculamos pi1.
	x1 = (1.0/2.0) * ( sqrt(x0) + ( 1.0/sqrt(x0)));
	pi1 = pi0 * ( (x1+1) / (y1+1) );

// Calculamos pi2.
	x2 = (1.0/2.0) * (sqrt(x1) + (1.0/sqrt(x1)));
	y2 = ((y1 * (sqrt(x1)) + (1.0/sqrt(x1))) / (y1 + 1));
	pi2 = pi1 * ((x2 + 1) / (y2 + 1));
// Mostramos las salidas del programa.
	cout << "el resultado de pi0 es: " << pi0 << " El resultado de pi1 es : " << pi1 << " y por último,  el resultado de pi2 es de: " << pi2 << endl;
}
