//
//  tipoalumno_plantilla1.cpp
//  
//
//  Created by Jaime Matas Bustos on 13/2/18.
//

#include <iostream>
using namespace std;

struct Fecha{
	int dia; // int del 1 al 31
	int mes; // int del 1 al 12
	int anio;// int del 2005 al 9999
};
/**
@brief asigna a la variable estructurada el int día
@param fecha &a variable de tipo fecha a la cual rellenaremos su dia
@param int dia. dia que introduciremos a la variable de tipo fecha
@pre dia deberá de estar entre 1 y 31
@return nada. es un procedimiento
@post 
*/
void setDia (Fecha &a, int dia){

	a.dia= dia;
}
/**
@brief asigna a la variable estructurada el int mes
@param fecha &a variable de tipo fecha a la cual rellenaremos su mes
@param int mes. mes que introduciremos a la variable de tipo fecha
@pre mes deberá de estar entre 1 y 12
@return nada. es un procedimiento
@post 
*/
void setMes (Fecha &a, int mes){

	a.mes= mes;
}
/**
@brief asigna a la variable estructurada el int anio
@param fecha &a variable de tipo fecha a la cual rellenaremos su anio
@param int anio. anio que introduciremos a la variable de tipo fecha
@pre anio deberá de estar entre 2005 y 9999
@return nada. es un procedimiento
@post 
*/
void setAnio (Fecha &a, int anio){

	a.anio= anio;
}
/**
@brief Devuelve por copia el dia de una variable estructurada de tipo fecha.
@param fecha &a variable de tipo fecha a la cual rellenaremos su dia
@param int dia. dia que introduciremos a la variable de tipo fecha
@pre dia deberá de estar entre 1 y 31
@return devolverá una variable de tipo int con el dia 
@post 
*/
int getDia (const Fecha &a){

	return a.dia;
}
/**
@brief Devuelve por copia el mes de una variable estructurada de tipo fecha.
@param fecha &a variable de tipo fecha a la cual devolveremos su mes
@pre mes deberá de estar entre 1 y 12
@return devolverá una variable de tipo int con el mes
@post 
*/
int getMes (const Fecha &a){

	return a.mes;
}

/**
@brief Devuelve por copia el año de una variable estructurada de tipo fecha.
@param fecha &a variable de tipo fecha a la cual devolveremos su año
@pre mes deberá de estar entre 1 y 12
@return devolverá una variable de tipo int con el anio
@post 
*/
int getAnio (const Fecha &a){

	return a.anio;

}

/***************************************
** Definición del TIPO DE DATO Alumno **
****************************************/
struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
    Fecha nacimiento;
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
char getNombre(Alumno &a);
int getTamanioNombre(Alumno &a);
unsigned int getEdad(Alumno &a);
void setNombre(Alumno &a, char nombre[]);
void setUtilNombre(Alumno &a, int util_nombre);
void setEdad(Alumno &a, unsigned int edad);
void setNotas(Alumno &a, int notas[]);
void setNombresAsignaturas(Alumno &a);
void printAlumno(const Alumno &a);
void intercambiarAlumnos(Alumno &a, Alumno &b);
float calcularMediaCalificacionesAlumno(Alumno &a);


/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
@brief Devuelve por copia una letra de la cadena nombre.
@param alumno  &a. variable de tipo alumno de donde devolveremos el nombre
@param int i. es la posición de la letra que devolveremos
@pre a deberá de tener un nombre e i deberá de ser >0 y menos que t_nombre
@return devolverá una posicion del vector char nombre
@post se devolverá un char
 */

char getNombre(Alumno &a, int i){
	    
	return a.nombre[i];
}


/**
@brief  módulo que sirve para rellenar una variable nacimiento
@pre 
@param alumno &a variable estructurada de tipo alumno de la que rellenaremos su fecha de nacimiento
@param Fecha n(por referencia) variable que llevará asignada los valores del dia de nacimiento del alumno

@RETURN  Nada. Es un procedimiento
@post  
*/
void  setNacimiento ( Alumno &a, Fecha &n){

	a.nacimiento=n;

}
/**
@brief modulo que devuelve el nacimiento de una variable structurada de tipo alumno
@pre a.nacimiento debe de estar relleno
@param Alumno a (por referencia) variable de la cual devolveremos su fecha de nacimiento
@RETURN Devolverá una variable de tio Fecha
@post La fecha de nacimiento será devuelta correctamente 
*/
Fecha getNacimiento ( Alumno &a){

	return a.nacimiento;
}
/**
 * @brief Calcula el tamaño que tiene el nombre de una variable estructurada de tipo Alumno. Para ello contará el número de caracteres totales desde el primero hasta el carácter centinela.
@pre. la variable estructurada a deberá de tener su nombre asignado
@param alumno &a (por referencia) variable estructurada de la que contaremos la longitud de su nombre
@return devolverá un tipo int con la longitud del nombre
@post tamanio >0
 */
int getTamanioNombre(Alumno &a){
	
	int tamanio=0;	    
	
	for(int i=0; a.nombre[i] != '\0'; i++){
		
		tamanio++;
	}
	cout << " TAMAÑOOOOOOOOO: "<< tamanio<< endl;
	
	return tamanio;		
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
@pre a.edad debe de estar relleno
@param Alumno a (por referencia) variable de la cual devolveremos su edad
@RETURN Devolverá una variable de tipo unsigned int
@post La edad será devuelta correctamente 
*/
unsigned int getEdad(Alumno &a){

    return a.edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
	@param Alumno a(por referencia) variable estructurada a la cual le asignaremos su variable nombre.
	@param char nombre [] vector que llevará asignado el nombre del alumno.
	@return Nada. es un procedimiento.
	@post a.nombre tendrá asignado el nombre del alumno
 */
void setNombre(Alumno &a, char nombre[]){

    for(int i=0; i <= 30; i++)
        a.nombre[i] = nombre[i];
}

/**
 @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 @pre La edad debe de estar filtrada entre 0 y 120.
 @param Alumno a (por referencia) variable estructurada a la que le rellenaremos la edad.
 @param unsigned int edad variable que tendrá asignado el valor de la edad del alumno
 @return nada. es un procedimiento
@post a.edad deberá de tener asignado el valor de edad
 */
void setEdad(Alumno &a, unsigned int edad){

	a.edad=edad;

}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 	@ param Alumno a (por referencia) variable de tipo Alumnos de la cual rellenaremos las notas.
 	@param int noras[] vector de tipo int donde estarán las notas de un alumno
 	@return nada. es un procedimiento
 	@post a.notas tendrá asignado los valores del vector notas.
 */
void setNotas(Alumno &a, int notas[]){

	int util_notas=6;
	for (int i=0;i<util_notas;i++){
	
		a.notas [i] = notas[i];
	}
}
/**
@brief modulo que imprime opor pantalla la fecha de nacimiento
@pre fecha deberñá de tener vañloes asignados
@param  Fecha a (porreferencia) vsriable que imprimiremos por pantalla
@RETURN Nada. es un procedimiento
@post   La fecha será imprimida con exito
*/
void printNacimiento (Fecha &a){

	cout << "Dia: "<< getDia (a)<< " del mes:  "<< getMes(a) << "del año: "<< getAnio(a)<< endl; 

}
/**
@brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
@pre en la matriz asignaturas deberán de estar todos los valores ide los nombres
@param Alumno a (por referencia) variable estructurada a la que le rellenaremos la asignatura
@param char asignaturas [] [4] matriz que llevará asignada las los nombres de las asignaturas
@return nada. es un procedimiento
@post a.nombres_asignatura pasará a tener los valores de las asignaturas
 */
void setNombresAsignaturas(Alumno &a, char asignaturas [] [4]){

	for (int f=0; f<6; f++){
	
		for (int c=0;c<4;c++){
	
			a.nombres_asignaturas [f] [c] = asignaturas [f] [c];
		}
	}
}

/**
  @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
  @pre la variable estructurada deberá de estar rellena
  @param Alumno &a (por referencia) variable estructurada que imprimiremos por pantallaç
  @return nada. es un procedimiento
  @post la variable estructurada de tipo alumno se mostrará por pantala correctamente
 */
void printAlumno( Alumno &a, int tamanio){
	char aux;
    //OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    //¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?
    cout << "Nombre Alumno: ";

	for (int i=0;i<tamanio;i++){
		aux= getNombre(a , i);
		cout << aux;
	}
	cout<< endl;
		
    cout << "Edad: " << getEdad(a) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;
	printNacimiento (a.nacimiento );
}

/**
@brief Intercambia el contenido de dos variables de tipo Alumno.
@pre. Las variables deberán de estar rellenas, o al menos una de ellas.
@param alumno a (por referencia) primera variable estructurada que intercambiaremos
@param Alumno b (por referencia) seguna variable estructurada con la que realizaremos el intercambio
@return nada. es un procedimiento
@ post. el valor de b será igual al inicial de a y el de a igual al inicial de b
 */
void intercambiarAlumnos(Alumno &a, Alumno &b){

	Alumno c;// variable de tipo alumno que utilizaremos por referencia

	c=a;
	a=b;
	b=c;
    
}

/**
@brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
@pre a.notas deberá de estar relleno
@param Alumno a (por referencia) variable de la cual calcularemos su nota media.
@return devolverá un float que tendrá asignado la acumulacion obtenida entre 6 (el numero de notas).
@post la variable acumulacion tendrá asignada la suma de todas las notas.
 */
float getMediaCalificacionesAlumno(Alumno &a){

	float acumulacion=0;
	int i=0;

	for (int i=0; i < 6; i++){

		acumulacion += a.notas[i];
	}

	return acumulacion / 6;   
}

int main(){
    Alumno Berrios, Jaime, alumnocopiado;
	Fecha n_berrios, n_jaime;
    char nombreberrios[31] = {'B','e','r','r','i','o','s','\0'};
    int notasberrios[6] = {5,6,5,8,6,7};
	int t_Berrios=0, t_Jaime=0, t_copia;
    char nombrejaime[31] = {'J','a','i','m','e','\0'};
	char nombrecopia[31] = {'P','o','t','e','n','s','i','a','\0'};
    int notasjaime[6] = {5,6,5,7,7,6};
    int media=0;

  char asignaturas[6][4] = { {'P','R','O','\0'},{ 'B', 'D', '\0'}, {'E','D', '\0'},{'S','I','\0'}, {'F','O','L','\0'},{'L','M','\0'} };
	
    
    //Preparo los datos del Alumno Berrios
    setNombre(Berrios, nombreberrios);
	
	t_Berrios=getTamanioNombre(Berrios);	
    setEdad(Berrios, 22);
    setNotas(Berrios, notasberrios);
	setNombresAsignaturas(Berrios,asignaturas);
	setAnio(n_berrios, 1999);
	setMes(n_berrios, 11);
	setDia(n_berrios,22);
	setNacimiento ( Berrios, n_berrios);
    printAlumno(Berrios, t_Berrios);
    
    //Preparo los datos del Alumno Jaime
    setNombre(Jaime, nombrejaime);
	t_Jaime= getTamanioNombre (Jaime);
    setEdad(Jaime, 23);
    setNotas(Jaime, notasjaime);
	setAnio(n_jaime, 1989);
	setMes(n_jaime, 06);
	setDia(n_jaime,15);
	setNacimiento ( Jaime, n_jaime);
	setNombresAsignaturas(Jaime,asignaturas);
    printAlumno(Jaime, t_Jaime);
	
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"

    setNombre(alumnocopiado,nombrecopia);
	t_copia= getTamanioNombre (alumnocopiado);
    printAlumno(alumnocopiado, t_copia);
	setNombresAsignaturas(alumnocopiado,asignaturas);
    
    /*Aquí habría que incluir el código para probar los módulos Intercambiar Alumnos y Calcular Calificaciones Medias*/
    
    // 1) Probamos Intercambiar Alumnos y mostramos por pantalla los alumnos intercambiados.
	intercambiarAlumnos(Jaime, Berrios);
	
	cout << "JAIMEEEEEEEEEEE: "<<endl;	
	printAlumno(Jaime, t_Jaime);

	cout << "BERRIOOOOOOOOOS: "<<endl;	
	printAlumno(Berrios, t_Berrios);
	
    
    // 2) Probamos Calcular Calificación Media de los Alumnos y las mostramos por pantalla.

	media=calcularMediaCalificacionesAlumno(Jaime);
    
	cout << "La media deberia de ser: 6 y es: "<< media << endl;
}
