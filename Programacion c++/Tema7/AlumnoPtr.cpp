#include <iostream>
#include <stdlib.h>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"


using namespace std;
//*****************************//
struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas

};
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
@brief copia la cadena a.nombre de una variable de tipo alumno en un vector aux.
@param alumno  *ptr. variable de tipo puntero que apunta a una variable de tipo Alumno
@param char aux[] vector auxiliar donde copiaremos la cadena de nombre
@pre la variable a la que apunta ptr deberá de tener un nombre e i deberá de ser >0 y menos que t_nombre
@return nada. es un procedimiento
@post en el vector aux se copiará a.nombre del alumno correctamente
 */

void getNombre( Alumno *ptr, char aux[]){
	int i;	    

	for (i=0; ptr->nombre[i] !='\0'; i++){ //bucle para copiar la el nombre en una cadena auxiliar

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
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
	@param Alumno *ptr puntero que apunta a una variable de tipo Alumno la cual le asignaremos su variable nombre.
	@param char nombre [] vector que llevará asignado el nombre del alumno.
	@return Nada. es un procedimiento.
	@post ptr->nombre tendrá asignado el nombre del alumno
 */

void setNombre(Alumno *ptr, char nombre[]){
	int i=0;

	for (i=0; nombre[i] != '\0'; i++){ // bucle para copiar el nombre en el espacio asignado en su variable estructuradaa

       	 ptr->nombre[i] = nombre[i];
	}
	ptr->nombre[i]= '\0';
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
	for (int i=0;i<util_notas;i++){ //bucle para copiar las notas en un vector auxiliar
	
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
}

/**
@brief modulo que sirve para crear un puntero dinamico
@pre rendremos que tener creado una varianle de tipo puntero
@return si se reserva espacio de memoria, se devolvera un ptr de Alumno
@post o se imprimirá por antalla el mensaje de error, o se devolverá un ptr
*/

Alumno* crearAlumno(){

	Alumno *ptr_a=0;
	ptr_a= new Alumno;

	if (ptr_a==0){ // si el SO nos devuelve un en espacio de memoria null, abortamos el programa

		cout << "Lo sentimos, no hay memoria... Cerrando....."<<endl;
		exit(-1);
	}
	return ptr_a;
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

	delete ptr;
	ptr=0;
}

int main () {

	Alumno *Cristian=0;
	Alumno *Edu=0;
	char nombreedu[31] = {'E','d','u','\0'};
	char nombrecris[31] = {'C','r','i','s','t','i','a','n','\0'};
	int notascristian[6] = {5,6,5,8,6,7};
	char asignaturas[6][4] = { {'P','R','O','\0'},{ 'B', 'D', '\0'}, {'E','D', '\0'},{'S','I','\0'}, {'F','O','L','\0'},{'L','M','\0'} };
	

	Cristian=crearAlumno();
	setNombre(Cristian,nombrecris);
	setEdad(Cristian,20);
	setNotas(Cristian,notascristian);
	setNombresAsignaturas(Cristian,asignaturas);
	printAlumno( Cristian);

	Edu=crearAlumno();
	setNombre(Edu,nombreedu);
	setEdad(Edu,30);
	setNotas(Edu,notascristian);
	setNombresAsignaturas(Edu,asignaturas);
	printAlumno( Edu);
	
	EliminarAlumno(Cristian);
	printAlumno(Cristian);
}
