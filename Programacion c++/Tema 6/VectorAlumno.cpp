
#include <iostream>
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
void getNombre( Alumno &a, char aux[]);
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
@brief copia la cadena a.nombre de una variable de tipo alumno en un vector aux.
@param alumno  &a. variable de tipo alumno de donde devolveremos el nombre
@param char aux[] vector auxiliar donde copiaremos la cadena de nombre
@pre a deberá de tener un nombre e i deberá de ser >0 y menos que t_nombre
@return nada. es un procedimiento
@post en el vector aux se copiará a.nombre del alumno correctamente
 */

void getNombre( Alumno &a, char aux[]){
	int i;	    

	for (i=0; a.nombre[i] != '\0'; i++){

			aux[i] = a.nombre[i];
	}
	aux[i]='\0';
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
unsigned int getEdad( Alumno &a){

    return a.edad;
}
/**
@brief  módulo que sirve para rellenar una variable nacimiento
@pre la variable de tipo fecha deberá de estar rellena
@param alumno &a variable estructurada de tipo alumno de la que rellenaremos su fecha de nacimiento
@param Fecha n(por referencia) variable que llevará asignada los valores del dia de nacimiento del alumno

@RETURN  Nada. Es un procedimiento
@post  
*/
void  setNacimiento ( Alumno &a, Fecha &n){

	a.nacimiento=n;

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
@brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
@pre en la matriz asignaturas deberán de estar todos los valores ide los nombres
@param Alumno a (por referencia) variable estructurada a la que le rellenaremos la asignatura
@param char asignaturas [] [4] matriz que llevará asignada las los nombres de las asignaturas
@return nada. es un procedimiento
@post a.nombres_asignatura pasará a tener los valores de las asignaturas
 */
void setNombresAsignaturas(Alumno &a, char asignaturas [] [4]){

	for (int f=0; f<6; f++){ // for anidado con el que copiaremos una matriz en el aux
	
		for (int c=0;c<4;c++){
	
			a.nombres_asignaturas [f] [c] = asignaturas [f] [c];
		}
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
  @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
  @pre la variable estructurada deberá de estar rellena
  @param Alumno &a (por referencia) variable estructurada que imprimiremos por pantallaç
  @return nada. es un procedimiento
  @post la variable estructurada de tipo alumno se mostrará por pantala correctamente
 */
void printAlumno( Alumno &a){
	const int DIM=31;
	char aux[DIM];

    cout << "Nombre Alumno: ";

    getNombre(a,aux);
	for (int i=0;aux[i] != '\0';i++){ // bucle para imprimir el nombre copiado anteriormente en un aux
		cout<< aux[i];
	}
	cout<< endl;
		
    cout << "Edad: " << getEdad(a) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++){ // bucle que sirve para imprimir las calificaciones del alumno
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;
    }
	printNacimiento (a.nacimiento );
}

/**
@brief modulo que sirve para introducir un alumno en un vector de tipo alumno
@pre el espacio de memoria del vector deberá de estar libre y util_clase deberá de ser menor que util_notas
@param Alumno v [], vector al que le introduciremos la variable de tipo alumno
@param int util. Variable que llevará consigo las posiciones ocupadas del vector y la siguiente posición libre
@param Alumno a (por referencia) variable que introduciremos en el vector de alumnos.
@param const int DIM variable que tendrá asignado el tamaño máximo del vector
@RETURN Nada. es un procedimiento 
@post  La util del vector pasrá a vale una más, si está lleno el vector se imprimirá un mensaje por pantalla.
*/

void SetVectorAlumno ( Alumno v[], int &util,const Alumno &a, const int DIM){

	if (util < DIM){

		cout << YELLOW<< "----------- introduciendo vector en el alumno ----------"<< NORMAL<< endl;
		v[util]=a;
		util++;
	}
	else{

		cout << DEBUG << "ERROOOOOOR, ESPACIO OCUPADO"<< endl;
	}
}

/**
@brief módulo que sirve para imprimir un vector de alumnos
@pre el vector de alumnos deberá de estar relleno, siendo la util > que 0
@param const Alumno vector[], vector de tipo Alumno que imprimiremos por pantalla.
@param int util. variable que nos dirá cuantas posiciones del vector tenemos ocupadas y nos servirá para ver hasta cuando imprimimos
@param int tamanio. variable que llevará consigo el tamaño del vector nombre del alumno
@RETURN Nada. es un procedimiento
@post  El vector será imprimido correctamente por pantalla.
*/

void printVector ( Alumno vector[], int util_Vector){

	for (int i=0; i<util_Vector;i++){// bucle que sirve para recorrer todo el vector
	cout << CYAN << "-----Alumno" << i+1 << " --------"<< NORMAL<<endl; // le pasamos cada vez que avanzamos una posición la variable para que la imprima
		printAlumno( vector[i]);
	}
}

/**
@brief módulo que sirve para rellenar una variable de tipo fecha con datos introducidos por el usuario
@pre Fecha f debe de estar vacia
@param Fecha f. será la variable que rellenaremos
@RETURN nada. es un procedimiento.
@post La variable fecha quedará correctamente asignada.
*/
void IntroduceFechaTeclado( Fecha &f){

	int anio=0, dia=0, mes=0;

	cout << "Introduzca el año de nacimiento: ";
	cin >> anio;
	setAnio (f, anio);
	cout << "Introduzca el mes de nacimiento: ";
	cin >> dia;
	setDia (f, dia);
	cout << "Introduzca el dia de nacimiento: ";
	cin>> mes;
	setMes (f,mes);
}

/**
@brief modulo que sirve para rellenar una variable de tipo alumno
@pre la variable estructurada debe de estar vacia
@param 
@RETURN Nada. es un procedimiento
@post La variable estructurada alumno estará correctamente asignada a sus valores pertinentes.
*/

void introduceAlumnoTeclado(Alumno &a){
	Fecha f;
	char nombre [30];
	int edad=0;
	int notas[6] = {5,6,5,8,6,7};
	char asignaturas[6][4] = { {'P','R','O','\0'},{ 'B', 'D', '\0'}, {'E','D', '\0'},{'S','I','\0'}, {'F','O','L','\0'},{'L','M','\0'} };
	
	cout << "Por fvor, digame el nombre del alumno";
	cin.ignore(256, '\n');// sin el cin.ignore no nos deja introducir el segundo nombre
	cin.getline(nombre, 30);
	setNombre ( a, nombre);
	cout << " Ahora, diganos la edad: ";
	cin >> edad;
	setEdad (a, edad);
	setNombresAsignaturas(a,asignaturas);
	IntroduceFechaTeclado(f);
	setNacimiento ( a, f);
	setNotas ( a, notas);
	
}

/**
@brief modulo que sirve para reordenar un vector
@pre el vector deberá de tener una pordición borrada
@param Alumno vector [] vector el cual reordenaremos
@param int util. variable que nos servirá para ver el numero de alumnos que tenemos en nuestra clase.
@param int eliminado. variable que llevará asignada la posicion que ha sido eliminada
@RETURN Nada. es un procedimiento
@post  El vector se reordenará sin la posicion.
*/
void ReordenarVector (Alumno vector [], int &util, int eliminado) {

	for(int i=eliminado; i < util - 1;i++){ // modulo que sirve para eliminar un elemento del vector
		vector[i]=vector[i +1];
	}
	util--;
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

	for (int i=0; i < 6; i++){ // bucle para acumular todas las notas del alumno

		acumulacion += a.notas[i];
	}

	return acumulacion / 6;   
}
/**
@brief modulo que ordena un vector de menor a mayor por el metodo de la burbuja entrada: 5 4 2 salida: 2 4 5.
@pre util_vector tendrá que ser mayor que 0 
@param int vector [] será que vector que ordenaremos.
@param int util_vector variable de tipo int que utilizaremos para manejar el espacio ocupado del vector.
@RETURN Nada. es un procedimiento 
@post  El vector tendrá que estar ordenado de menor a mayor. y la util se deberá de mantener igual
*/

void OrdenacionBurbuja ( Alumno v [], int util_vector){

	bool cambio=true;
	Alumno aux;
	for (int izqda = 0; izqda < util_vector && cambio; izqda++){
			cambio=false;
			for (int i = util_vector-1; i > izqda; i--){
				if (getMediaCalificacionesAlumno(v[i]) < getMediaCalificacionesAlumno(v[i-1]) ){ // utilizamos el método de la burbuja pero con los get nota media para así poder ordenarlos por nota media
					cambio=true;

					aux=v[i];
					v[i]= v[i-1];
					v [i-1]=aux;
			}
		
		}
	}
		
}
/**
@brief modulo que sirve para comparar dos cadenas de char
@pre los vectoress de tipo char deben de estar rellenos
@param const char nombre[] vector que contendrá la primera cadena a comparar
@param const char nombre2 [] vector que contendrá la segunda cadena a comparar
@RETURN devolverá un bool que contendrá true si son iguales o false si no.
@post si las cadenas son iguales habrá un bool true, si no lo son será false.
*/

bool ComprobarCadena (const char nombre[], const char nombre2[]){
	bool iguales=true;

	for (int i=0; nombre[i] != '\0' && iguales; i++){ // reocrreremos el vector hasta encontrar el elemento centinela

		if ( nombre [i] != nombre2[i] ) { // si una posición es distinta un bool se convierte en falso, debido a que ya se ha comprobado que la cadena no es igual 
			iguales=false;
		}
	}
	return iguales;
}
/**
@brief modulo para dar las salidas de una busqueda en un vector de alumnos.
@pre el vector tendrá que haber pasado antes por una busqueda
@param const Alumno vector [] vector el cual imprimiremos en pantalla en caso de que haya algún elemento en el
@param int util. util que nos dirá si el vector está relleno o no
@RETURN Nada. es un procedimiento
@post  se imprimirá por pantalla un mensaje u otro, dependiendo de si el vector tiene algo asignado o no.
*/

void ImprimeBuscado ( Alumno vector [], int util) {

	if (util > 0){ // si util es mayor que 0 es orque hay contenido en el vector, con lo cual imprimimos
		cout << CYAN;
		printVector ( vector, util);
		cout << NORMAL;
	}
	else{

		cout << DEBUG << " No hemos encontrado nada con sus criterios de busqueda..."<<NORMAL<<endl;
	}
}
	
		
/**
@brief modulo que sirve para buscar en un vector de alumnos los alumnos que tengan un nombre en concreto.
@pre util_alumnos deberá de ser mayor que 0 y tendremos que tener un nombre para comprobar
@param const Alumnos vector [] vector en el que realizaremos la busqueda.
@param int util variable que llevaráasignada el numero de espacios ocupados en el vector
@param char nombre[] vector donde tendremos asignado el nombre de la cadena a buscar
@RETURN Nada. es un procedimiento
@post util_aux deberá de ser mayor que 0 si se encuentra algún alumno con el nombre deseado, si no, se mostrará por panralla un mensaje de error.
*/

void BusquedaNombre ( Alumno vector [], int util, const char nombre [] ){
	const int DIM=31;
	char aux_nombre[DIM];
	bool igual=false;	
	Alumno aux[DIM];
	int util_aux=0;	


	for (int i=0;i< util; i++){ // vector que sirve para recorrer todo el vector
		getNombre(vector[i], aux_nombre);
		igual=ComprobarCadena (aux_nombre , nombre );
		if (igual== true){ // si e bool que devuelve comprobar caddena es true, lo añadimos al vector.

			aux[util_aux]=vector[i];
			util_aux++;
		}
	}
	ImprimeBuscado (aux ,util_aux); // imprimimos los resultados
}
/**
@brief modulo que sirve para buscar en un vector de alumnos los alumnos superen una edad
@pre util_alumnos deberá de ser mayor que 0 y tendremos que tener una edad para comprobar
@param const Alumnos vector [] vector en el que realizaremos la busqueda.
@param int util variable que llevaráasignada el numero de espacios ocupados en el vector
@param int edad edad con la cual comprobaremos
@RETURN Nada. es un procedimiento
@post util_aux deberá de ser mayor que 0 si se encuentra algún alumno mayor a la edad deseada, si no, se mostrará por panralla un mensaje de error.
*/

void Busquedaedad ( Alumno vector [], int util, int edad){

	Alumno aux[20];
	int util_aux=0;

	for (int i=0;i< util; i++){ // bucle que utilizaremos para buscar en todo el vector

		if (getEdad(vector[i]) > edad){ // si vector[i] es > edad, lo añadimos en un vector aux

			aux[util_aux]=vector[i];
			util_aux++;
		}
	}

		ImprimeBuscado (aux,util_aux);	// imprimimos los resultados
	
}	
		
int main () {

	const int DIM_MAX=20;
	Alumno clase [DIM_MAX];
	int util_clase=0;
	Alumno aux_nombre[DIM_MAX];
	int util_aux_nombre=0;
	Alumno aux_edad[DIM_MAX];
	int util_aux_edad=0;

	int notas [6]={1,2,3,1,2,4};
	Alumno a;
	int edad=0, eliminado=0;
	char nombre [DIM_MAX];
	for (int i=0; i<3;i++){ // bucle para rellenar 3 alumnos del vector
		introduceAlumnoTeclado(a);
		SetVectorAlumno ( clase, util_clase,a,DIM_MAX);
		if (util_clase==2){
			setNotas( clase [i], notas);
		}
		//InicializacionAlumno(a);
	}
	printVector ( clase, util_clase);
	cout<< " Por favor: diganos el nombre a buscar: ";
	cin >> nombre;
	//realizamos la busqueda por nombre
	BusquedaNombre ( clase, util_clase , nombre);
	cout<< " Por favor: diganos a partir de que edad desea que busquemos: ";
	cin >> edad;	
	//iniciamos la busqueda por edad
	Busquedaedad(clase, util_clase,edad);
	//Ordenamos el vector 
	cout << YELLOW << "------ORDENANDO EL MODULO POR NOTA MEDIA.....------"<<NORMAL<<endl;

	OrdenacionBurbuja( clase,util_clase);
	printVector ( clase, util_clase);
	//eliminamos un elemento del vector
	cout<< " Por favor: diganos la posición que desea eliminar: ";
	cin >> eliminado;	
	ReordenarVector (clase, util_clase, eliminado);
	printVector ( clase, util_clase);
	
}