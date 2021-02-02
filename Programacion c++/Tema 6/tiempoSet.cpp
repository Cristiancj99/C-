#include <iostream>
using namespace std;

struct Time{
	int hora;
	bool am;
	int minuto;
	int segundo;
};
/**
@brief Modulo que sirve para rellenar la hora de una variable
@param Time variable (por referencia) variable a la que le asignaremos la hora
@param int hora. Variable que llevará asignada la hora de una variable estructurada
@return Nada. es un procedimiento
@post t.hora tendrá el valor de hora
*/
void setHora (Time &t, int hora){

	t.hora=hora;

}
/**
@brief Modulo que sirve para rellenar el minuto de una variable
@param Time variable (por referencia) variable a la que le asignaremos el minuto
@param int hora. Variable que llevará asignada los minutos de una variable estructurada
@return Nada. es un procedimiento
@post t.minuto tendrá el valor de minuto
*/
void setMinuto (Time &t, int minuto){

	t.minuto=minuto;

}
/**
@brief Modulo que sirve para rellenar los segundos de una variable
@param Time variable (por referencia) variable a la que le asignaremos los segundos
@param int hora. Variable que llevará asignada los segundos de una variable estructurada
@return Nada. es un procedimiento
@post t.segundo tendrá el valor de segundo
*/
void setSegundo (Time &t, int segundo){

	t.segundo=segundo;

}
/**
@brief Modulo que sirve para devolver la hora de una variable estructurada de tipo Time
@pre t.hora deberá de estar relleno
@param Time variable (por referencia) variable de la que devolveremos la hora 
@return devolverá una vaiable de tipo int que tendrá la hora de la variable estructurada
@post la variable que devolverá será mayor que 0 y menor que 24
*/
int getHora(Time &t){

	return t.hora;

}
/**
@brief Modulo que sirve para rellenar los segundos de una variable
@param Time variable (por referencia) variable a la que le asignaremos el bool am
@return Nada. es un procedimiento
@post t.segundo tendrá el valor de segundo
*/
void setAm (Time &t){

	if (getHora(t) > 12 ){
		t.am=false;
	}
	else{
		t.am=true;
	}
}


/**
@brief Modulo que sirve para devolver los minutos de una variable estructurada de tipo Time
@pre t.minuto deberá de estar relleno
@param Time variable (por referencia) variable de la que devolveremos los minutos 
@return devolverá una vaiable de tipo int que tendrá los minutos de la variable estructurada
@post la variable que devolverá será mayor que 0 y menor que 60
*/
int getMinuto (Time &t){

	return t.minuto;

}
/**
@brief Modulo que sirve para devolver los segundos de una variable estructurada de tipo Time
@pre t.segundo deberá de estar relleno
@param Time variable (por referencia) variable de la que devolveremos los segundos 
@return devolverá una vaiable de tipo int que tendrá los segundos de la variable estructurada
@post la variable que devolverá será mayor que 0 y menor que 60
*/
int getSegundo (Time &t){

	return t.segundo;

}
/**
@brief Modulo que sirve para devolver el valor de am de una variable estructurada de tipo Time
@pre t.am deberá de estar relleno
@param Time variable (por referencia) variable de la que devolveremos am
@return devolverá una vaiable de tipo bool
@post la variable que devolverá será un bool
*/
bool getAm (Time &t){

	return t.am;

}
/**
@brief Modulo que sirve para rellenar un struct
@param Time variable (por referencia) variable a la que le asognaremos los valores.
@return Nada. es un procedimiento
@post devolverá una variable de tipo Time con todos sus valores asignados
*/
void poner_hora( Time &variable){

	int hora=0, minuto=0, segundo=0;

	cout << "Introduzca la hora: ";
	cin >> hora;
	setHora(variable, hora);
	setAm(variable);
	cout << "Introduzca los minutos";
	cin >> minuto;
	setMinuto(variable,minuto);
	cout << "Introduzca los segundos";
	cin >> segundo;
	setSegundo (variable,segundo);
}
/**
@brief Modulo que sirve para imprimir un struc
@pre la variable de tipo time tendrá que tener todos los valores asignados
@param Time variable (por referencia) variable que imprimiremos por pantalla
@return Nada. es un procedimiento
@post se imprimirán los valores correctamente
*/
void Imprimir ( Time &variable){

	cout << "son las: " << getHora (variable) << " hs, " << getMinuto(variable) << " minutos y " << getSegundo(variable) << " segundos de la ";
	if (getAm(variable)== true){
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
void SegundosAtiempo(int segundos, Time &t){

	setSegundo(t, (segundos % 60) );
	segundos=segundos / 60;
	setMinuto (t, (segundos % 60) );
	setHora (t, (segundos % 60) );
	setAm(t);	
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
void DiferenciaTiempo (Time tiempo1, Time tiempo2, Time &t){

	setHora(t, (getHora(tiempo1) - getHora(tiempo2) ) );
	setMinuto(t, (getMinuto(tiempo1) - getMinuto(tiempo2) ) );
	setSegundo(t, (getSegundo(tiempo1) - getSegundo(tiempo2) ) );
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

	cout << " Hay una diferencia de: " << getHora(diferencia) << " horas, " << getMinuto(diferencia) << " minutos y " << getSegundo(diferencia)<< " segundos"<< endl;

}