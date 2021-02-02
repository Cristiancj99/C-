/* Programa para calcular las ecuaciones de 2 grado

del tipo ax^2 - bx + c = 0*/





#include <iostream>

#include <cmath>

using namespace std;

int main() {

// Marcamos las variables necesarias

	double a= 0.0, b= 0.0, c= 0.0;

	double respuesta1= 0.0, respuesta2= 0.0;

	cout << " Bievenido al programa para calcular ecuaciones de 2 grado" << endl;

//pediremos las ENTRADAS del programa al usuario. 

	cout << "Para empezar, introduzca el valor de a: ";

	cin >> a;

	cout << " Para continuar, introduzca el valor de b: ";

	cin >> b;

	cout << " Finalmente, introduzca el valor de c y verá la magia: ";

	cin >> c;



	if ( (a == 0) && (b == 0) && (c == 0) ) { // todo 0
	cout <<" ¿ Eres tonto ? " << endl;
	}



	else if ( (a == 0) && (b == 0) ) {// caso de que a y b sea 0. ( c=0)		
	cout <<" Si a y b son iguales a 0 se quedara una ecuacion irracional."<<endl; 
		}


	else if (( b*b - 4*a*c) < 0 )  { // ráiz negativa
	cout << "Las raíces negativas no tienen solución."<< endl;
	}

	

	else if (a != 0) {// caso de que a = 0 ( no se puede dividir)

		respuesta1 = (-b + sqrt( b*b - 4*a*c))/ (2*a);

		respuesta2 = (-b - sqrt( b*b - 4*a*c))/ (2*a);

		cout << "Los resultados de la ecuación serán resultado x1 : " << respuesta1 << " y el resultado x2 será : " << respuesta2 << endl; 

	}

	else if(a == 0) { // no se puede dividir.

		cout << " No se podrá dividir entre cero y 2*0 = 0 " <<endl;

	}
	
}