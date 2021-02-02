#include <iostream>
using namespace std;

struct Time{
	int hora;
	bool am;
	int minuto;
	int segundo;
};

/**
@brief Modulo que sirve para rellenar un struct
@param Time variable (por referencia) variable a la que le asognaremos los valores.
@return Nada. es un procedimiento
@post devolverá una variable de tipo Time con todos sus valores asignados
*/
void poner_hora( Time &variable){

	cout << "Introduzca la hora: ";
	cin >> variable.hora;
	if (variable.hora < 12){
		variable.am=false;
	}
	else{
		variable.am=true;
	}
	cout << "Introduzca los minutos";
	cin >> variable.minuto;
	cout << "Introduzca los segundos";
	cin >> variable.segundo;
}
/**
@brief Modulo que sirve para imprimir un struc
@pre la variable de tipo time tendrá que tener todos los valores asignados
@param Time variable (por referencia) variable que imprimiremos por pantalla
@return Nada. es un procedimiento
@post se imprimirán los valores correctamente
*/
void Imprimir (const Time &variable){

	cout << "son las: " << variable.hora << " hs, " << variable.minuto<< " minutos y " << variable.segundo << " segundos de la ";
	if (variable.am== true){
		cout << " de la tarde."<<endl;
	}
	else{
		cout << " de la mañana" << endl;
	}
}

/**
@brief Modulo que sirve pasar segundos a una variable de tipo Time
@pre segundos >0
@param Time segundos_pasado (por referencia) variable a la que le asignaremos los valores de los segundos en Hora, minuto y segundo
@param int segundos varriable a la que le asignaremos la cantidad de segundos que introducirá el usuario
@return Nada. es un procedimiento
@post los segundos se pasarán rellenando la variable segundo_pasado
*/
void SegundosAtiempo(int segundos, Time &segundo_pasado){

	segundo_pasado.hora=segundos % 3600;
	segundo_pasado.minuto=segundo_pasado.hora % 60;
	segundo_pasado.segundo=segundo_pasado.minuto %60;
	if (segundo_pasado.hora < 12){
		segundo_pasado.am=false;
	}
	else{
		segundo_pasado.am=true;
	}	
}
/**
@brief Modulo que sirve para calcular la diferencia de tiempo entre dos variables de tipo Time
@pre tiempo1 y tiempo2 deberán de estar asignadas a valores
@param const Time tiempo1 1 variable que utilizaremos para calcular la diferencia
@param const Time tiempo2 2 variable que utilizaremos para calcular la diferencia
@param Time diferencia (por referencia) variable a la que le asignaremos la diferencia entre tiempo1 y tiempo2
@return Nada. es un procedimiento
@post diferencia tendrá los valores de la diferencia entre tiempo1 y tiempo2
*/
void DiferenciaTiempo ( const Time tiempo1, const Time tiempo2, Time &diferencia){

	diferencia.hora= tiempo1.hora - tiempo2.hora;
	diferencia.minuto= tiempo1.minuto - tiempo2.minuto;
	diferencia.minuto= tiempo1.segundo - tiempo2.segundo;
}

int main () {

	Time tiempo, segundo_pasado, tiempo2, diferencia;
	int segundos=0;





	poner_hora( tiempo);
	Imprimir ( tiempo);
	cout << "Introduzca los segundos que usted quiere pasar a tiempo real: ";
	cin >> segundos;
	SegundosAtiempo (segundos, segundo_pasado);
	Imprimir (segundo_pasado);
	poner_hora( tiempo2);
	DiferenciaTiempo ( tiempo, tiempo2, diferencia);

	cout << " Hay una diferencia de: " << diferencia.hora << " horas, " << diferencia.minuto << " minutos y " << diferencia.segundo << " segundos"<< endl;

}	
