ostream>
#include <stdlib.h>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
struct Fecha{
	int dia; // int del 1 al 31
	int mes; // int del 1 al 12
	int anio;// int del 2005 al 9999
};
/**
@brief asigna a la variable estructurada el int día
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructurada a la cual rellenaremos su dia
@param int dia. dia que introduciremos a la variable de tipo fecha
@pre dia deberá de estar entre 1 y 31
@return nada. es un procedimiento
@post 
*/
void setDia (Fecha *ptr, int dia){

	ptr->dia= dia;
}
/**
@brief asigna a la variable estructurada el int mes
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructurada a la cual rellenaremos su mes
@param int mes. mes que introduciremos a la variable de tipo fecha
@pre mes deberá de estar entre 1 y 12
@return nada. es un procedimiento
@post 
*/
void setMes (Fecha *ptr, int mes){

	ptr->mes= mes;
}
/**
@brief asigna a la variable estructurada el int anio
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructurada a la cual rellenaremos su anio
@param int anio. anio que introduciremos a la variable de tipo fecha
@pre anio deberá de estar entre 2005 y 9999
@return nada. es un procedimiento
@post 
*/
void setAnio (Fecha *ptr, int anio){

	ptr->anio= anio;
}
/**
@brief Devuelve por copia el dia de una variable estructurada de tipo fecha.
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructuradaa la cual rellenaremos su dia
@param int dia. dia que introduciremos a la variable de tipo fecha
@pre dia deberá de estar entre 1 y 31
@return devolverá una variable de tipo int con el dia 
@post 
*/
int getDia (const Fecha *ptr){

	return ptr->dia;
}
/**
@brief Devuelve por copia el mes de una variable estructurada de tipo fecha.
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructurada a la cual devolveremos su mes
@pre mes deberá de estar entre 1 y 12
@return devolverá una variable de tipo int con el mes
@post 
*/
int getMes (const Fecha *ptr){

	return ptr->mes;
}
/**
@brief Devuelve por copia el año de una variable estructurada de tipo fecha.
@param fecha *ptr vatisnle de tipo puntero que apunta a la variable estructurada a la cual devolveremos su año
@pre mes deberá de estar entre 1 y 12
@return devolverá una variable de tipo int con el anio
@post 
*/
int getAnio (const Fecha *ptr){

	return ptr->anio;

}



//*****************************//
struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
	Fecha *nacimiento;

};
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
@brief copia la cadena a.nombre de una variable de tipo alumno en un vector aux.
@param alumno  &a. variable de tipo alumno de donde devolveremos el nombre
@param char aux[] vector auxiliar donde copiaremos la cadena de nombre
@pre a deberá de tener un nombre e i deberá de ser >0 y menos que t_nombre
@return nada. es un procedimiento
@post en el vector aux se copiará a.nombre del alumno correctamente
 */

void getNombre( Alumno *ptr, char aux[]){
	int i;	    

	for (i=0; ptr->nombre[i] !='\0'; i++){ // bucle para copiar el nombre en una cadena auxiliar

			aux[i] = ptr ->nombre[i];
	}
	aux[i]='\0';
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
@pre ptr->edad debe de estar relleno
@param Alumno *ptr puntero que apunta a una variable de tipo Alumno
@RETURN Devolverá una variable de tipo unsigned int
@post La edad será devuelta correctamente 
*/
unsigned int getEdad( Alumno *ptr){

    return ptr->edad;
}
/**
@brief modulo que devuelve el nacimiento de una variable structurada de tipo alumno
@pre a->nacimiento debe de estar relleno
@param Alumno a (por referencia) variable de la cual devolveremos su fecha de nacimiento
@RETURN Devolverá una variable de tipo puntero que apuntará a una variable estructurada de tipo Fecha
@post La fecha de nacimiento será devuelta correctamente mediante un puntero
*/
Fecha* getNacimiento ( Alumno *ptr){

	return ptr->nacimiento;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
	@param Alumno *ptr puntero que apunta a una variable de tipo Alumno la cual le asignaremos su variable nombre.
	@param char nombre [] vector que llevará asignado el nombre del alumno.
	@return Nada. es un procedimiento.
	@post ptr->nombre tendrá asignado el nombre del alumno
 */

void setNombre(Alumno *ptr, char nombre[]){
	int i=0;

	for (i=0; nombre[i] != '\0'; i++){ // bucle para copiar el nombre enn una auxiliar

       	 ptr->nombre[i] = nombre[i];
	}
	ptr->nombre[i]= '\0';
}
/**
@brief  módulo que sirve para rellenar una variable nacimiento
@pre la variable de tipo fecha deberá de estar rellena
@param alumno *ptr vaariable de tipo puntero qeu apunta a una variable estructurada de tipo alumno
@param Fecha *f vaariable de tipo puntero qeu apunta a una variable estructurada de tipo fecha

@RETURN  Nada. Es un procedimiento
@post  
*/
void  setNacimiento ( Alumno *ptr, Fecha *f){

	ptr->nacimiento=f;

}
/**
 @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 @pre La edad debe de estar filtrada entre 0 y 120.
 @param Alumno *ptr puntero que apunta a una variable de tipo Alumno a ls que le rellenaremos la edad
 @param unsigned int edad variable que tendrá asignado el valor de la edad del alumno
 @return nada. es un procedimiento
@post ptr->edad deberá de tener asignado el valor de edad
 */

void setEdad(Alumno *ptr, unsigned int edad){

	ptr->edad=edad;

}



/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 	@param Alumno *ptr puntero que apunta a una variable de tipo Alumno de la cual rellenaremos las notas.
 	@param int noras[] vector de tipo int donde estarán las notas de un alumno
 	@return nada. es un procedimiento
 	@post ptr->notas tendrá asignado los valores del vector notas.
 */

void setNotas(Alumno *ptr, int notas[]){

	int util_notas=6;
	for (int i=0;i<util_notas;i++){ // for con el que copiaremos las notas
	
		ptr-> notas [i] = notas[i];
	}
}

/**
@brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
@pre en la matriz asignaturas deberán de estar todos los valores ide los nombres
@param Alumno *ptr puntero que apunta a una variable de tipo Alumno a la que le rellenaremos la asignatura
@param char asignaturas [] [4] matriz que llevará asignada las los nombres de las asignaturas
@return nada. es un procedimiento
@post ptr->nombres_asignatura pasará a tener los valores de las asignaturas
 */
void setNombresAsignaturas(Alumno *ptr, char asignaturas [] [4]){

	for (int f=0; f<6; f++){ // for anidado con el que copiaremos una matriz en el aux
	
		for (int c=0;c<4;c++){
	
			ptr-> nombres_asignaturas [f] [c] = asignaturas [f] [c];
		}
	}
}
/**
@brief modulo que imprime opor pantalla la fecha de nacimiento
@pre fecha deberñá de tener vañloes asignados
@param  Fecha *ptr variable de tipo puntero qeu imprimiremos por pantalla
@RETURN Nada. es un procedimiento
@post   La fecha será imprimida con exito
*/
void printNacimiento (Fecha *ptr){

	cout << "Dia: "<< getDia (ptr)<< " del mes:  "<< getMes(ptr) << "del año: "<< getAnio(ptr)<< endl; 

}
/**
  @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
  @pre la variable estructurada deberá de estar rellena
  @param @param Alumno *ptr puntero que apunta a una variable de tipo Alumno que imprimiremos por pantallaç
  @return nada. es un procedimiento
  @post la variable estructurada de tipo alumno se mostrará por pantala correctamente
 */

void printAlumno( Alumno *ptr){
	const int DIM=31;
	char aux[DIM];

	cout << "Nombre Alumno: ";

	getNombre(ptr,aux);
	/*for (int i=0;aux[i] != '\0';i++){ // bucle para imprimir el nombre copiado anteriormente en un aux
		cout<< aux[i];
	}*/
	
	cout<<aux << endl;
		
    cout << "Edad: " << getEdad(ptr) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++){ // bucle que sirve para imprimir las calificaciones del alumno
        cout << " - " << ptr ->nombres_asignaturas[i] << ": " << ptr->notas[i] << endl;
    }
	printNacimiento (getNacimiento (ptr) );
}
/**
@brief modulo que sirve para crear un puntero dinamico
@pre 
@return si se reserva espacio de memoria, se devolvera un ptr de Alumno
@post o se imprimirá por antalla el mensaje de error, o se devolverá un ptr
*/

Fecha* crearFecha(){

	Fecha *ptr_a=0;
	ptr_a= new Fecha;

	if (ptr_a==0){// si el SO nos devuelve un en espacio de memoria null, abortamos el programa

		cout << "Lo sentimos, no hay memoria... Cerrando....."<<endl;
		exit(-1);
	}
	return ptr_a;
}
/**
@brief modulo que sirve para crear un puntero dinamico
@pre 
@return si se reserva espacio de memoria, se devolvera un ptr de Alumno
@post o se imprimirá por antalla el mensaje de error, o se devolverá un ptr
*/

Alumno* crearAlumno(){

	Alumno *ptr_a=0;
	ptr_a= new Alumno;

	if (ptr_a==0){// si el SO nos devuelve un en espacio de memoria null, abortamos el programa

		cout << "Lo sentimos, no hay memoria... Cerrando....."<<endl;
		exit(-1);
	}
	return ptr_a;
}
/**
@brief modulo que sirve para eliminar una variable estructurada mediante su puntero
@pre la variable estructurada a la que apunta el puntero deberá de estar rellena
@param Fecha *ptr puntero de tipo fecha que nos señalara a la esctructura
@RETURN Nada. es un procedimiento
@post El espacio de memoria será liberado correctamente
*/

void EliminarFecha ( Fecha *ptr){

	setDia(ptr->dia, 0);
	setMes(ptr->mes, 0);
	setAnio(ptr->anio, 0);
	
	delete ptr;
	ptr=0;
}
/**
@brief modulo que sirve para eliminar una variable estructurada mediante su puntero
@pre la variable estructurada a la que apunta el puntero deberá de estar rellena
@param Alumno *ptr puntero de tipo alumno que nos señalara a la esctructura
@RETURN Nada. es un procedimiento
@post El espacio de memoria será liberado correctamente
*/

void EliminarAlumno ( Alumno *ptr){

	int aux_notas[6]={0};
	char asignaturas[6][4] = { {'\0','\0','\0','\0'},{ '\0', '\0', '\0'}, {'\0','\0', '\0'},{'\0','\0','\0'}, {'\0','\0','\0','\0'},{'\0','\0','\0'} };


	setNombre(ptr," ");
	setEdad(ptr, -1);
	setNotas(ptr, aux_notas);
	setNombresAsignaturas(ptr, asignaturas);
	EliminarFecha(ptr->nacimiento);

	delete ptr;
	ptr=0;
}
int main () {

	Alumno *Cristian=0;
	Fecha *Cris=0;
	Alumno *Edu=0;
	Fecha *Eduard=0;
	char nombreedu[31] = {'E','d','u','\0'};
	char nombrecris[31] = {'C','r','i','s','t','i','a','n','\0'};
	int notascristian[6] = {5,6,5,8,6,7};
	char asignaturas[6][4] = { {'P','R','O','\0'},{ 'B', 'D', '\0'}, {'E','D', '\0'},{'S','I','\0'}, {'F','O','L','\0'},{'L','M','\0'} };
	

	Cristian=crearAlumno();
	Cris=crearFecha();
	setNombre(Cristian,nombrecris);
	setEdad(Cristian,20);
	setNotas(Cristian,notascristian);
	setNombresAsignaturas(Cristian,asignaturas);
	setDia (Cris, 22);
	setMes(Cris, 11);
	setAnio(Cris, 1999);
	setNacimiento(Cristian, Cris);
	printAlumno( Cristian);
	//rellenamos la variable a la que apunta el puntero
	Edu=crearAlumno();
	Eduard=crearFecha();
	setNombre(Edu,nombreedu);
	setEdad(Edu,30);
	setNotas(Edu,notascristian);
	setNombresAsignaturas(Edu,asignaturas);
	setDia (Eduard, 22);
	setMes(Eduard, 11);
	setAnio(Eduard, 1999);
	setNacimiento(Edu, Eduard);
	printAlumno( Edu);
	//eliminamos un alumno y comprom¡bamos si esta bien eliminado
	EliminarAlumno(Cristian);
	printAlumno(Cristian);
}