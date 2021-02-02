/* programa para ver las 10
tablas de multiplicar mediante un bucle*/


#include <iostream>
using namespace std;
int main () {

	int i=0.0, j= 0.0; // variables itinerantes.

	for (i=1;i<=10;i++){
		
		for (j=1;j<=10;j++){
		
			cout << i << " x " << j << " = " << i*j << endl;

		}
	}
}