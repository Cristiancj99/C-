#include <iostream>
#include <stdlib.h>
#include<string>
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"




using namespace std;


// declaracion de los struct


/******************************
 ******************************
*/
struct Foto{

	string ruta; // ruta donde esta el archivo que utilizaremos como ruta
	string tipo;// extension de la foto
	unsigned long int tamanio; // tamanio en bits
};
//**********************************************************************************
/**
@brief modulo que sirve para incluir las lineas de filtro sin necesidad de repetirlas
@pre introducir una variable de un tipo distinto 
@RETURN nada. (es un procesamiento, con lo cual no devolverá nada)
@post el indicador de error será borrado correctamente 
*/
void filtrado(){
	cin.clear();//borra el indicador de error en el cin.
	cin.ignore(256,'\n');//ignora 256 caracteres y el salto de linea
}

//********************************************************************************

/**
@brief modulo que sirve para introducir la ruta a una foto
@param foto f.variable estructurada de tipo foto que rellenaremos 
@param string ruta. variable de tipo string que tendrá asignada la ruta de la imagen
@pre. ruta debe de tener contenido y f.ruta debe de estar vacio
@param nada. es un procedimiento
@post la ruta de la variable estructurada pasará a tener asignado el valor de ruta.
*/

void setRuta (Foto &f, string ruta){

	f.ruta=ruta;

}
/**
@brief modulo que sirve para introducir el tipo de una foto (.png)
@param foto f. variable estructurada de tipo foto que rellenaremos 
@param string tipo. variable de tipo string que tendrá asignada el tipo de la imagen
@pre. tipo debe de tener contenido y f.tipo debe de estar vacio
@param nada. es un procedimiento
@post el tipo de la variable estructurada pasará a tener asignado el valor de tipo.
*/

void setTipo (Foto &f, string tipo){

	f.tipo=tipo;

}

/**
@brief modulo que sirve para introducir el tamaño de una foto en bits
@param foto f. variable estructurada de tipo foto que rellenaremos 
@param int tamanio. variable que llevará asignada el tamanio de la foto
@pre. tamanio deberá de ser mayor que 0 y f.tamanio deberá de estar vacio
@param nada. es un procedimiento
@post el tamanio de la variable estructurada pasará a tener asignado el valor de tamanio.
*/

void setTamanio (Foto &f, int tamanio){

	f.tamanio=tamanio;

}

/**
@brief modulo que sirve para devolver la ruta de un archivo
@param foto f. variable estructurada de tipo foto de la cual devolveremos los datos
@pre. a.ruta deberá de estar relleno
@param devolverá una variable de tipo string con el contenido de la ruta
@post la ruta será devuelta correctamente
*/

string getRuta(const Foto f){

	return f.ruta;

}
/**
@brief modulo que sirve para devolver el tipo  de un archivo
@param foto f. variable estructurada de tipo foto de la cual devolveremos los datos
@pre. a.tipo deberá de estar relleno
@param devolverá una variable de tipo string con el contenido del tipo
@post el tipo será devuelta correctamente
*/

string getTipo (const Foto f){

	return f.tipo;

}

/**
@brief modulo que sirve para devolver el tamanio de una variable estructurada de tipo foto
@param foto f. variable estructurada de tipo foto de la cual devolveremos los datos
@pre. a.tamanio deberá de estar relleno
@param devolverá una variable de tipo unsigned long int con el contenido del tamanio
@post tamanio será devuelta correctamente
*/

unsigned long int getTamanio(const Foto f){

	return f.tamanio;

}

/**
@brief modulo que sirve para imprimir una variable estructurada de tipo foto 
@pre la variable estructurada debe de estar rellena
@param Foto f. variable estructurada que imprimiremos por pantalla
@return nada. es un procedimiento
@post la variable estructurada de tipo Fecha será imprimida correctamente
*/

void ImprimirFoto (const Foto f){

	cout << "ruta del arcchivo: "<<CYAN<< getRuta(f)<<NORMAL << " " <<DEBUG<< getTipo(f) <<NORMAL<<endl;
	cout << "espacio ocupado en la BD: "<<YELLOW<<getTamanio(f)<<NORMAL<<endl;

}
/**
@brief modulo que sirve para imprimir laa ruta de una variable de tipo foto
@pre la variable estructurada debe de estar rellena
@param Foto f. variable estructurada de la cual imprimiremos la ruta
@return nada. es un procedimiento
@post la ruta de la variable estructurada de tipo Fecha será imprimida correctamente
*/

void imprimirRuta( const string ruta){

	cout <<SOLUCION<<"Ruta que coincide: "<< ruta<< NORMAL<<endl;
}

/**
@brief modulo que sirve para hacer un vector de fotos dinamico
@pre el vector debe de estar creado previamente
@return devolverá un puntero de tipo foto dinamico que será un vector
@post si hay espacio en el heap se devolverá correctamente, si no lo hay se dmostrará un mensaje de error y finalizará el código
*/
Foto* CrearVectorFotos (int dim){

	Foto*f=new Foto [dim];

	if (f==0){
		cout << DEBUG<< "Lo siento, no hay espacio..."<<NORMAL<<endl;
		exit(-1);
	}
	
	return f;
}


/**
@brief módulo que sirve para eliminar una foto reseteando sus valores.
@param Foto f. variable estructurada de tipo foto que resetearemos.
@pre la variable estructurada debe de estar rellena
@return Nada. es un procedimiento
@post. la variable estará reseteada correctamente.
*/

void EliminarFoto (Foto &f){
// resetearemos las variables haciendo los respectivos set con valores vacios o 0.

	setRuta(f, " ");
	setTipo(f, " ");
	setTamanio (f, 0);
// al no ser una variaable dinámica no deberemos de hacer el delete

}



/******************************
 ******************************
*/

struct  Usuario{

	string login; //unique
	string nombre; // nombre del usuario
	string apellido; // apellido del usuario
	string perfil_usuario; // nombre del perfil
	string localidad;// localidad del usuario (flipada)
	int visitas;//numero de visitas que tiene un usuario (flipada)
	Foto* v_fotos; //vector dinamico de panojitos
	int dim_vfotos; // dimension del vector v_fotos
	int TotalFotosUsuario; // utiles del vector de v_fotos

};

/**
@brief modulo que sirve para introducir un login a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param string login. string que utilizaremos para asignar el valor del login
@pre. el login debe de estar relleno y login de la variable estructurada debe de estar libre
@param nada. es un procedimiento
@post el login de la variable estructurada pasará a tener asignado el valor de login.
*/

void setLogin (Usuario *u, string login){

	u->login=login;
}
/**
@brief modulo que sirve para introducir un nombre a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param string nombre. string que utilizaremos para asignar el valor del nombre
@pre. el nombre debe de estar relleno y nombre de la variable estructurada debe de estar libre
@param nada. es un procedimiento
@post el nombre de la variable estructurada pasará a tener asignado el valor de nombre.
*/

void setNombre (Usuario *u, string nombre){

	u->nombre=nombre;

}


/**
@brief modulo que sirve para introducir el apellido a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param string apellido. string que utilizaremos para asignar el valor del apellido
@pre. el apellido debe de estar relleno y apellido de la variable estructurada debe de estar libre
@param nada. es un procedimiento
@post el apellido de la variable estructurada pasará a tener asignado el valor de apellido.
*/

void setApellido (Usuario *u, string apellido){

	u->apellido=apellido;

}
/**
@brief modulo que sirve para introducir el nombre del usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param string nombre_usuario. string que utilizaremos para asignar el valor del nombre_usuairo
@pre. el nombre_usuario debe de estar relleno y nombre_usuario de la variable estructurada debe de estar libre
@param nada. es un procedimiento
@post el nombre_usuario de la variable estructurada pasará a tener asignado el valor de nombre_usuario.
*/

void setPerfil_usuario (Usuario *u, string nombre_usuario){

	u->perfil_usuario=nombre_usuario;

}
/*********************************************/
		//flipada
/********************************************/
/**
@brief modulo que sirve para introducir la localidad a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param string localidad. string que utilizaremos para asignar el valor de localidad
@pre. la localidad debe de estar relleno y localidad de la variable estructurada debe de estar libre
@param nada. es un procedimiento
@post la localidad de la variable estructurada pasará a tener asignado el valor de localidad.
*/

void setLocalidad (Usuario *u, string localidad){

	u->localidad=localidad;

}
/**
@brief modulo que sirve para introducir el numero de visitas a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param int visitas. variable de tipo int que llevará asignado el numero de visitas
@pre. visitas será siempre mayor que 0
@param nada. es un procedimiento
@post las visitas del usuario serán aumentadas correctamente 
*/

void setVisitas (Usuario *u, int visitas){

	u->visitas=visitas;

}
/***************************************************/
		//fin flipada
/***************************************************/
/**
@brief modulo que sirve para añadir una nueva direccion de memoria al vector de foto
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param Fotos *f puntero qeu lleva la direccion de memoria que le asignaremos al usuario
@param nada. es un procedimiento
@post v_fotos pasará a tener la direccion de memoria de f
*/

void setV_fotos (Usuario *u, Foto *f){

	u->v_fotos=f;

}
/**
@brief modulo que sirve para introducir la dimension de un vector de imagenes a un usuario. esto servirá para cuando redimensionemos. inicialmente será 5 e irá aumentando de 5 en 5
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param int dim_fotos. dimension del vector de fotos del usuario
@pre. dim_foto siempre será mayor que 0 y será multiplo de 5. SE LLAMARÁ CUANDO SE NECISTE REDIMENSIONAR EL VECTOR!!
@param nada. es un procedimiento
@post la dimension del vector será auentada correctamente
*/

void setDim_vfotos (Usuario *u, int dim_fotos){

	u->dim_vfotos=dim_fotos;

}
/**
@brief modulo que sirve para introducir la util del vector del usuario (TotalFotosUsuario). 
@param Usuario *u puntero que apunta a la variable de tipo Usuario que rellenaremos
@param int util. variable que llevará asignada el valor de la útil del vector
@pre. util será > 0 y < que la dimension del vector.
@retun nada. es un procedimiento
@post la util del vector de fotos se actualizará correctamente
*/

void setTotalFotosUsuario (Usuario *u, int util){

	u->TotalFotosUsuario=util;

}

/**
@brief modulo que sirve para devolver el login de un usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre el usuario deberá de tener un login asignado
@return devolverá una variable de tipo string 
@post el login será devuelto correctamente
*/
string getLogin (const Usuario *u){

	return u->login;

}
/**
@brief modulo que sirve para devolver el nombre de un usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre el usuario deberá de tener un nombre asignado
@return devolverá una variable de tipo string 
@post el nombre será devuelto correctamente
*/
string getNombre (const Usuario *u){

	return u->nombre;

}
/**
@brief modulo que sirve para devolver el apellido de un usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre el usuario deberá de tener un apellido asignado
@return devolverá una variable de tipo string 
@post el apellido será devuelto correctamente
*/
string getApellido (const Usuario *u){

	return u->apellido;

}
/**
@brief modulo que sirve para devolver el perfil del usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre el usuario deberá de tener un perfilusuario asignado
@return devolverá una variable de tipo string 
@post el perfilusuario será devuelto correctamente
*/
string getPerfilUsuario (const Usuario *u){

	return u->perfil_usuario;

}
/*********************************************/
		//flipada
/********************************************/
/**
@brief modulo que sirve para devolver la localidad del usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre el usuario deberá de tener una localidad asignada
@return devolverá una variable de tipo string 
@post la localidad será devuelto correctamente
*/
string getLocalidad (Usuario *u){

	return u->localidad;

}
/**
@brief modulo que sirve para devolver el numero de visitas a un usuario
@param Usuario *u puntero que apunta a la variable de tipo Usuario de la cual devolveremos sus valores
@pre. u->visitas deberá de estar relleno
@param devolvera una variable de tipo int que tendrá asignada el valor de las visitas
@post las visitas del usuario serán devueltas correctamente
*/

int getVisitas (Usuario *u){

	return u->visitas;

}
/***************************************************/
		//fin flipada
/***************************************************/
/**
@brief modulo que devuelve una imagen del vector de fotos de un alumno
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@param int i. variable de tipo int que llevará la posicion del vector que queremos devolver
@pre totalFotosUsuario deberá de ser mayor que 0
@return devolverá una variable estructurada de tipo foto  
@post la foto será devuelta correctamente
*/
Foto getFoto (const Usuario *u, int i){

	return u->v_fotos[i];

}
/**
@brief modulo que devuelve la dimension del vector de fotos de un usuario
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre dim_vfotos deberá de ser mayor que 0
@return devolverá una variable estructurada de tipo int 
@post la dimension será devuelta correctamente
*/
int getDim_vfotos (const Usuario *u){

	return u->dim_vfotos;

}

/**
@brief modulo que devuelve la util del vector de fotos de un alumno (TotalFotosUsuario)
@param Usuario *u puntero que aopunta a la variable estructurada de tipo Alumno
@pre TotalFotosUsuario deberá de ser mayor que 0
@return devolverá una variable estructurada de tipo int 
@post la "util" será devuelta correctamente
*/
int getTotalFotosUsuario (const Usuario *u){

	return u->TotalFotosUsuario;

}
/**
@brief modulo que sirve para redimensionar el vector de fotos. en este caso solo aumentará.
@param usuario *u usuario del cual aumentaremos su vector de fotos
@pre el vector de fotos debe de tener su espacio agotado
@return devolvera un puntero que de fotos dinamico
@post el vector aumentara su dimension 5 mas.
*/
Foto* resizeFotos (Foto *u, int &util_actual, int dim_actual,  int dim_nueva){


    	Foto *dinamico_aux=new Foto [dim_nueva];

	 if (dim_actual < dim_nueva){ // caso de que la dimension nueva sea mayor que la dimension actual.
		cout << "su vector nuevo es mayor que el anterior, con lo cual no hay problema."<<endl;

		for (int i=0; i<util_actual;i++){ // copiamos todo el contenido del vector en el auxiliar
			dinamico_aux[i]=u[i];
   		}
		cout << "cambio realizado"<<endl;
	}  

	delete []u;// borramos el vector dinámico antiguo 
	u=0;// hacemos que el vector dinamico apunte a null
	return dinamico_aux;

}


/**
@brief modulo que sirve para eliminar una foto al usuario de su vector dinámmico
@param Usuario *u puntero que apunta a la variable estructurada de tipo Usuario a la que le asignaremos la foto
@paraam int i. variable que llevará asignada la posicion que queremos borrar
@pre la util deberá de ser mayor que 0, si no, no hay nada que borrar 
@return nada. es un procedimiento
@post la foto será eliminada del vector y reordenado
*/
void EliminarFotoVector (Usuario *u, int i){

	cout<<DEBUG<<"borrando foto..."<<NORMAL<<endl;

	u->v_fotos[i]=u->v_fotos[getTotalFotosUsuario(u)-1];// hacemos un intercambio entre la posicion que queremos borrar y la ultima del vector
	setTotalFotosUsuario(u, getTotalFotosUsuario(u)-1);// reducimos la util	
		cout<<SOLUCION<<"Foto borrada con exito!!"<<NORMAL<<endl;
}


void insertarFotoenUsuario (Usuario *u, Foto f){

	int aux_util=getTotalFotosUsuario(u);

	if ( (getDim_vfotos(u) > getTotalFotosUsuario (u) ) ){ // si la util no es mayor que la dimension siginica que aún queda espacio, así que no habrá problema

		u->v_fotos [getTotalFotosUsuario (u)] = f;
		setTotalFotosUsuario (u, getTotalFotosUsuario (u) +1);
	}

	else { // si la util es igual o mayor que la dimension, vamos a ampliar 5 posiciones el vector 

		setV_fotos(u, resizeFotos (u->v_fotos, aux_util, getDim_vfotos(u),  getDim_vfotos(u)+1) );// aqui debería de hacer el set
		u->v_fotos [aux_util] = f;// asignamos a la siguinte posicion la foto
		setTotalFotosUsuario (u, aux_util +1);// actualizamos la util
		setDim_vfotos(u, getDim_vfotos(u)+5); // actualizamos la dimension
	
	}
}


/**
@brief modulo que sirve para imprimir un usuario mediante su puntero
@pre la variable a la que apunta el puntero debe de estar rellena para poder imprimirla
@param Usuario *u variable de tipo punturo que apunta a la variable de tipo usuario que queremos imprimir
@return nada. es un procedimiento
@post la variable estructurada de tipo Alumno será imprimida correctamente
*/

void ImprimirUsuario ( Usuario *u){

	char opcion=0;

	cout <<CYAN<< "Nombre de Login: "<<NORMAL<< getLogin(u)<<endl;
	cout <<CYAN<< " Nombre real y apellidos: " <<NORMAL<< getNombre(u) << " " << getApellido(u) << endl;
	cout <<CYAN<< "perfil del usuario: "<<NORMAL<< getPerfilUsuario (u)<< endl;
	cout <<DEBUG<<"Localidad: "<<getLocalidad(u)<<NORMAL<<endl;//flipada
	cout<<DEBUG<<"Numero de visitas: "<<getVisitas(u)<<NORMAL<<endl;//flipada
	cout << "Fotos: "<<endl;

	do{
		cout << "Si quiere ver las fotos del usuario, pulse 's', si no las quiere ver, pulse 'n' "<< endl;
		cin>> opcion;
	}while( (opcion != 's') && (opcion != 'n') ); // flitro para que seleccione una opcion si o si

	if (opcion=='s'){ // si selecciona la s se le mostrarán las fotos
	
		 if (getTotalFotosUsuario(u) >0){// si la util es mayor que 0 hay fotos
			for (int i=0;i<getTotalFotosUsuario (u);i++){
			
			ImprimirFoto(getFoto(u, i) );
			}
		}
		if (getTotalFotosUsuario(u) ==0){ // si la util es 0 aun no hay fotos
			cout <<DEBUG<< "Lo siento, el usuario aun no tiene fotos..."<<NORMAL<<endl;
		}
	}

}

/**
@brief modulo que sirve para imprimir el login de un usuario
@pre el login deberá de estar relleno
@param Usuario *u variable de tipo punturo que apunta a la variable de tipo usuario que queremos imprimir el login
@return nada. es un procedimiento.
@post el login se imprimirá correctamente
*/

void ImprimirLogin(Usuario *u){

	cout <<CYAN<< "Nombre de Login: "<<NORMAL<< getLogin(u)<<endl;

}

/**
@brief modulo que sirve para imprimir todas las fotos de un usuario
@pre TotalFotosUsuariodebe de ser >0.
@param Usuario *u variable de tipo punturo que apunta a la variable de tipo usuario que imprimiremos sus fotos
@return nada. es un procedimiento
@post las fotos se imprimirán correctamente
*/

void ImprimirFotosUsuario (Usuario *u){

		 if (getTotalFotosUsuario(u) >0){// si totalfotosusuario es mayor que 0 significa que hay fotos
			for (int i=0;i<getTotalFotosUsuario (u);i++){
				cout <<CYAN <<"Foto "<<i<<" : "<<NORMAL;
				ImprimirFoto(getFoto(u, i) );
			}
		}
		if (getTotalFotosUsuario(u) ==0){ // si es igual significa que no las hay
			cout <<DEBUG<< "Lo siento, el usuario aun no tiene fotos..."<<NORMAL<<endl;
		}
}

/**
@brief modulo que sirve para hacer una variable de tipo Usuario dinamico 
@return devolverá una variable de tipo puntero que apuntará al heap.
@post el puntero apuntará al heap si hay espacio  a null si no lo hay, en caso de que no haya se terminará el programa

*/
Usuario* CrearUsuario (){
	int dim=5;

	Usuario *nuevo=new Usuario;

	if (nuevo==0){

		cout <<DEBUG<< "error inesperado.. no hay suficiente memoria"<<NORMAL<<endl;
		exit(-1);
	}
	

	nuevo->v_fotos=CrearVectorFotos (dim); //hacemos el vector de fotos dinamico.
	setDim_vfotos( nuevo, dim);
	setTotalFotosUsuario(nuevo,0);
	setVisitas(nuevo, 0);
	

	return nuevo;
}

/**
@brief modulo que sirve para eliminar una variable de tipo usuario
@param Usuario*u variable que eliminaremos
@pre la variable estructurada deberá de estar rellena
@return devolverá una direccion de memoria de tipo usuario apuntando a null
@post la variable será eliminada y el espacio de memoria estará liberado.
*/

Usuario* EliminaUsuario (Usuario *u){

	// reseteamos todos los componentes del struct
	cout <<DEBUG<< "ELIMINANDO USUARIO....."<<NORMAL<<endl;
	setNombre (u," ");
	setLogin (u," ");
	setApellido(u," ");
	setPerfil_usuario(u," ");
	setLocalidad(u," ");
	//cout <<DEBUG<< "ELIMINANDO USUARIO antes de eliminar las fotos....."<<NORMAL<<endl;
	for (int i=0;i<getTotalFotosUsuario (u);i++){ // bucle para resetear todas las fotos de un usuario 

		EliminarFoto(u->v_fotos[i] );
	}
	
	//cout <<"despues de bocle fotos"<<endl;
	delete [] u->v_fotos; // una vez reseteadas, eliminamos el vector del heap
	//cout<<"despues de eliminar el vector de fotos"<<endl;
	u->v_fotos=0;
	setTotalFotosUsuario(u, 0);
	setDim_vfotos(u, 0);
	delete u; // una vez reseteados todos los componentes liberamos la memoria en el heap
	u=0;//una vez liberada la memoria, damos una direccion nula a la variable de tipo puntero
	cout << SOLUCION<<"Alumno eliminado correctamente"<<NORMAL<<endl;

	return u;
}		

/******************************
 ******************************
*/

struct TablaUsuarios{

	Usuario**  punteroapuntero; // vector dinámico de punteros
	int totaltuplas; // nunca podrá ser negativo.
	// siempre tiene que coincidir el tamaño y las utiles!!!!!!
};
/**
@brief modulo que sirve para hacer dinamico el vector punteroapuntero del struct TablaUsuarios
@param int dim. dimension del vector de punteroapuntero
@pre. dim tiene que ser exactamente igual a la util y a la dimension del vector!!
@return devolverá en el caso de que haya espacio en el heap un puntero a puntero que apunte al heap
@post si hay espacio en el heap devolverá un puntero a puntero, si no, finalizará la ejecucion del programa
*/

Usuario** PunteroapunteroDinamico ( int dim){

	Usuario **u=new Usuario*[dim];

	if (u==0){
		cout << DEBUG<< "Lo siento, no hay espacio..."<<NORMAL<<endl;
		exit(-1);
	}
	
	return u;
}
/**
@brief modulo que sirve para redimensionar un vector de usuarios
@pre el vector tiene que tener todo el espacio de memoria ocupado
@param Usuario **u vector que redimensionaremos
@param int util _actual (por referencia) variable que nos dirá las posiciones ocupadas del actual vector
@param int dim_actual dimension actual del vector
@param int dim_nueva dimension nueva que queremos introducir en el vector
@return devolverá un puntero a puntero con dimension de dim_nueva
@post el vector que se devolverá es un vector con la dimension nueva y sustituirá al anterior
*/
Usuario** resize(Usuario **u, int &util_actual, int dim_actual,  int dim_nueva){


    	Usuario **dinamico_aux=PunteroapunteroDinamico ( dim_nueva); 
	cout <<"dinamico creado.."<<endl;

	//cout<< DEBUG << util_actual<<dim_actual<<dim_nueva<<NORMAL<<endl;

	if (dim_nueva==dim_actual){// caso de que las dimensiones sean iguales

		dinamico_aux=u;
	}


	else if (dim_actual > dim_nueva){ //caso de que el nuevo vector es menor

		if (util_actual<=dim_nueva){ // si la fimension nueva es menor que la util actual, no hay problema, ya que podemos copiar sin problemas de espacio
			cout << "su vector nuevo es menor que el anterior pero caben sus contenidos sin problema."<<endl;
		
			for (int i=0;i<util_actual;i++){
				dinamico_aux[i]=u[i];
	
   		 	}
			cout << "cambio realizado"<<endl;
		}	

		else{ // caso de que la util sea mayor que la dimension nueva (en este caso no hace faly¡ta borrar basura porque lo hemos borrado previamente
			cout << "su vector nuevo es menor que el anterior pero no caben sus contenidos."<<endl;
			for (int i=0;i<dim_nueva;i++){
				dinamico_aux[i]=u[i];
			}
			//cout <<CYAN<<"Impresion despues de copiar en el aux"<<endl;

			//cout <<DEBUG<< "esta es la util actual en el resize "<< util_actual<<NORMAL<<endl;
			//cout << util_actual<<endl;
		}
	}

	else if (dim_actual < dim_nueva){ // caso de que la dimension nueva sea mayor que la dimension actual.
		cout << "su vector nuevo es mayor que el anterior, con lo cual no hay problema."<<endl;

		for (int i=0; i<util_actual;i++){
			dinamico_aux[i]=u[i];
   		}
		cout << "cambio realizado"<<endl;
	}  

	delete []u;// borramos el antiguo vector dinámico
	u=0;//hacemos que el vector (que ya no es dinamico) apunte a null

	util_actual=dim_nueva;

    return dinamico_aux;
}







/**
@brief modulo que sirve para asignar al vector punteroapuntero otra direccion de memoria
@param TablaUsuarios t variable estructurada de tipo TablaUsuarios la cual rellenaremos
@param Usuario ** u variable de tipo punteroapuntero que asignaremos a t.punteroapuntro
@returrn nada. es un procedimiento
@post t.punteroapuntero tendrá la direccion de u
*/
void setPunteroapuntero (TablaUsuarios &t, Usuario **u){

	t.punteroapuntero=u;
}

/**
@brief modulo que sirve para rellenar la util/dimension(totaltuplas) de una variable estructuada de tipo TablaUsuarios
@param TablaUsuarios t variable estructurada de tipo TablaUsuarios la cual rellenaremos
@param int util variable que llevará consigo el totaltuplas que existe
@pre util>0
@returrn nada. es un procedimiento
@post el valor de totaltuplas será igual a util
*/
void setTotaltuplas (TablaUsuarios &t, int util){

	t.totaltuplas=util;
}
 


/**
@brief modulo que devuelve un puntero del vector punteroapuntero 
@param TablaUsuarios t variable estructurada de tipo TablaUsuarios de la cual obtendremos los datos
@param int i. variable de tipo int que llevará la posicion del vector que queremos devolver
@pre totaltuplas deberá de ser mayor o igual que 0
@return devolverá un puntero que apunta a una variable estructurada del tipo TablaUsuarios 
@post la "tupla" será devuelta correctamente
*/
Usuario* getUsuarios (const TablaUsuarios t, int i){

	return t.punteroapuntero[i];

}
/**
@brief modulo que devuelve la util del vector de punteroapunter de una tabladealumnos (Totaltuplas)
@param TablaUsuarios t variable estructurada de tipo TablaUsuarios de la cual obtendremos los datos
@pre Totaltuplas deberá de ser mayor que 0
@return devolverá una variable de tipo int 
@post la "util" será devuelta correctamente
*/
int getTotaltuplas (const TablaUsuarios t){

	return t.totaltuplas;

}

/**
@brief modulo que sirve para devolver la direccion de memoria de punteroapuntero
@param Tabla t. variable que devolveremos su direccion de memoria
@pre t.punteroapuntero debe de estar apuntando a unas posiciones correctamente
@return Usuario ** devolvera una direccion de memoria
@pre la direccion de memoria que contiene t.punteroapuntero será devuelto correctamente
*/

Usuario ** getPunteroapuntero (const TablaUsuarios t){

	return t.punteroapuntero;
}

/**
@brief modulo que sirve para introducir un Usuario en punteroapuntero de una variable structurada de tipo TablaUsuario
@param TablaUsuario t tabla a la que le asignaremos el Usuario
@param Usuario u. Variable estructurada de tipo que introduciremos en el vector punteroapuntero
@return Nada. es un procedimiento
@post la variable de tipo usuario quedará asignada en el vector de punteros.
 */

Usuario** InsertarUsuarioEnTabla (TablaUsuarios &t, Usuario*u){
	
	Usuario ** aux=new Usuario*[getTotaltuplas(t)];

	int util_dim=getTotaltuplas(t);
	cout <<"redimensionando...."<<endl;
	aux=resize(t.punteroapuntero/*hacer el get*/, util_dim, util_dim, util_dim+1);
	cout << "insertando usuario...."<<endl;
	aux[getTotaltuplas(t)]=u;
	cout << "insertando usuario...."<<endl;
	setTotaltuplas(t, getTotaltuplas(t)+1);

	cout <<DEBUG<<"util despues de insertar"<<getTotaltuplas(t)<<NORMAL<<endl;

	return aux;

}

/**
@brief modulo que sirve para asignar valor a una posicioin de punteroapuntero
@param TablaUsuarios t variable que utilizaremos para rellenar la posicion de punteroapuntero
@param int posicion variable que llevará asignada la posicion que queremos asignar
@param Usuario*u puntero que introduciremos en una posicion del vector
@pre totaltuplas de la variable debe de ser >0
@return nada. es un procedimiento
@post la variable de tipo puntero de usuario estará introducida en la posicion del vector correspondiente
*/
void InsertarUsuarioEnPosicionExistente(TablaUsuarios &t, int posicion, Usuario *u){

	t.punteroapuntero[posicion]=u;
}

/**
@brief modulo que sirve para crear una tabla de usuarios
@param TablaUusario &t (por referencia) variable la cual haremos dinamica y meteremos uns ejemplos iniciales.
@pre totaltuplas deberá de ser igual a 0.
@return nada. es un procedimiento
@post la variable estructurada pasará a tener en su interior un puntero a puntero dinámico y tendrá alfunos ejemplos dentro
*/

void crearTablaUsuario (TablaUsuarios &t){
	Usuario *christian;
	Usuario *antonio;
	Usuario *edu;
	Usuario *jaime;
	Usuario *arturo;
	Usuario *adri;
	Usuario *carlos;
	Foto fantonio, foto1, foto2, foto3, foto5;
	int tamanio=400000;

	setTotaltuplas(t, 0);
	cout << DEBUG<<getTotaltuplas(t)<<NORMAL<<endl;
	
	//cout <<"antes de hacer el puntero dinámico"<<endl;		
	setPunteroapuntero(t, PunteroapunteroDinamico(getTotaltuplas(t) ) ); // le pasamos 0 porque ahora mismo no tiene ninguna tupla en su interior

	//cout << "despues de hacer el puntero dinamico"<<endl;
	setRuta(fantonio, "home desktop programacion dd");
	setTipo(fantonio, ".png");
	setTamanio (fantonio, tamanio);

	
	
//rellenamos e introducimo usuario de prueba
	antonio=CrearUsuario ();
	setNombre(antonio, "antonio");
	setLogin(antonio, "tony el gordo");
	setApellido(antonio, "martinez");
	setPerfil_usuario (antonio, "sicario");
	setLocalidad(antonio, "Granada");
	setVisitas (antonio, 231);
	insertarFotoenUsuario(antonio, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, antonio) );
//rellenamos e introducimo usuario de prueba

	christian=CrearUsuario ();
	setNombre(christian, "cristian");
	setLogin(christian, "cristiancj99");
	setApellido(christian, "Campos");
	setPerfil_usuario (christian, "programador menos que junior");
	setLocalidad(christian, "Granada");
	setVisitas (christian, 100);
	insertarFotoenUsuario(christian, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, christian) );

	setRuta(foto1, "home desktop foto1");
	setTipo(fantonio, ".JPEG");
	setTamanio (foto1, tamanio);

	setRuta(foto2, "home desktop/fotos/ds");
	setTipo(foto2, ".png");
	setTamanio (foto2, tamanio);

	setRuta(foto3, "home desktop/imagen");
	setTipo(fantonio, ".JPEG");
	setTamanio (foto3, tamanio);

	setRuta(foto5, "home/imagen");
	setTipo(fantonio, ".png");
	setTamanio (foto5, tamanio);

	insertarFotoenUsuario(christian, foto1);
	insertarFotoenUsuario(christian, foto2);
	insertarFotoenUsuario(christian, foto3);
	insertarFotoenUsuario(christian, foto5);
//rellenamos e introducimo usuario de prueba
	edu=CrearUsuario ();
	setNombre(edu, "Eduard");
	setLogin(edu, "edeuve");
	setApellido(edu, "Guerra");
	setPerfil_usuario (edu, "otaku");
	setLocalidad(edu, "Malaga");
	setVisitas (edu,176);
	insertarFotoenUsuario(edu, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, edu) );
//rellenamos e introducimo usuario de prueba
	jaime=CrearUsuario ();
	setNombre(jaime, "Jaime");
	setLogin(jaime, "xchampi");
	setApellido(jaime, "Rojas");
	setPerfil_usuario (jaime, "jugador profesional de pin pon");
	setLocalidad(jaime, "Malaga");
	setVisitas (jaime,146);
	insertarFotoenUsuario(jaime, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, jaime) );
//rellenamos e introducimo usuario de prueba
	arturo=CrearUsuario ();
	setNombre(arturo, "Arturo");
	setLogin(arturo, "rizitos69");
	setApellido(arturo, "López");
	setPerfil_usuario (arturo, "carpintero profesional");
	setLocalidad(arturo, "Malaga");
	setVisitas (arturo,97);
	insertarFotoenUsuario(arturo, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, arturo) );
//rellenamos e introducimo usuario de prueba
	adri=CrearUsuario ();
	setNombre(adri, "Adri");
	setLogin(adri, "panojito");
	setApellido(adri, "Garcia");
	setPerfil_usuario (adri, "jugador competitivo del counter");
	setLocalidad(adri, "Almeria");
	setVisitas (adri,328);
	insertarFotoenUsuario(adri, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, adri) );
//rellenamos e introducimo usuario de prueba
	carlos=CrearUsuario ();
	setNombre(carlos, "Carlos");
	setLogin(carlos, "carlitos21");
	setApellido(carlos, "Jiménez");
	setPerfil_usuario (carlos, "representante de vox");
	setLocalidad(carlos, "Sevilla");
	setVisitas (carlos,95);
	insertarFotoenUsuario(carlos, fantonio);
	cout << "insertando usuario...."<<endl;
	setPunteroapuntero(t,InsertarUsuarioEnTabla(t, carlos) );




}
/**
@brief modulo que sirve para imprimir una variable estructurada del tipo tablausuarios
@pre totaltuplas tendrá que ser mayor que 0
@param TablaUsuarios tvariable estructurada de tipo TablaUsuarios que imprimiremos
@return nada. es un procedimiento
@post la variable estructurada de tipo TablaUsuarios será imprimida correctamente
*/

void ImprimirTablaUsuaarios (TablaUsuarios t){


	for (int i=0; i<getTotaltuplas(t);i++){ // bucle que recorre todas las posiciones del vector

		ImprimirUsuario(t.punteroapuntero[i]);
		setVisitas(t.punteroapuntero[i], getVisitas(getUsuarios (t, i))+1);//flipada
	}

}

/**
@brief módulo que sirve para eliminar una variable estructurada de tipo TablaUsuario
@pre la variable estructurada debe de estar rellena y su vector puntero a puntero tiene que ser dinámico
@param TablaUsuario *u (por referencia) variable estructurada la cual resetearemos
@return nada. es un procedimiento
post la variable estructurada será reseteada, eliminando su vector dinámico de punteroapuntero
*/

void EliminarTablaUsuarios (TablaUsuarios t){

	cout <<DEBUG << "Eliminando tabla de usuarios...."<<NORMAL<<endl;

	for (int i=0;i<getTotaltuplas(t);i++){

		t.punteroapuntero[i]=EliminaUsuario(getUsuarios(t, i) ); //  bucle con el que eliminamos todos los componentes del vector punteroapuntero

	}
	delete [] t.punteroapuntero; // liberamos el espacio de memoria del heap 
	t.punteroapuntero=0;

	setTotaltuplas(t, 0);
	cout <<DEBUG << " tabla de usuarios Eliminada correctamente"<<NORMAL<<endl;
}

/**
@brief modulo que sirve para comparar un string con todos los de un vector de tabla de usuarios
@param TablaUsuarios t. variable estructurada que utilizaremos para comparar
@param string login. variable de tipo string que llevará asignado el nombre a comparar
@pre login tiene que estar relleno
@return devolverá un bool que será false si se cumple la condicion o true si no se cumple
@post se devolverá una variable de tipo bool que será true si el string es unico y falso si se repite.
*/

bool ComprobarLogin (TablaUsuarios t, string login){

	bool repetido=false;

	for (int i=0; (i<getTotaltuplas(t) && !repetido);i++){// comprobamos el vector de punteroapuntero hasta llegar hasta el final o hasta demostrar que el login esta repetido 

		if (login == getLogin (getUsuarios (t,i)) ){  // si el login es igual a otro creado, el bool se hará true y se saldrá del grupo

			repetido=true;
		}
	}
	return repetido;
}
/**
@brief modulo que sirve para comparar un string con todos los de un vector de tabla de usuarios y devolver el usuario que se repite
@param TablaUsuarios t. variable estructurada que utilizaremos para comparar
@param string login. variable de tipo string que llevará asignado el nombre a comparar
@param bool unico (por referencia) variable que utilizaremos para ver si se encuentra o no.
@pre login tiene que estar relleno y todos los usuarios de punteroapuntero deberán de tener su login correcto
@return devolverá la posicion del login que coincide
@post si se encuentra el login en el vector, se devolverá la posicion asignada al usuario
*/

int BuscarPorLogin (TablaUsuarios t, string login, bool &repetido){

	int i=0;
	repetido=false;

	for (i=0; (i<getTotaltuplas(t) && !repetido);i++){// comprobamos el vector de punteroapuntero hasta llegar hasta el final o hasta demostrar que el login esta repetido 

		if (login== getLogin (getUsuarios (t,i)) ){// si el login es igual a otro creado, el bool se hará true y se saldrá del grupo

			repetido=true;
		}
	}

	cout <<DEBUG<< i<<NORMAL<<endl;

	return i-1;// en este caso devolvemos la posicion donde esta el usuario que se repite 
}
/** 
@brief modulo que sirve para imprimir solamente el login del usuario.
@pre los login de punteroapuntero deben de estar rellenos.
@param TablaUsuarios t. tabla de la que imprimiremos el login
@return nada. es un procedimiento
@post los login serán impresos correctamente
*/

void ImprimirLoginTabla (TablaUsuarios t){

	for (int i=0; i<getTotaltuplas(t);i++){ // bucle que recorre todo el vector 

		ImprimirLogin(t.punteroapuntero[i]);
	}
}
/** 
@brief modulo que sirve para eliminar una posicion del vector y redimensionarlo una posicion menos
@pre la posicion que queremos eliminar deberá de estar correctamente rellena
@param @TablaUsuarios t (por referencia) Variable que utilizaremos para eliminar una posicon de punteroapuntero
@param int i posicion que queremis eliminar
@return nada. es un pprocedimiento
@post la posicion será eliminada correctamente y el vector redimensionado.
*/
Usuario** EliminarPosicionVector (TablaUsuarios &t, int eliminado){

	Usuario ** aux=new Usuario*[getTotaltuplas(t)];
	int aux_dim_util=getTotaltuplas(t);
	
	//ImprimirUsuario(t.punteroapuntero[eliminado]);
	cout <<DEBUG<<"Eliminando usuario en tabla puntero.... "<<NORMAL<<endl;
	//cout <<DEBUG<<"util antes de eliminar "<<getTotaltuplas(t)<<"posicion que vas a eliminar"<<eliminado<<NORMAL<<endl;
	t.punteroapuntero[eliminado]=EliminaUsuario(t.punteroapuntero[eliminado] );// eliminamos la posición del vector

	if (eliminado < getTotaltuplas(t)){ // si la posicion no es la ultima, podremos sobreescribir. si es la ultima simplemente haremos el resize
		for (int i=eliminado; i<aux_dim_util;i++){
		
			t.punteroapuntero[i]=t.punteroapuntero[i+1];
	
		}
	}
	//cout<<YELLOW<<"USUARIOS DESPUES DE COPIARLO EN ELIMINAR Y ANTES DEL RESIZE"<<endl;
	
	cout <<DEBUG<<"usuario eliminadoen tabla puntero..."<<NORMAL<<endl;
	aux=resize(getPunteroapuntero(t), aux_dim_util,aux_dim_util ,  aux_dim_util-1);// redimensionamos el vector a una posicion menos
	setTotaltuplas(t,aux_dim_util);

	return aux;

}

	
/**
@brief modulo que sirve para ordenar a los usuarios segun sus fotos
@pre Totaltuplas debe de valer mas que 0
@param @TablaUsuarios t (por referencia) Variable que utilizaremos para ordenar sus usuarios
@return nada. es un procedimiento
@post el vector punteroapuntero deberá de estar ordenado por el número de fotos de cada usuario
*/

void OrdenarFotos(TablaUsuarios &t){

	Usuario *valor;// vector auxiliar donde guardaremos la posicion para hacer el cambio
	int Nfotos=0;
	int i=0;

	for (int izqda=1; izqda<getTotaltuplas(t); izqda++){ // metodo de insercion
	
		Nfotos=getTotalFotosUsuario(t.punteroapuntero[izqda]);
		valor=getUsuarios ( t, izqda);

		for (i=izqda; ( (i>0) && ( Nfotos < getTotalFotosUsuario(t.punteroapuntero[i-1]) ) ); i--){

			InsertarUsuarioEnPosicionExistente(t,i, getUsuarios(t,i-1) );
		}
		
		InsertarUsuarioEnPosicionExistente(t, i, valor);
	}
}

/**
@brief modulo que sirve para ordenar a los usuarios por orden alfabético
@pre Totaltuplas debe de valer mas que 0
@param @TablaUsuarios t (por referencia) Variable que utilizaremos para ordenar sus usuarios
@return nada. es un procedimiento
@post el vector punteroapuntero deberá de estar ordenado por orden alfabético
*/

void OrdenarNombre(TablaUsuarios &t){

	Usuario *valor;// puntero auxiliar donde guardaremos la posicion para hacer el cambio
	string auxiliar;
	int i=0;

	for (int izqda=1; izqda<getTotaltuplas(t); izqda++){ // metodo de insercion
	
		auxiliar=getLogin(t.punteroapuntero[izqda]);	
		valor=getUsuarios (t,izqda);

		for (i=izqda; ( (i>0) && ( auxiliar < getLogin(t.punteroapuntero[i-1]) ) ); i--){

			InsertarUsuarioEnPosicionExistente(t,i, getUsuarios(t,i-1) );
		}

		InsertarUsuarioEnPosicionExistente(t, i, valor);
	}
} 

/**
@brief modulo que sirve para que el usuario introduzca el login de un usuario  por pantalla
@param string login (por referencia)variable que rellenará el usuario
@pre debe de haber suficiente memoria como para poder crear la variable
@return nada. es un procedimiento
@post la variable estará rellena correctamente
*/

void RellenarLogin(string &login){
		
	cout<<"Ahora, introduzca su login: "<<endl;
	cin>>login;
}
/**
@brief modulo que sirve para que el usuario introduzca un usuario por pantalla
@param Usuario *u variable que rellenará el usuario
@pre debe de haber suficiente memoria como para poder crear la variable
@ return nada. es un procedimiento
@post la variable estará rellena correctamente
*/	

void RellenaUsuarioAdministrador (TablaUsuarios t,Usuario *u){

	string nombre;
	string login;
	string apellido;
	string nombre_usuario;
	string localidad;
	bool unico;

	do{
		cout <<YELLOW<<"Introduzca el login. Recuerda, debe de ser unico "<<NORMAL<<endl;
		cin >> login;
		unico=ComprobarLogin (t, login);

	}while(unico); // bucle para pedir el login hasta que sea unico 

	setLogin (u, login);
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	cout <<YELLOW<<"Introduzca el nombre real del usuario"<<NORMAL<<endl;
	cin >> nombre;
	setNombre(u, nombre);
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	cout << YELLOW<< " Introduzca el apellido del usuario: "<<NORMAL<<endl;
	cin >> apellido;
	setApellido(u, apellido);
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	cout << YELLOW<< "Introduzca el nombre de usuario: "<<NORMAL<<endl;
	cin>> nombre_usuario;
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	setPerfil_usuario(u, nombre_usuario);
	cout <<DEBUG<< "inserte la localidad de procedencia (recuerde, la primera en mayúscula): "<<NORMAL<<endl;
	cin >>localidad;
	setLocalidad(u,localidad);

}

/**
@brief modulo que sirve para pedir el tamaño de una foto filtrado
@param unsigned long int tamanio variable a la que le asignaremos el tamanio
@return nada. es un procedimiento
@post. tamanio deberá de ser un int y estará filtrado
*/

void PedirTamanioUsuario(unsigned long int &tamanio){


	do{
		cout <<YELLOW<<"introduzca el espacio que ocupa: "<<endl;
		while(!(cin >> tamanio ) ){  // si se produce un error al tomar la entrada, entrará en el bucle
				cout << DEBUG << "no seas golfo anda"<<NORMAL<<endl;
				filtrado(); // invocacion para filtrar
			}
	}while ((tamanio<=0) || (tamanio>=5000000));
}	

/**
@brief modulo que sirve para que el usuario introduzca un usuario por pantalla
@param Usuario *u variable que rellenará el usuario
@pre debe de haber suficiente memoria como para poder crear la variable
@ return naa. es un procedimiento
@post la variable estará rellena correctamente
*/

void RellenaFoto (Foto &f){


	string login;
	string ruta;
	string tipo;
	unsigned long int espacio;

	cout <<YELLOW << "Introduzca la ruta del fichero"<<endl;
	cin >> ruta;
	setRuta(f, ruta);
	cout <<YELLOW <<"Introduzca el tipo del fichero: "<<endl;
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	cin >> tipo;
	setTipo(f, tipo);
	cin.ignore(256,'\n');//lo utilizamos por problemas al insertar nombres muy largos
	PedirTamanioUsuario(espacio);//llamamos a la funcion que nos pedira el espacio filtrado
	setTamanio(f,espacio);
}
/*************************************************/
/************************************************/
		//extra
/************************************************/
/***********************************************/

/**
@brief modulo que sirve para crear un vector de string dinamico
@param int dim dimension que tendrá el vector dinamico
@pre el vector deberá de estar creado previamente 
@return devolvera un vector dinamico de tipo string
@post si hay espacio de memoria en el heap se devolverá correctamente, si no hay se mostraráun mensaje de error y finalizará el programa
*/

string* CrearVectorString (int dim){

	string * s=new string [dim];

	if (s==0){ // si el puntero dinamico apunta a null, es que no hay espacio en el heap
		cout << DEBUG<< "Lo siento, no hay espacio..."<<NORMAL<<endl;
		exit(-1);
	}
	
	return s;

}
/**
@brief modulo que sirve para eliminar un vector de string dinamico
@param string *Vector vector dinamico que eliminaremos
@param int dim variable de tipo int que tendrá asignado las posiciones que tenemos en nuestro vector
@pre el vector deberá de estar creado previamente 
@return devolvera un vector dinamico de tipo string
@post devolveremos un vector dinamico de string apuntando a null
*/

string* BorrarVectorString (string *vector, int util){

	for (int i=0;i<util;i++){// eliminamos el contenido del vector

		vector[i]=" ";
	}
	
	util=0;
	delete []vector ; // eliminamos su espacio del heap
	vector=0;// hacemos que apunte a null
	
	return vector;

}
/**
@brief modulo que sirve paraa imprimir un vector de rutas
@param string rutas [] vector que lleva asignado las rutas a imprimir
@param int util. variable de tipo int que llevará asignado el numero de componentes que tiene el vector
@pre util>0
@return nada. es un procedimiento
@post, se imprimirá correctamente la solucion.
*/

void ImprimirVectorRuta (string rutas [], int util){


	if (util>0){// si la util es mayor que 0 significa que se han encontrado coincidencias en las rutas
		for (int i=0; i<util;i++){
			imprimirRuta( rutas[i]);
		}
	}
	else{ // si la util es 0 significa que no hay coincidencias

		cout <<DEBUG<< " el fragmento no se encuentra en la base de datos..."<<NORMAL<<endl;
	}
}
/**
@brief modulo que sirve para buscar un fragmento en todo un string 
@param TablaUsuarios t variable estructurada de tipo TablaUsuarios que utilizaremos para comparar las fotos
@param string fragmento. variable de tipo string que tendrá asignada el valor del fragmento a buscar
@param string rutas [] vector donde guardaremos todas las rutas que coincidan con el fragmento
@int util_rutas. variable de tipo int que utilizaremos para seguir el estado en tiempo real de rutas.
@pre la variable fragmento deberá de estar rellena y totatuplas deberá de ser mayor que 0
@return nada. es un procedimiento
@post se imprimirá por pantalla las fotos que coincidan correctamente
*/

void BusquedaFragmento (TablaUsuarios t, string fragmento, string* rutas, int &util_rutas){//EJERCICIO EXTRA

	int posicion=0;// variable que utilizaremos para ver si se encuentra la foto bien
	int i=0, j;
	string buscar;
	Foto f_aux;
	Usuario* aux; 


	for (i=0; i<getTotaltuplas(t);i++){
		//cout <<"cambio de usuario"<<endl;
		aux=getUsuarios (t,i);// aqui iremos asignando a aux cada usuario de la tabla
		for(j=0; j<getTotalFotosUsuario(aux);j++){// este bucle lo utilizaremos para comprobar todas las fotos del usuario, una vez acabado de comprobar, en el anterior int se cambiará
			//cout<<DEBUG<<"antes de copiar la foto"<<NORMAL<<endl;
			f_aux=getFoto (aux,j);
			//cout<<DEBUG<<"despues de copiar la foto"<<NORMAL<<endl;
			buscar=getRuta(f_aux);
			//cout<<DEBUG<<"despues de copiar la ruta"<<NORMAL<<endl;
			posicion=buscar.find(fragmento, 0); // funcion para ver si se encuentra el fragmento en la ruta de la foto.
			
			if (posicion != -1){ // si posicion devuelve algo distinto a menos uno es porque si se encuentra.
			
				rutas[util_rutas]=buscar;
				util_rutas++;
			}
			posicion=0;// reseteamos la posicion
		}
	}				
}

/*************************************************/
/************************************************/
		//flipadas
/************************************************/
/***********************************************/
/**
@brief modulo que sirve para buscar en una tabla de usuarios comparando la localidad
@param TablaUsuarios t. variable estructurada que utilizaremos para comparar
@param string Localidad. variable de tipo string que llevará asignado la localidad que queremos buscar
@param int posicion. variable que llevará asignada la posicion del usuario que estamos buscando sus ceercanias
@pre localidad tiene que estar relleno y la primera letra debe de estar en mayúscula. todos los usuarios de punteroapuntero deberán de tener su login correcto
@return nada. es un procedimiento
@post se imprimirán por pantalla correctamente los usuarios que tengan la misma localidad que la buscada
*/

void BuscarLocalidad (TablaUsuarios t, string localidad, int posicion){ //EJERCICIO FLIPADA

	int i=0;
	int j=0;// variable que utilizaremos para ver si hay algún usuario que coincida

	for (i=0; i<getTotaltuplas(t);i++){

		if (localidad== getLocalidad (getUsuarios (t,i)) ){
			
			if (i !=posicion){ // condicion para que no nos imprima el mismo usuario que estamos buscando
				ImprimirUsuario(getUsuarios (t,i) );
				j++;// si entra en el bucle se hará j++
			}
		}
	}

	if (j==0){ // si j es 0 significa wue no ha entrado en el bucle, con lo cual, no hay usuarios en esa localidad
		cout<<DEBUG<<"Lo siento, mejor solo que mal acompañado..."<<NORMAL<<endl;
	}


}
/**
@brief modulo que sirve para ordenar a los usuarios segun sus visitas
@pre Totaltuplas debe de valer mas que 0
@param @TablaUsuarios t (por referencia) Variable que utilizaremos para ordenar sus usuarios
@return nada. es un procedimiento
@post el vector punteroapuntero deberá de estar ordenado segun las visitas de cada usuario
*/

void OrdenarVisitas(TablaUsuarios &t){

	Usuario *valor;// vector auxiliar donde guardaremos la posicion para hacer el cambio
	int Nvisitas=0;
	int i=0;

	for (int izqda=1; izqda<getTotaltuplas(t); izqda++){ // metodo de insercion
	
		Nvisitas=getVisitas(getUsuarios(t,izqda) );
		valor=getUsuarios ( t, izqda);

		for (i=izqda; ( (i>0) && ( Nvisitas < getVisitas(getUsuarios(t,i-1) ) ) ); i--){

			InsertarUsuarioEnPosicionExistente(t,i, getUsuarios(t,i-1) );
		}
		
		InsertarUsuarioEnPosicionExistente(t, i, valor);
	}
}
/**
@brief modulo que sirve para imprimir el login del usuario con sus visitas.
@pre el login y las visitas deberá de estar relleno
@param Usuario *u variable de tipo punturo que apunta a la variable de tipo usuario que queremos imprimir el login
@return nada. es un procedimiento.
@post el login se imprimirá correctamente junto con las visitas
*/

void ImprimirLoginVisitas(Usuario *u){

	cout <<CYAN<< "Nombre de Login: "<<NORMAL<< getLogin(u)<<DEBUG<<" visitas: "<<getVisitas(u)<<NORMAL<<endl;

}

/** 
@brief modulo que sirve para imprimir el login del usuario con sus visitas.
@pre los login de punteroapuntero y las visitas deben de estar rellenos.
@param TablaUsuarios t. tabla de la que imprimiremos el login y las visitas 
@return nada. es un procedimiento
@post los login serán impresos correctamente junto con sus visitas
*/

void ImprimirLoginVisitasTabla (TablaUsuarios t){

	for (int i=0; i<getTotaltuplas(t);i++){

		ImprimirLoginVisitas(t.punteroapuntero[i]);
	}
}

/**
@brief modulo que sirve para enseñar el menu de las flipadas 
@pre char != z
@param  char &opcion(por referencia) parametro que sirve para ver que opción cogemos.
@param TablaUsuarios cristian variable estructurada de tabla de usuarios que utilizaremos para obtener los datos
@RETURN Nada. es un procedimiento
@post  Mostrará por pantalla el menú correctamente
*/

void menuFlipadas (char &opcion, TablaUsuarios cristian){
	
	int posicion_aux=0;
	bool unico;	
	string login;

	cout <<CYAN<< "Usted ha entrado al menu de las flipadas"<<endl;
	cout <<YELLOW<< "---------------------------MENU--------------------------"<<endl;
	cout <<DEBUG<< "Opcion x: "<<NORMAL<<" Localizar personas cerca de un usuario"<<endl;
	cout <<DEBUG<< "Opcion y:"<<NORMAL<<" Ordenar personas por numero de visitas"<<endl;
	cout << "Opcion z: Salir del menu de flipadas"<<endl;
	cin>> opcion;

	switch (opcion) { // switch utilizado para el menú
        	case 'x':
			
			cin.ignore(256,'\n');//ignora 256 caracteres y el salto de linea
			cout <<CYAN<< "bienvenido a la busqueda por localidad de cristobook, podrás conocer a la gente que tiene un usuario cerca!!"<<NORMAL<<endl;
			cout <<CYAN<<"para empezar diganos sobre que usuario quiere realizar su busqueda: "<<NORMAL<<endl;
			ImprimirLoginTabla(cristian);
			cout <<YELLOW<<" vamos a ver los usuarios que tiene cerca una persona. "<<NORMAL;
			RellenarLogin(login);
			posicion_aux=BuscarPorLogin (cristian, login, unico);

			if (unico){			

			BuscarLocalidad (cristian, getLocalidad(getUsuarios (cristian, posicion_aux) ), posicion_aux );				
				
			}
			else{
				cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
			}

			break;
		case 'y':
			ImprimirLoginTabla(cristian);
			OrdenarVisitas(cristian);
			cout <<SOLUCION<<" ordenados correctamente por visitas "<<NORMAL<<endl;
			ImprimirLoginVisitasTabla (cristian);
			break;

		default:
			break;


	}
}
/*************************************************/
/************************************************/
	//fin de flipadas
/************************************************/
/***********************************************/
/**
@brief moódulo que sirve para implementar diferentes funciones de testing
@param TablaUsuarios cristian. Tabla sobre la que utilizaremos el testing 
@char &opcion (por referencia) variable de tipo char que utilizaremos para ver en que opcion del menu nos metemos
@pre para realizar estos testing cristian.Totaltuplas deberá de ser mayor que 0
@return nada. es un procedimiento
@post la TablaUsuarios será testada correctamente para comprobar su funcionamientp
*/
 
void menuDebbug(TablaUsuarios cristian, char opcion){

	Usuario**auxiliar_1 =new Usuario*[5];
	Usuario *manolo;
	Usuario *juan;
	Usuario *guille;
	Usuario *angel;
	Usuario *pablo;
	Foto fantonio, foto1, foto2, foto3, foto5;
	int tamanio=400000, aux;

	cout <<CYAN<< "Opcion a:"<<NORMAL<<"testeo tarjetas 1,3,2 (x3)"<<endl;
	cout <<CYAN<< "Opcion b:"<<NORMAL<<" introduce 5 usuarios, borraa 3 usuarios (x3)"<<endl;
	cout <<CYAN<< "Opcion c:"<<NORMAL<<"Insertar usuario, introducir 4 foros, borrar usuario (x3) "<<endl;

	cin>>opcion;

	switch (opcion) {
			

		case 'a':

			for (int i=0;i<3;i++){

				cout <<"creando tabla"<<endl;
				crearTablaUsuario(cristian);
				ImprimirTablaUsuaarios (cristian);
				cout <<"eliminando tabla"<<endl;
				EliminarTablaUsuarios (cristian);
			}
			break;

		case 'b':

	

			//cout << "despues de hacer el puntero dinamico"<<endl;
			setRuta(fantonio, "home desktop programacion dd");
			setTipo(fantonio, ".png");
			setTamanio (fantonio, tamanio);

	
	
		//rellenamos e introducimo usuario de prueba
			manolo=CrearUsuario ();
			setNombre(manolo, "manolo");
			setLogin(manolo, "tony el gordo");
			setApellido(manolo, "martinez");
			setPerfil_usuario (manolo, "sicario");
			setLocalidad(manolo, "Granada");
			setVisitas (manolo, 231);
			insertarFotoenUsuario(manolo, fantonio);


		//rellenamos e introducimo usuario de prueba

			pablo=CrearUsuario ();
			setNombre(pablo, "cristian");
			setLogin(pablo, "cristiancj99");
			setApellido(pablo, "Campos");
			setPerfil_usuario (pablo, "programador menos que junior");
			setLocalidad(pablo, "Granada");
			setVisitas (pablo, 100);
			insertarFotoenUsuario(pablo, fantonio);





		//rellenamos e introducimo usuario de prueba
			juan=CrearUsuario ();
			setNombre(juan, "Eduard");
			setLogin(juan, "edeuve");
			setApellido(juan, "Guerra");
			setPerfil_usuario (juan, "otaku");
			setLocalidad(juan, "Malaga");
			setVisitas (juan,176);
			insertarFotoenUsuario(juan, fantonio);
	

		//rellenamos e introducimo usuario de prueba
			guille=CrearUsuario ();
			setNombre(guille, "Jaime");
			setLogin(guille, "xchampi");
			setApellido(guille, "Rojas");
			setPerfil_usuario (guille, "jugador profesional de pin pon");
			setLocalidad(guille, "Malaga");
			setVisitas (guille,146);
			insertarFotoenUsuario(guille, fantonio);
			

		//rellenamos e introducimo usuario de prueba
			angel=CrearUsuario ();
			setNombre(angel, "Arturo");
			setLogin(angel, "rizitos69");
			setApellido(angel, "López");
			setPerfil_usuario (angel, "carpintero profesional");
			setLocalidad(angel, "Malaga");
			setVisitas (angel,97);
			insertarFotoenUsuario(angel, fantonio);
	
			

			
			auxiliar_1[0]=guille;
			auxiliar_1[1]=pablo;
			auxiliar_1[2]=juan;
			auxiliar_1[3]=angel;
			auxiliar_1[4]=manolo;
				
			aux=getTotaltuplas(cristian);

			for (int i=0; i<3;i++){
				for (int i;i<5;i++){
				
				setPunteroapuntero(cristian,InsertarUsuarioEnTabla(cristian, auxiliar_1[i]) );	

				}

				for (int i=getTotaltuplas(cristian)-1; i>= aux;i--){
					cout << YELLOW<<i<<endl;
					setPunteroapuntero(cristian,EliminarPosicionVector(cristian, i) );
				}
				cout <<DEBUG<< "mostrando tabla despues de eliminar los 5  alumnos"<<endl;
				cout <<CYAN<<"despues de eliminar "<<getTotaltuplas(cristian)<<NORMAL<<endl;				
			}
			break;




		case 'c':	

			guille=CrearUsuario ();
			setNombre(guille, "Jaime");
			setLogin(guille, "xchampi");
			setApellido(guille, "Rojas");
			setPerfil_usuario (guille, "jugador profesional de pin pon");
			setLocalidad(guille, "Malaga");
			setVisitas (guille,146);
			insertarFotoenUsuario(guille, fantonio);


			setRuta(foto1, "home desktop foto1");
			setTipo(fantonio, ".JPEG");
			setTamanio (foto1, tamanio);

			setRuta(foto2, "home desktop/fotos/ds");
			setTipo(foto2, ".png");
			setTamanio (foto2, tamanio);

			setRuta(foto3, "home desktop/imagen");
			setTipo(fantonio, ".JPEG");
			setTamanio (foto3, tamanio);

			setRuta(foto5, "home/imagen");
			setTipo(fantonio, ".png");
			setTamanio (foto5, tamanio);

			pablo=CrearUsuario ();
			setNombre(pablo, "cristian");
			setLogin(pablo, "cristiancj99");
			setApellido(pablo, "Campos");
			setPerfil_usuario (pablo, "programador menos que junior");
			setLocalidad(pablo, "Granada");
			setVisitas (pablo, 100);
			insertarFotoenUsuario(pablo, fantonio);


			juan=CrearUsuario ();
			setNombre(juan, "Eduard");
			setLogin(juan, "edeuve");
			setApellido(juan, "Guerra");
			setPerfil_usuario (juan, "otaku");
			setLocalidad(juan, "Malaga");
			setVisitas (juan,176);
			insertarFotoenUsuario(juan, fantonio);

			Usuario**auxiliar =new Usuario*[3];
			
			auxiliar[0]=guille;
			auxiliar[1]=pablo;
			auxiliar[2]=juan;


			for (int i=0;i<3;i++){

				setPunteroapuntero(cristian,InsertarUsuarioEnTabla(cristian, auxiliar[i]) );	
				cout << "insertando foto"<<endl;
				cout<<DEBUG<< getTotaltuplas(cristian);		
				insertarFotoenUsuario(cristian.punteroapuntero[getTotaltuplas(cristian)-1], foto1);
				cout << "insertando foto"<<endl;		
				insertarFotoenUsuario(cristian.punteroapuntero[getTotaltuplas(cristian)-1], foto2);
				cout << "insertando foto"<<endl;		
				insertarFotoenUsuario(cristian.punteroapuntero[getTotaltuplas(cristian)-1], foto3);
				cout << "insertando foto"<<endl;		
				insertarFotoenUsuario(cristian.punteroapuntero[getTotaltuplas(cristian)-1], foto5);
				setPunteroapuntero(cristian,EliminarPosicionVector(cristian, getTotaltuplas(cristian)-1 ) );
			}
			cout << SOLUCION<< "todo correcto"<<endl;	
			delete []auxiliar;
			auxiliar=0;
			break;
			
	}

	
}		
/**
@brief módulo que sirve para eliminar aquellos usuarios que no tengan más de tres fotos
@param TablaUsuarios t(por referencia) tabla de usuarios de la cual comprobaremos si sus miembros cumplen los requisitos o no
@param int MinFotos. variable que utilizaremos para comprobar con el número de fotos de cada usuario
@pre TotalTuplas>0
@return nada. es un procedimiento 
@post eliminará correctamente los usuarios que tengan menos de 3 fotos
*/

void EliminarUsuarioPorFicherosMin(TablaUsuarios &t, int MinFotos){

	int aux=0;//variable que utilizaremos para ir guardando el número de fotos de cada usuario


	for (int i=0; i< getTotaltuplas(t);i++){

		aux=getTotalFotosUsuario(getUsuarios (t, i) );
		//cout <<i<<endl;
		if (aux < MinFotos){
			//cout <<"he entrado"<<endl;
			setPunteroapuntero(t,EliminarPosicionVector(t, i) );
			i=0;

		}
	}
	
}

			
/**
@brief modulo que sirve para enseñar un menu y que el usuario pueda elegir sus opciones 
@pre char != e
@param  char &opcion(por referencia) parametro que sirve para ver que opción cogemos.
@RETURN Nada. es un procedimiento
@post  Mostrará por pantalla el menú correctamente
*/
void menu ( char &opcion, TablaUsuarios &cristian, int &filtrado){

	bool unico;	
	string login;
	string localidad;
	string fragmento;
	Foto foto_nueva;
	char opcion_flipada;
	int posicion_aux=0, posicion_foto_aux=0;
	int dim=20;
	int util_aux=0;
	string *rutas;
	int util_rutas=0;
	int MinFotos=0;

	rutas=CrearVectorString (dim);// creamos el vector dinamico que necesitaremos para el ejercicio extra



	cout <<SOLUCION<< "BIENVENIDOS A CRISTOBOOK, SELECCIONE UNA OPCION PARA COMENZAR."<<endl;
	cout <<YELLOW<< "---------------------------MENU--------------------------"<<endl;
	cout <<CYAN<< "Opcion a:"<<NORMAL<<"Crear tabla de usuarios"<<endl;
	cout <<CYAN<< "Opcion b:"<<NORMAL<<" Eliminar una tabla de usuarios"<<endl;
	cout <<CYAN<< "Opcion c:"<<NORMAL<<"Imprimir tabla de Usuarios"<<endl;
	cout <<CYAN<< "Opcion d:"<<NORMAL<<"insertar usuario en tabla de usuarios "<<endl;
	cout <<CYAN<< "Opcion e:"<<NORMAL<<"Eliminar usuario de la tabla de usuarios"<<endl;
	cout <<CYAN<< "Opcion f:"<<NORMAL<<"Buscar por atributo login en tabla de usuarios "<<endl;
	cout <<CYAN<< "Opcion g:"<<NORMAL<<"ordenar por atributo totalfotos y por login "<<endl;
	cout <<CYAN<< "Opcion h:"<<NORMAL<<"Añadir fotografia a usuario"<<endl;
	cout <<CYAN<< "Opcion i:"<<NORMAL<<"Eliminar fotografia de usuario"<<endl;
	cout <<CYAN<< "Opcion j:"<<NORMAL<<"Imprimir Fotografias Del usuario"<<endl;	
	cout <<CYAN<< "Opcion k:"<<NORMAL<<"extra: localizacion de un fragmento en las rutas "<<endl;	
	cout <<CYAN<< "Opcion m:"<<NORMAL<<"menu flipadas"<<endl;
	cout <<CYAN<< "Opcion x: prueba aptitud"<<NORMAL<<endl;
	cout <<CYAN<< "Opcion o: testing grupal"<<NORMAL<<endl;
	cout <<DEBUG<< "Opcion n:"<<NORMAL<<"Salir"<<endl;
	do{
		if (filtrado==0){
			cout <<DEBUG<<"RECUERDA, SI NO HAY TABLA NO PODRÁS ACCEDER A NADA, SOLO A SALIR"<<NORMAL<<endl;
		}
		cout <<CYAN<< NORMAL;
		cin >> opcion;

	}while ( (filtrado==0)&&( (opcion !='a') && (opcion !='n') ) );
	filtrado++;
	

	switch (opcion) { // switch utilizado para el menú
        	case 'a': // caso para crear las tablas
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "aoefnen" que se meta solo en la opcion a.
			crearTablaUsuario(cristian);

			break;
		case 'b':// caso de eliminar una tabla de usuarios
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "boefnen" que se meta solo en la opcion b.
			EliminarTablaUsuarios (cristian);
			setTotaltuplas(cristian, 0);
			filtrado=0;

			break;
		case 'c':// caso de imprimir una tabla de usuarios
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "coefnen" que se meta solo en la opcion c.
			ImprimirTablaUsuaarios (cristian);

			break;
		case'd': // caso de insertar un usuario en una tabla de usuarios
			cin.ignore(256,'\n');//ignora 256 caracteres y el salto de linea
			Usuario *nuevo;
			nuevo=CrearUsuario();// hacemos la variable dinámica
			//pedimos los datos de la variable que vamos a introducir en el usuario

			RellenaUsuarioAdministrador (cristian,nuevo);
		 
			cristian.punteroapuntero=InsertarUsuarioEnTabla(cristian, nuevo);




			break;
		case 'e':// caso de Eliminar un usuario de la tabla de usuarios 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "eoefnen" que se meta solo en la opcion e.
			if(getTotaltuplas(cristian) <=1){
				
				cout << DEBUG<< "no puedes eliminar el ultimo usuario, si quieres hacerlo elimina la tabla."<<NORMAL<<endl;
			}

			else{

				cout << DEBUG<<getTotaltuplas(cristian)<<NORMAL<<endl;

				ImprimirLoginTabla(cristian);
				cout <<YELLOW<<" vamos a eliminar un usuario. "<<NORMAL;
				RellenarLogin(login);
				posicion_aux=BuscarPorLogin (cristian, login, unico);

				if (unico){
					setPunteroapuntero(cristian,EliminarPosicionVector(cristian, posicion_aux) );
					ImprimirLoginTabla(cristian);

				}
				else{
					cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
				}
			}
				

			break;
        	case 'f': // caso buscar por atributo login wn una tabla de usuarios

			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "foefnen" que se meta solo en la opcion f.

			cout <<YELLOW<<"vamos a buscar un usuario por login. "<<NORMAL;
			RellenarLogin(login);
			posicion_aux=BuscarPorLogin (cristian, login, unico);

			if (unico){
				ImprimirUsuario(getUsuarios (cristian, posicion_aux));
				setVisitas(cristian.punteroapuntero[posicion_aux], getVisitas(getUsuarios (cristian, posicion_aux))+1);

			}
			else{
				cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
			}
			
			
			break;
		case 'g':// caso de ordenar por atributo totalfotos o por login 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "goefnen" que se meta solo en la opcion g.

			cout <<YELLOW<< "Ordenando por el numero de fotos..."<<NORMAL<<endl;
			OrdenarFotos(cristian);
			cout <<DEBUG<< "Ordenado por el numero de fotos correctamente."<<NORMAL<<endl;
			ImprimirLoginTabla(cristian);

			cout <<YELLOW<<"Ordenando por el nombre..."<<NORMAL<<endl;
			OrdenarNombre(cristian);
			cout <<DEBUG<< "Ordenado por el nombre correctamente."<<NORMAL<<endl;			
			ImprimirLoginTabla(cristian);
			break;

		case 'h':// caso de añadir una fotografia al usuario

			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "hoefnen" que se meta solo en la opcion h.
			RellenaFoto (foto_nueva);
			cout <<YELLOW<<" vamos a introducir una foto en un usuario. "<<NORMAL;
			RellenarLogin(login);
			posicion_aux=BuscarPorLogin (cristian, login, unico);

			if (unico){							
				cout << DEBUG <<" insertando foto a "<< login <<NORMAL<<endl;	
				insertarFotoenUsuario (cristian.punteroapuntero[posicion_aux], foto_nueva);
				cout << SOLUCION <<" imagen insertada correctamente..."<<NORMAL<<endl;
			}
			else{
				cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
			}
			break;


		case'i': // caso de eliminar una foto del usuario
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "ioefnen" que se meta solo en la opcion i.
			ImprimirLoginTabla(cristian);
			cout <<YELLOW<<" vamos a eliminar una foto de un usuario. "<<NORMAL;
			RellenarLogin(login);
			posicion_aux=BuscarPorLogin (cristian, login, unico);
			util_aux=getTotalFotosUsuario(getUsuarios (cristian, posicion_aux));

			if (unico){
				if ( util_aux==0){

					cout <<DEBUG<<"No hay mas fotos que eliminar"<<NORMAL<<endl;
				}
				else{				
					ImprimirFotosUsuario (getUsuarios (cristian, posicion_aux));			
					cout<<" que imagen desea borrar?"<<endl;
					cin>>posicion_foto_aux;	
					EliminarFotoVector (cristian.punteroapuntero[posicion_aux], posicion_foto_aux);
				
				
				}
			}

			else{
				cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
			}

	
			break;
		case 'j':// caso de Imprimir todas las fotos de un usuario 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "joefnen" que se meta solo en la opcion j.
			ImprimirLoginTabla(cristian);
			cout <<YELLOW<<" vamos ver las fotos de un usuario. "<<NORMAL;
			RellenarLogin(login);
			posicion_aux=BuscarPorLogin (cristian, login, unico);

			if (unico){							
				cout << DEBUG <<" mostrando fotos de.. "<< login <<NORMAL<<endl;
				ImprimirFotosUsuario (getUsuarios (cristian, posicion_aux));
				setVisitas(cristian.punteroapuntero[posicion_aux], getVisitas(getUsuarios (cristian, posicion_aux))+1);	
				
				cout << SOLUCION <<" imagen insertada correctamente..."<<NORMAL<<endl;
			}
			else{
				cout <<DEBUG<<"Lo siento, usuario no dado de alta..."<<NORMAL<<endl;
			}
			break;

			break;


		case 'k':// ejercicio extra 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "koefnen" que se meta solo en la opcion k.
			cout <<"Diganos el fragmento que quiere buscar entre las fotos de nuestra base de datos: "<<endl;
			cin >> fragmento;
			BusquedaFragmento (cristian,fragmento, rutas, util_rutas);
			ImprimirVectorRuta (rutas,util_rutas);
			util_rutas=0;
				
			break;

		case 'm':// flipada

			/* algoritmo que busque a gente de una misma ciudad que el usuario elegido. para ello se añadirá otro componente al struckt usuario
			y se realizará una busqueda. imprimiendo el  usuario y todos los usuarios que viven cerca de el*/
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "ioefnen" que se meta solo en la opcion i.
			do{				
				menuFlipadas (opcion_flipada,cristian);
			}while(opcion_flipada !='z');		
				
			break;
		case 'x':// prueba de aptitud
			cout <<" vamos a eliminar los usuarios que tengan un menos número de fotos del que introduzcas: "<<endl;
			cin >> MinFotos;
			ImprimirTablaUsuaarios (cristian);
			EliminarUsuarioPorFicherosMin(cristian, MinFotos);
			ImprimirTablaUsuaarios (cristian);
			
			break;
		case 'o':

			menuDebbug(cristian,opcion_flipada);

			break;




		case 'n':// caso para salir del programa

			if (getTotaltuplas(cristian)==0){// si el puntero apunta a null, no hará falta que liberemos espacio de memoria.

				cout <<YELLOW<<" Hasta la proxima!!!"<<NORMAL<<endl;
			}

			if(getTotaltuplas(cristian)!=0){ // si el puntero no apunta a null tendremos que eliminar la tabla para así librarnos de todo lo dinamico
				cout << DEBUG<<"Primero, liberaremos el espacio de memoria que has gastado golfo!! "<<NORMAL<<endl;			
				EliminarTablaUsuarios (cristian);
				cout << SOLUCION<< "Ahora si que si. HASTA LA PROXIMA!!"<<NORMAL<<endl;
			}
			rutas=BorrarVectorString (rutas, util_rutas);
				

			break;

		default:
			break;
	}
}

int main () {

	char opcion='\0';
	TablaUsuarios cristian;
	int filtrado=0;//variable que utilizaremos para filtrar el menu
	
	setTotaltuplas(cristian, 0);// lo utilizaremos para que funcione bien el módulo de salir



	do{ // bucle que repetirá el menú hasta que se pulse la tecla s

		menu ( opcion, cristian, filtrado);


	}while ( opcion !='n');



}
