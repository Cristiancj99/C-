/* Programa para ver la nota de 
un alumno*/



#include <iostream>
using namespace std;
int main () {

	int nota_alumno = 0.0; // nota introducida por el usuario
	cout << "Bienvenidos al programa para saber que calificación tienes. " << endl;
//Entradas
	cout << " Por favor. Para comenzar, introduzca su nota: ";
	cin >> nota_alumno;
//salidas
	if ( ( nota_alumno > 10 ) && ( nota_alumno < 0 ) )	{ // para que la nota esté entre 0 y 10

		cout << "Sólo válidos con números del 1 al 10 " << endl;
	}
		
		else if ( ( nota_alumno >= 0) && ( nota_alumno < 5) ) { // Caso del alumno suspenso
			cout << " Lo siento señor párrizas, usted está suspenso."<< endl;
		}
	
		else if ( ( nota_alumno >= 5) && ( nota_alumno < 7) ) { // el alumno esta aprobado
			cout << " Estás aprobadillo." << endl;
		}

		else if ( ( nota_alumno >= 7) && ( nota_alumno < 9) ) { // El alumno tiene un notable
			cout << " Enhorabuena, tienes un notable !! "<< endl;
		}

		else if ( ( nota_alumno >= 9) && ( nota_alumno <= 10) ) { // el alumno tiene un sobresaliente. 
			cout << " FELICIDADEEES!!! tienes un pedazo de sobresaliente!! " <<endl;
		}
}