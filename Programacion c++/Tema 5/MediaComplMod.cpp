#include <iostream>

#include <cmath>

#define RED "\033[1;31m"

#define NORMAL "\033[1;0m"

using namespace std;

/**
@brief Módulo que sirve para rellenar un vector. Una vez que introduzcas un valor menor que 0 se finalizará de introducir notas.
@pre util_notas==0
@param int v [] vector en el cual guardaremos todos los numeros que introducirá el usuario
@param int util_notas. (por referencia) Variable que servirá para poder seguir el estado de vector.
@RETURN Nada. Es un procedimiento
@post  util_uno>0 y < DIM_VECTOR 
*/



void introducenotas (int v[],int  &util_notas, ){


	bool correcto=true; // variable que utilizaremos para salir del bucle cuando ingresen un número menor a 0
	for (int i=0; (v [i] <0) || ( correcto ==true);i++) {



		cout << "introduce números hasta 10 veces: " << endl;

		cin >> v [i];

		if (v [i] > 0){ // si util_notas es mayor que 0 el numero se introducirá correctamente

			util_notas ++;

		}

		else { // si el numero es menor que 0 se saldrá del bucle

			correcto = false;

		}

	}

}
/**
@brief Módulo que sirve para calcular la media de un vector.
@pre util_notas < 0
@param int v [] vector sobre el que calcularemos la media
@param int util. (por referencia) Variable que servirá ver cuantas notas tenemos introducidas en el vector
@param double media (por referencia) variable de tipo double que utilizaremos para asignar la media del vector 
@RETURN Nada. Es un procedimiento
@post  util se mantendrá igual y media >0. 
*/

void CalcularMedia (int v [], double &media, int util) {



	for (int i=0;i<util;i++){ // bucle para calcular la media



		media+= v[i];

	}

	media/= util; 

}

/**
@brief Módulo que sirve para calcular la desviación y la varianza.
@pre util_notas > 0 y media > 0
@param int v [] vector sobre el que calcularemos la desviación y la varianza
@param int util_notas. (por referencia) Variable que servirá ver cuantas notas tenemos introducidas en el vector
@param double media (por referencia) variable de tipo double que tendrá asignada la media del vector
@param double desviacion (por referencia) variable donde asignaremos la desviación del vector
@param double varianza (por referencia) Variable que utilizaremos àra asignar el valor de la varianza
@RETURN Nada. Es un procedimiento
@post  util se mantendrá igual y desviacion y varianza > 0. 
*/

void CalcularDesviacionVarianza ( int v [], int util_notas,double  media,double &desviacion,double &varianza){

	for (int i=0;i<util_notas;i++){ // bucle para calcular la desviación



		desviacion += (pow(v [i] - media, 2.0)/util_notas); // calculos para obtener la desviación

	}



	varianza= sqrt( desviacion); // calculo necesarios para la varianza

}


/**
@brief Módulo que sirve para dar las salidas del programa.
@pre util > 0.
@param const int VECTOR [] vector constante del que leeremos sus espacios
@param int util. variable de tipo int que utilizaremos para manejar el contenido del vector y saber hasta cuando leer.
@return Las salidas.
@post  El programa imprimirá el vector correctamente.
*/
void salidas (double media, double desviacion, double varianza){





	cout << "Media: "<< media << endl;

	cout << "Desviacion: " << desviacion << endl;

	cout << "Varianza: " << varianza << endl;

}

	

	





int main () {



	const int DIM_NOTAS = 10;

	int notas [DIM_NOTAS] = {0};

	int util_notas = 0;

	double media=0.0, desviacion=0.0, varianza=0.0;






	introducenotas(notas , util_notas);



	cout << RED << "LLEVAS GASTADO " << util_notas << " DE " << DIM_NOTAS << NORMAL << endl; // DEBUG

	CalcularMedia (notas, media, util_notas);

	CalcularDesviacionVarianza ( notas, util_notas, media, desviacion, varianza);

	salidas(media, desviacion, varianza);

}