/* Programa de simulacion de tiro
pes.*/


#include <iostream>
using namespace std;

int main () {



	double x1 = 0.0, y1 = 0.0; // esquina superior izqda de la portería.

	double x2 = 0.0, y2 = 0.0; // Esquina inferior derecha de la portería.

	double xt = 0.0, yt = 0.0; // Tiro del usuario.

//Entradas del usuario



	cout << "Bienvenido al fábuloso simulador de tiros QUE MALO ERES." << endl;

	cout << " Introduce dónde estará la esquina superior de tu porteria (distancia del primer palo y altura): ";

	cin >> x1 >> y1;



	cout << " Introduce dónde estará la esquina inferior derecha de tu porteria (distancia del primer palo y altura.): ";

	cin >> x2 >> y2;



	cout << " Introduzca dónde irá dirigido su tiro: ";

	cin >> xt >> yt;



	if ( ( ( xt > x1) && ( xt < x2) ) && ( ( yt < y1) && ( yt > y2 ) ) ) // Gol.

	 { 

		cout << " GOOOOOOOOOOOOOOOL!!!!!"<< endl;

	}





		else if ( ( ( xt > x1) && ( xt < x2) ) && ( ( yt > y1) ) ) { //Entre palos alto.

			cout << "UYYY!!!! La pelota salió altaa!!" << endl; 

		}



		else if ( ( xt > x2) && ( yt > y1) ) { // arriba por la derecha.

			cout << "EL TIRO SE MARCHÓ ALTO POR LA DERECHAAA!!!"<< endl;

		}



		else if ( ( xt < x1) && ( yt > y1) ) { // arriba por la izqda.

			cout << "EL TIRO SE MARCHÓ ALTO POR LA IZQUIERDAA!!!"<< endl;

		}



		else if (  ( xt < x1) && ( ( yt < y1) ) && ( yt > y2)  ) { // fuera por la izqda.	

			cout << "La pelota se marchó por la izquierdaa!!!" << endl; 

		}



		else if (  ( xt > x2) && ( ( yt < y1) ) && ( yt > y2)  ) { // fuera por la derecha.

			cout << "La pelota se marchó por la izquierdaa!!!" << endl; 

		}



		else if ( ( xt < x1) && ( yt == y2) ) { // Raso por la izquierda

			cout << "EL TIRO SE MARCHÓ ROZANDO EL PALO IZQUIERDOO!!!"<< endl;

		}



		else if ( ( xt > x2) && ( yt == y2) ) { // Raso por la derecha

			cout << "EL TIRO SE MARCHÓ ROZANDO EL PALO DERECHOOO!!!"<< endl;

		}	



		else if ( yt < y2) { // el tiro no llega a la portería

			cout << "ponte a practicar, COJOOOOO!"<< endl;

		}



		else if ( ( ( xt > x1) && ( xt < x2) ) && ( ( yt == y1) ) ) { //Larguero.

			cout << "UYYYY!! LA PELOTA SE ESTRELLÓ EN EL LARGUEROO!!" << endl; 

		}



		else if (  ( xt == x1) && ( ( yt < y1) ) && ( yt > y2)  ) { // palo izquierdo.

			cout << "UYY!! LA PELOTA SE ESTRELLÓ EN EL PALO IZQUIERDOO" << endl; 

		}



		else if (  ( xt == x2) && ( ( yt < y1) ) && ( yt > y2)  ) { // palo derecho.

			cout << "UYY!! LA PELOTA SE ESTRELLÓ EN EL PALO DERECHOOO" << endl; 

		}



		else if ( ( xt == x1) && ( yt > y2) ) { // Alto por encima del palo izqdo

			cout << "SE MARCHÓ POR ENCIMA DEL PALO IZQDOOO!"<< endl;

		}



		else if ( ( xt == x2) && ( yt > y2) ) { // Alto por encima del palo derecho

			cout << "SE MARCHÓ POR ENCIMA DEL PALO DERECHOOO!"<< endl;

		}

}