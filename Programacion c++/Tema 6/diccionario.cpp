#include <iostream>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"



using namespace std;
const int DIM_PALABRAS=1000;
//---------------------------
struct Entrada{
	
	char palabra[40];
	int traduccion;
};
/**
@brief modulo que sirve para añadir a una variable estructuradala palabra
@pre  char palabra[] debe de estar relleno
@param entrada e (por referencia) variable estructuada a la que le rellenaremos el nombre
@param char palabra[] cadena que contendrá el nombre de la entrada
@RETURN Nada. es un procedimiento
@post  e.palabra será igual al vector palabra 
*/
void setPalabra (Entrada &e, char palabra[]){

	int i=0;
	for (i=0; palabra[i] !='\0';i++){

		e.palabra[i]=palabra[i];
	}
	e.palabra[i]='\0';
}
/**
@brief modulo que sirve para añadir a una variable estructuradala el entero que se le asignara a traduccion
@pre  traduccion >=0
@param entrada e (por referencia) variable estructuada a la que le rellenaremos la traduccion
@param int traduccion. variable que llevará asignada el nuero de la traduccion
@RETURN Nada. es un procedimiento
@post  e.traduccion será igual a traduccion 
*/
void setTraduccion (Entrada &e, int traduccion){

	e.traduccion=traduccion;
}
/**
@brief modulo que sirve para devolver la traduccion de una variable estructurada de tipo entrada
@pre  e.entrada>0
@param entrada e (por referencia) variable estructuada de la que devolveremos la traduccion
@RETURN devolveá un entero que tendrá de contenido el numero de traduccion
@post  traduccion será devuelto correctamente 
*/
int getTraduccion (Entrada &e){

	return e.traduccion;
}
/**
@brief modulo que sirve para devolver e.nombre copiandolo en un aux
@pre  char palabra[] debe de estar relleno
@param entrada e (por referencia) variable estructuada a la que le rellenaremos el nombre
@param char aux[] cadena donde se copiara e.nombre
@RETURN Nada. es un procedimiento
@post  aux tendrá asignado el contenido de e.palabra 
*/
void getPalabra (Entrada &e, char aux[]){

	int i=0;
	for (i=0; e.palabra[i] !='\0';i++){

		aux[i]=e.palabra[i];
	}
	aux[i]='\0';
}

//******************
struct Diccionario{

	Entrada ingles[DIM_PALABRAS];
	Entrada espaniol[DIM_PALABRAS];
	int num_entradas;
};
/**
@brief modulo que sirve para añadir a una variable estructurada de tipo diccionario una entrada ingles
@pre e debe de estar rellena
@param Diccionario &d variable de tipo estructurada que rellenaremos;
@param Entrada ingles. variable de tipo Entrada que asignaremos a d.ingles
@RETURN Nada. es un procedimientno
@post  d.ingles será igual que ingles.
*/
void setIngles (Diccionario &d, Entrada ingles, int util_ingles){

	d.ingles[util_ingles]=ingles;
}
/**
@brief modulo que sirve para añadir a una variable estructurada de tipo diccionario una entrada Español
@pre e debe de estar rellena
@param Diccionario &d variable de tipo estructurada que rellenaremos;
@param Entrada espaniol. variable de tipo Entrada que asignaremos a d.espaniol
@RETURN Nada. es un procedimientno
@post  d.espaniol será igual que espaniol.
*/
void setEspaniol (Diccionario &d, Entrada espaniol, int util_espaniol){

	d.espaniol[util_espaniol]=espaniol;
}
/**
@brief modulo que sirve para añadir a una variable estructuradala el entero que se le asignara a num_palabras
@pre  numero >=0
@param Diccionario d (por referencia) variable estructuada a la que le rellenaremos el num_entrada
@param int numero. variable que llevará asignada el nuero de entrada
@RETURN Nada. es un procedimiento
@post d.num_palabras== numero
*/
void setNum_entradas(Diccionario &d, int numero){

	d.num_entradas=numero;
}
/**
@brief modulo que sirve para devolver el num_entradas de una variable estructurada de tipo Diccionario
@pre  d.num_entradas>0
@param Diccionario d (por referencia) variable estructuada de la que devolveremos el num_entradas
@RETURN devolveá un entero que tendrá de contenido el numero de entradas
@post  num_entradas será devuelto correctamente 
*/

int getNum_entradas (const Diccionario d){

	return d.num_entradas;
}
/**
@brief modulo que sirve para devolver d.ingles de una variable estructurada de tipo Diccionario
@pre d.ingles deberá de estar relleno
@param Diccionario &d variable estructurada de tipo diccionario de la cual devolveremos ingles;
@RETURN devolverá una variable de tipo entrada con el conteido de d.ingles
@post  d.ingles será devuelto correctamente.
*/
void getIngles (const Diccionario &d, int i, Entrada &aux){

	aux= d.ingles[i];
}
/**
@brief modulo que sirve para devolver d.espaniol de una variable estructurada de tipo Diccionario
@pre d.espaniol deberá de estar relleno
@param Diccionario &d variable estructurada de tipo diccionario de la cual devolveremos espaniol;
@RETURN devolverá una variable de tipo entrada con el conteido de d.espaniol
@post  d.espaniol será devuelto correctamente.
*/
void getEspaniol (const Diccionario &d, int i, Entrada &aux){

	aux=d.espaniol [i];
}
/**
@brief modulo que sirve para introducir una palabra en el diccionario con su traduccion
@preutil_ingles y util_español deberán de ser mayor que 0 
@param Diccionsrio &1dam variable estructurada de tipo diccionario la cual rellenaremos
@param int utl_ingles variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@param int utl_español variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@RETURN nada. es un procedimiento
@post  la posicion actual del vector ingles y del vector español estará rellena y las utiles valdrá uno mas
*/
void IntroducePalabra (Diccionario &d, int &util_ingles, int &util_espaniol){

	const int DIM=50;

	char aux[DIM]; // cadenas auxiliares que utilizaremos para asignarles los nombres
	char aux1[DIM];
	Entrada espaniol; // entrada que introduciremos en el vector espaniol del struct
	Entrada ingles;// entrada que introduciremos en el vector ingles del struct
	cin.ignore(256, '\n'); // utilizado para que podamos escribir en el cin.getline
	cout << "Introduza su palabra en español: ";
	cin.getline(aux, DIM); 

	setPalabra( espaniol, aux);
	setTraduccion (espaniol, util_espaniol);

	setEspaniol (d, espaniol, util_espaniol);// la util será la posicion donde guardarenos le Entrada. Cada vez que pase por ahí se le sumará 1
	util_espaniol++;

	cin.ignore(256, '\n');

	cout << "Ahora introduzca la traduccion de la palabra ingresada: "<<endl;
	cin.getline(aux1, DIM);
	setPalabra (ingles, aux1);
	setTraduccion (ingles, util_ingles);
	setIngles (d, ingles, util_ingles);// la util será la posicion donde guardarenos le Entrada. Cada vez que pase por ahí se le sumará 1
	util_ingles++;

}
/**
@brief modulo que sirve para imprimir una variable estructurada de tipo Diccionario
@pre util_ingles y util_español deberán de ser > que 0
@param Diccionsrio &d variable estructurada de tipo diccionario la cual imprimiremos
@param int &utl_ingles variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@param int &utl_español variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@RETURN Nada. es un procedimiento
@post  el diccionario se imprimira de manera correcta.
*/

void ImprimeDiccionario ( Diccionario &d, int &util_ingles, int &util_espaniol) {

	const int DIM=50;
	char aux [DIM]; // auxiliar que utilizaremos para copiar e nombre de la entrada
	int traduccion=0;
	char aux1[DIM];// auxiliar que utilizaremos para copiar e nombre de la entrada
	Entrada aux_entrada, aux1_entrada;


	if (util_ingles ==0) { // si la util es igual a 0 o menor será porque 

		cout << "El diccionario esta listo para que empieces a rellenarlo..."<<endl;
	}
	
	else{ 

		for (int i=0; i<util_espaniol; i++){ // bucle para imprimir hasta que llegue a la util
			
			getEspaniol ( d, i, aux_entrada); // copiamos la entrada en la aux				
			getPalabra (aux_entrada, aux); // copiamos el nombre de la entrada en el aux
			traduccion = getTraduccion (aux_entrada); 
			getIngles( d , traduccion, aux1_entrada);// copiamos la entrada en la aux
			getPalabra (aux1_entrada , aux1);// copiamos el nombre de la entrada en el aux

			//imprimimos todas las cadenas
		
			cout << "Español: ";

			for (int i=0; aux[i] != '\0'; i++){

				cout << aux[i];
			}
			cout << endl;
			cout << "Ingles: ";

			for (int i=0; aux1[i] != '\0'; i++){

				cout << aux1[i];
			}
			cout << endl;
		 }
	}
}
/**
@brief modulo que sirve para imprimir una entrada
@pre la entrada debe de estar rellena
@param Diccionario d. Diccionario donde buscaremos la traduccion de la Entrada e
@param const Entrada E. variable que utilizaremos para imprimirla por pantalla
@RETURN nada, es un procedimiento
@post  La entrada se imprimirá correctamente 
*/
void imprimir_traduccion (Diccionario d,  Entrada e){

	char aux[40];
	int posicion=0;//variable que utilizaremos para guardar la pposicion de la traduccion.
	Entrada aux_ingles;

	
	posicion=getTraduccion(e);	// valor que utilizaremos para saber donde está la posicion de la traduccion de la palabra en español
	getIngles(d,posicion, aux_ingles);
	getPalabra(aux_ingles, aux);

	cout << SOLUCION<< "La tradución es: "<<aux<<NORMAL<<endl;
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
@brief modulo que sirve para buscar una palabra en el diccionario y mostrar su traduccion por pantalla
@pre las utiles deberán de ser mayor que 0, si no no hay nada en el diccionario
@param Diccionario d variable que utilizaremos para buscar en ella
@param int &utl_ingles variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@param int &utl_español variable de tipo int que utilzaremos para gestionar el vector de dentro de la vsriable estructurada 
@param char nombre_aux [] cadena de char que tendrá asignado el nombre a buscar
@bool comprobacion (por referencia) bool que utilizaremos para ver si dos cadenas son iguales o no
@RETURN Si la palabra es encontrada devolverá una variable de tipo Entrada, si no mostrará un mensaje de error
@post  si la palabra se esncuentra nos devolverá una variable estructurada de entrada que será una copia de la entrada encontrada, si no imprirá correctamente el mensaje por pantalla
*/

Entrada BuscarTraduccion (Diccionario &d, int &util_ingles, int &util_espaniol, char nombre_aux [], bool &comprobacion){

	
	char cadena [40];
	Entrada aux_espaniol;
	Entrada aux_entrada;
	

	for (int i=0; (i < util_espaniol && !comprobacion); i++){
		getEspaniol(d,i, aux_espaniol);//vamos guardando en aux_espaniol todas las posiciones 
		getPalabra (aux_espaniol, cadena); // copiamos el nombre de la entrada en una cadena para poder compararlo
		comprobacion=ComprobarCadena (cadena, nombre_aux); // comprobamos la cadena y devolvemos un bool
		if (comprobacion){ // si el bool es true, guardaremos la cadena en una auxiliar que despues devolveremos
			getEspaniol(d,i,aux_entrada);		
		}
	}
	
	if (comprobacion){
		return aux_entrada;
	}
	else{
		cout << "Lo sentimos, la palabra no se encuentra disponible..."<<endl;
	}
}
	
/**
@brief modulo que sirve para enseñar un menu y que el usuario pueda elegir sus opciones 
@pre char != e
@param  char &opcion(por referencia) parametro que sirve para ver que opción cogemos.
@param char matriz [] [DIM_COLUMNAS] matriz de tipo char que utiizaremos como tablero.
@param const char jugador1 [] vector que tendrá asignado el nombre del jugador 1
@param const char jugador2 [] vector que tendrá asignado el nombre del jugador 2
@RETURN Nada. es un procedimiento
@post  Mostrará por pantalla el menú correctamente
*/

void menu ( char &opcion, Diccionario &d, int &util_ingles, int &util_espaniol){

	Entrada aux_entrada;
	char nombre_buscar [40];
	bool comprobacion=false;

	cout <<YELLOW<< "---------------------------MENU--------------------------"<<endl;
	cout <<CYAN;
	cout << "Para añadir una entrada pulse e"<<endl;
	cout << "Para imprimir el diccionario, pulse i"<<endl;
	cout << "Para Traducir una palabra, pulse t"<<endl;
	cout << "Para ordenar el diccionario, pulse o"<<endl;
	cout << "Para eliminar una palabra, pulse b"<<endl;
	cout << "Para salir, pulse s"<<endl;
	cout << NORMAL;
	cin >> opcion;

	switch (opcion) { // switch utilizado para el menú
        	case 'e':
			
			IntroducePalabra (d,util_ingles,util_espaniol);

			break;
		case 'i':

			ImprimeDiccionario (d, util_ingles, util_espaniol);

			break;
		case 't':
			cin.ignore(256,'\n');
			cout << "Por favor, introduzca la palabra que desea traducir"<<endl;
			cin.getline(nombre_buscar, 40);
			aux_entrada=BuscarTraduccion (d,util_ingles,util_espaniol, nombre_buscar, comprobacion);
			if (comprobacion){//si comprobacion es true será porque está la palabra buscada, con lo cual imprimios su traduccion
				imprimir_traduccion (d, aux_entrada);
			}
			break;
		case'o':
	
			cout << "Disponible en la version 2.0.."<<endl;
			break;
		case 'b':

			cout << "Disponible en la version 2.0.."<<endl;
			break;
		default:
			break;

	}
}
int main () {
	char opcion;
	Diccionario dam;
	int util_ingles=0;
	int util_espaniol=0;

	do{ // bucle que repetirá el menú hasta que se pulse la tecla s

		menu ( opcion,dam,util_ingles,util_espaniol);

	}while ( opcion !='s');
}	

