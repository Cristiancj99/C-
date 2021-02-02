#include <iostream>
#include <stdlib.h>
#include<string>
#include "vista.h"
#define NORMAL "\033[1;0m"
#define CYAN "\033[1;36m"
#define DEBUG "\033[1;31m"
#define YELLOW "\033[1;33m"
#define SOLUCION "\033[1;32m"
#define PURPLE "\033[1;35m"
#define GREEN_SUBRA "\033[1;42m"

using namespace std;
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
Vista::Vista(){

	t= new Tabla_usuarios();
} 

Vista::~Vista(){

	t->~Tabla_usuarios();
}
void Vista::setDebug ( bool debug){

	this->debug=debug;
}

bool Vista::getDebug ( ){

	return this->debug;
}

void Vista::creacionInicial(){

	Admin *Christian=new Admin("cristiancj99", "cristian","Campos", "Programador Fracaso",0);// usuario incial
	t->InsertarUsuarioenVector(Christian);	

	Normal *Jaime=new Normal("j.Cabeza", "Jaime","Garcia", "Cabezilla de grupo", 946.47, 0, 5);// usuario inicial
	t->InsertarUsuarioenVector(Jaime);
	Foto f=Foto("HOME/DESKTOP/FOTOS/FOTO",".PNG",342432);
	this->t->InsertarFotoUsuarioTabla(f, 1);

	Normal *Edu=new Normal("edeuve", "Edu","Guerra", "Otaku", 964.47, 0, 5);// usuario inicial
	t->InsertarUsuarioenVector(Edu);

	Foto j=Foto("HOME/DESKTOP/FOTOS/PLAYA",".PNG",342432);	
	Foto h=Foto("HOME/DESKTOP/FOTOS/MANTA",".PNG",342432);
	Foto g=Foto("HOME/DESKTOP/FOTOS/CUCHILLO",".PNG",342432);
	// fotos que utilizaremos inicialmente
	this->t->InsertarFotoUsuarioTabla(f, 2);
	this->t->InsertarFotoUsuarioTabla(j, 2);
	this->t->InsertarFotoUsuarioTabla(h, 2);
	this->t->InsertarFotoUsuarioTabla(g, 2);

	
	Normal *arturo=new Normal("arzu", "Arturo","Mena", "fontanero", 32, 0, 5);
	t->InsertarUsuarioenVector(arturo);

	Normal *pablo=new Normal("blogart", "Pablo","Garcia", "Arquitecto", 55, 0, 5);
	t->InsertarUsuarioenVector(pablo);
	this->t->InsertarFotoUsuarioTabla(j, 4);
	this->t->InsertarFotoUsuarioTabla(h, 4);

}	

void Vista::InsertarUsuarioVista(){

	char opcion;
	string nombre;
	string login;
	string apellido;
	string perfil;
	int posicion;
	bool repetido=false;//variable auxiliar que utilizaremos para filtrar el login

	do{
		cout<<" digame el login de su usuario: "<<endl;
		cin>>login;
		repetido=this->t->BuscarLogin(login, posicion, false);
		if( repetido){
		
			cout<<DEBUG<<"login en uso"<<NORMAL<<endl;
		}
	}while(repetido);
	cout<< "digame el nombre de su usuario: "<<endl;
	cin>>nombre;
	cout<<"digame el apellido de su usuario: "<<endl;
	cin>>apellido;
	cout<< "Por Ultimo, diganos que tipo de perfil"<<endl;
	cin>>perfil;

	do{
		cout<<" elija la función que desea: A(administrador), U(usuario normal)"<<endl;
		cin >>opcion;
	}while ( (opcion != 'A') && (opcion !='U') );

	if (opcion=='A'){


		Admin *nuevo=new Admin(login, nombre,apellido, perfil,0);
		this->t->InsertarUsuarioenVector(nuevo);
	}
		
	if (opcion=='U'){

		int salario;
		cout<< "Por favor, diganos el salario del usuario: "<<endl;
		while(!(cin >> salario ) ){  // si se produce un error al tomar la entrada, entrará en el bucle
			cout << DEBUG << "no seas golfo anda"<<NORMAL<<endl;
			filtrado(); // invocacion para filtrar
		}
		Normal *nuevo=new Normal(login, nombre,apellido, perfil, salario, 0, 5);
		this->t->InsertarUsuarioenVector(nuevo);
	}			
			

}	
void Vista::EliminarUsuarioVista(){

	string login;
	bool encontrado=false;
	int posicion=0;
	cout<<" diganos el usuario que va a eliminar: "<<endl;
	cin>>login;
	encontrado=this->t->BuscarLogin(login, posicion, false);
	if (encontrado){// si encontrado es true, es porque el usuario esta en la bd
		this->t->EliminarUsuarioVector(posicion);
	}
	
	else{
		cout<<DEBUG<<"Lo siento, usuario no encontrado.."<<NORMAL<<endl;
	}







}
void Vista::BuscarPorLoginDado(){

	string login;
	bool encontrado=false;
	int posicion=0;
	cout<<" diganos el usuario que desea buscar: "<<endl;
	cin>>login;

	encontrado=this->t->BuscarLogin(login, posicion, true);// en este caso posicion, no sirve para nada.

	if (!encontrado){
		
		cout<<DEBUG<<" Lo siento, usuario no encontrado"<<endl;
	}
}
	

void Vista::ImprimirFotos(){


	string login;
	bool encontrado=false;
	int posicion=0;
	cout<<PURPLE<<" diganos el usuario que va a imprimir las foto: "<<NORMAL<<endl;
	cin>>login;
	encontrado=this->t->BuscarLogin(login, posicion, false);
	if (encontrado){// si encontrado es true, es porque el usuario esta en la bd
		this->t->ImprimirFotosUsuarioTabla(posicion);
	}
	
	else{
		cout<<DEBUG<<"Lo siento, usuario no encontrado.."<<NORMAL<<endl;
	}




}

void Vista::EliminarFoto(){


	int posicion_foto;
	string login;
	bool encontrado=false;
	int posicion=0;
	cout<<" diganos el usuario que va a Eliminar la foto: "<<endl;
	cin>>login;
	encontrado=this->t->BuscarLogin(login, posicion, false);

	if (encontrado){// si encontrado es true, es porque el usuario esta en la bd
		this->t->ImprimirFotosUsuarioTabla(posicion);
		cout<<CYAN<< "diganos la foto que va a eliminar"<<endl;
		cin>> posicion_foto;
		this->t->EliminarFotoUsuarioTabla(posicion,posicion_foto);
	
	}
	
	else{
		cout<<DEBUG<<"Lo siento, usuario no encontrado.."<<NORMAL<<endl;
	}

}
void Vista::InsertarFotoDada(){
	string login, ruta, tipo;
	int tamanio;
	bool encontrado=false;
	int posicion=0;
	cout<<"ingrese la ruta: "<<endl;
	cin>>ruta;
	
	cout<<"ingrese el tipo"<< endl;
	cin >>tipo;
	
	cout <<"Ingrese el tamaño que ocupa su foto "<<endl;
	cin>>tamanio;

	cout<<" diganos el usuario que va a introducir la foto: "<<endl;
	cin>>login;
	encontrado=this->t->BuscarLogin(login, posicion, false);

	if (encontrado){ // si encontrado es true, es porque el usuario esta en la bd
		Foto f=Foto(ruta,tipo,tamanio);
		this->t->InsertarFotoUsuarioTabla(f, posicion);
	}
	
	else{
		cout<<DEBUG<<"Lo siento, usuario no encontrado.."<<NORMAL<<endl;
	}
}

void Vista::OrdenarTabla(){

char opcion;
	do{
		cout<<YELLOW<<"Por favor, introduzca L si quiere ordenar por login y F si lo va a hacer por fotos"<<NORMAL<<endl;
		cin >> opcion;

	}while( (opcion!='F') && (opcion!='L') );

	if (opcion =='L'){ //opcion de ordenar por login

		cout <<"USTED HA DECIDIDO ORDENAR POR LOGIN"<<endl;
		this->t->OrdenarPorLogin();
	}
	if (opcion =='F'){//opcion de ordenar por vista

		cout <<"USTED HA DECIDIDO ORDENAR POR TOTAL FOTOS "<<endl;
		this->t->OrdenarPorTotalFotos();
		this->t->printNormal();


	}

}

void Vista::ExtraVista(){

	string login;
	string fragmento;
	bool encontrado=false;
	int posicion=0;
	cout<<" diganos su nombre de usuario: "<<endl;
	cin>>login;
	cout<<" Ahora, diganos el fragmento que desea buscar: "<<endl;
	cin>>fragmento;
	encontrado=this->t->BuscarLogin(login, posicion, false);
	if (encontrado){// si encontrado es true, es porque el usuario esta en la bd
		this->t->ExtraFragmento (fragmento,posicion);
	}
	
	else{
		cout<<DEBUG<<"Lo siento, usuario no encontrado.."<<NORMAL<<endl;
	}
}
void Vista::CambiarDebug(){

	char opcion;

	cout<<YELLOW<<"Pulse A si desea activar o D si desea desactivar los debug."<<NORMAL<<endl;
	cin>>opcion;

	if (opcion=='A'){//activa debug

		this->t->CambiarDebugTabla(true);
	}
	if (opcion=='D'){//apaga debug

		this->t->CambiarDebugTabla(false);
	}

}

void Vista::testing(){

	Usuario**auxiliar_1 =new Usuario*[5];
	Normal *manolo=new Normal("mano","manolo","martinez","sicario", 3634, 0, 5);			
	//rellenamos e introducimo usuario de prueba

	Normal *pablo=new Normal("blogart","Pablo","Hernandez","blogero", 3634, 0, 5);

	//rellenamos e introducimo usuario de prueba

	Normal *juan=new Normal("Anillo","Juanillo","Martinez","tonto", 3634, 0, 5);
	
	//rellenamos e introducimo usuario de prueba

	Normal *guille=new Normal("tonto","guille","SantaMaria","Persona que va de sobrada", 3634, 0, 5);

	//rellenamos e introducimo usuario de prueba

	Normal *angel=new Normal("Angelm","Angel","Martinez","Profesor", 3634, 0, 5);
	
	Normal *Manuel=new Normal("tonto","guille","SantaMaria","Persona que va de sobrada", 3634, 0, 5);

	Usuario**auxiliar =new Usuario*[3];


	Foto foto1=Foto("home/desktop/foto1", ".png",4324);


	Foto foto2=Foto("home/desktop/foto2", ".png",4324);

	
	Foto foto3=Foto("home/desktop/foto3", ".png",4324);


	Foto foto4=Foto("home/desktop/foto4", ".png",4324);



	Normal *Antonio=new Normal("anthony","guille","SantaMaria","Persona que va de sobrada", 3634, 0, 5);


		
			
	Normal *manu=new Normal("Manolo63","guille","SantaMaria","Persona que va de sobrada", 3634, 0, 5);

	char opcion;
	int aux, auxiliar2;

	cout <<CYAN<< "Opcion a:"<<NORMAL<<"testeo tarjetas 1,3,2 (x3)"<<endl;
	cout <<CYAN<< "Opcion b:"<<NORMAL<<" introduce 5 usuarios, borraa 3 usuarios (x3)"<<endl;
	cout <<CYAN<< "Opcion c:"<<NORMAL<<"Insertar usuario, introducir 4 foros, borrar usuario (x3) "<<endl;

	cout<<PURPLE<< "Opcion b:"<<NORMAL<<" eliminar usuarios con menos de 1 foto,2, y finalmente 2"<<endl;

	cin>>opcion;

	switch (opcion) {
			

		case 'a':

			for (int i=0;i<3;i++){

				cout <<"creando tabla"<<endl;
				this->creacionInicial();
				this->t->print();
				cout <<"eliminando tabla"<<endl;
				this->t->~Tabla_usuarios();
			}
			break;

		case 'b':
	
		//rellenamos e introducimo usuario de prueba


	
			auxiliar_1[0]=guille;
			auxiliar_1[1]=pablo;
			auxiliar_1[2]=juan;
			auxiliar_1[3]=angel;
			auxiliar_1[4]=manolo;
				
			aux=this->t->getTotal_usuarios();// auxiliar que utilizaremos para guardar las tuplas que teniamos iniciaalmente antes de comenzar el testing

			for (int i=0; i<3;i++){

				cout<<"he entrado la "<<i<<"vez"<<endl;				

				for (int i=0;i<5;i++){
				cout<<"insertando "<<i<<"usuario"<<endl;
				this->t->InsertarUsuarioenVector(auxiliar_1[i]);
				auxiliar2=this->t->getTotal_usuarios();
				}

				for (int i=aux; i< auxiliar2;i++){
					//cout << YELLOW<<i<<endl;
					cout<<"eliminando "<<i<<"usuario"<<endl;
					this->t->EliminarUsuarioVector(i);
				}
				if (this->getDebug()==true){
					cout <<DEBUG<< "mostrando tabla despues de eliminar los 5  alumnos"<<endl;
					cout <<CYAN<<"despues de eliminar "<<this->t->getTotal_usuarios()-1<<NORMAL<<endl;
				}				
			}
			break;

		case 'c':	





			
			
			auxiliar[0]=Manuel;
			auxiliar[1]=Antonio;
			auxiliar[2]=manu;


			for (int i=0;i<3;i++){

				this->t->InsertarUsuarioenVector(auxiliar[i]);	
				cout << "insertando foto"<<endl;
				cout<<DEBUG<< this->t->getTotal_usuarios();		
	
				this->t->InsertarFotoUsuarioTabla(foto1, this->t->getTotal_usuarios()-1);
				cout << "insertando foto"<<endl;		
				this->t->InsertarFotoUsuarioTabla(foto2, this->t->getTotal_usuarios()-1);;
				cout << "insertando foto"<<endl;		
				this->t->InsertarFotoUsuarioTabla(foto3, this->t->getTotal_usuarios()-1);
				cout << "insertando foto"<<endl;		
				this->t->InsertarFotoUsuarioTabla(foto4, this->t->getTotal_usuarios()-1);
				this->t->EliminarUsuarioVector(this->t->getTotal_usuarios()-1);
			}
			cout << SOLUCION<< "todo correcto"<<endl;	
			delete []auxiliar;
			auxiliar=0;
			break;
			
	

	
		case 'd':

			cout<<"1 foto"<<endl;
			this->t->print();

			this->t->EliminarMinimoFotosTabla(1);

			this->t->print();

			cout<<"2 fotos"<<endl;

			this->t->print();

			this->t->EliminarMinimoFotosTabla(2);

			this->t->print();
	
			cout<<"3 fotos"<<endl;

			this->t->print();

			this->t->EliminarMinimoFotosTabla(3);

			this->t->print();

			break;
	
	}
	delete[]auxiliar_1;
	auxiliar_1=0;
				
}


void Vista::EliminarFotosMinimo(){
	int fotos_min=0;

	cout<<CYAN<< "bienvenido al eliminar usuario por un numero minimo de fotografias"<<NORMAL<<endl;
	cout<<"Para comenzar, introduzca el numero mínimo de fotos: "<<endl;
	cin>> fotos_min;

	this->t->print();

	this->t->EliminarMinimoFotosTabla(fotos_min);

	this->t->print();	

}

void Vista::menu (char &opcion, bool &creada){


	cout <<GREEN_SUBRA<< "BIENVENIDOS A CRISTOBOOK, SELECCIONE UNA OPCION PARA COMENZAR."<<NORMAL<<endl;
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
	cout <<CYAN<< "Opcion m:"<<NORMAL<<"modo debug"<<endl;
	cout <<YELLOW<<"Opcion n:"<<NORMAL<<"testing"<<endl;
	cout <<DEBUG<< "Opcion s:"<<NORMAL<<"Salir"<<endl;
	cout <<PURPLE<< "Opcion o:"<<NORMAL<<"Prueba aptitud: eliminar Usuarios por minimo de fotos"<<endl;
	cout<<DEBUG<<"RECUERDA, SI NO CREAS LA TABLA ANTES, SOLO PODRÁS ACCEDER AL MODO DEBUG Y A SALIR"<<NORMAL<<endl;
	do{
		cin >> opcion;
		if(!creada){
			cout<<DEBUG<<"RECUERDA, SOLO PUEDES COMENZAR A USAR EL PROGRAMA UNA VEZ ESTE CREADA LA TABLA"<<NORMAL<<endl;
		}
	}while((!creada) && (opcion !='a')&& (opcion !='s')&& (opcion !='m'));
	
	switch (opcion) { // switch utilizado para el menú
        	case 'a': // caso para crear las tablas

			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "aoefnen" que se meta solo en la opcion a.
			if (!creada){
				creada=true;
				cout<<SOLUCION<<"Comenzando con la creacion inicial de la tabla"<<NORMAL<<endl;
				this->creacionInicial();
			}
			else{
				cout<<"La tabla ya esta creada golfo!!"<<endl;
			}
			break;
		case 'b':// caso de eliminar una tabla de usuarios
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "boefnen" que se meta solo en la opcion b.
			if(this->t->getTotal_usuarios()==0){
	
				cout<<DEBUG<<"NO TIENES NADA QUE ELIMINAAAR!!!!"<<endl;
			
			}
			else{
				cout<<" Vamos a proceder con la eliminación de la tabla"<<endl;
				this->t->~Tabla_usuarios();
				creada=false;
			}
			break;
		case 'c':// caso de imprimir una tabla de usuarios
		cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "coefnen" que se meta solo en la opcion c.
			this->t->print();

			break;
		case'd': // caso de insertar un usuario en una tabla de usuarios
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "doefnen" que se meta solo en la opcion d.
			this->InsertarUsuarioVista();

			break;
		case 'e':// caso de Eliminar un usuario de la tabla de usuarios 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "efnen" que se meta solo en la opcion e.
			if(this->t->getTotal_usuarios()==0){
	
				cout<<DEBUG<<"NO PUEDES SEGUIR ELIMINANDO USUARIOS!!!!"<<endl;
			
			}

			else{
				this->EliminarUsuarioVista();

			}

			break;
        	case 'f': // caso buscar por atributo login wn una tabla de usuarios
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "foefnen" que se meta solo en la opcion f.
			this->BuscarPorLoginDado();
			
			break;
		case 'g':// caso de ordenar por atributo totalfotos o por login 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "goefnen" que se meta solo en la opcion g.

			this->OrdenarTabla();

			break;

		case 'h':// caso de añadir una fotografia al usuario
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "hoefnen" que se meta solo en la opcion h.

			this->InsertarFotoDada();
			break;


		case'i': // caso de eliminar una foto del usuario
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "ioefnen" que se meta solo en la opcion i.
			this->EliminarFoto();
	
			break;
		case 'j':// caso de Imprimir todas las fotos de un usuario 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "joefnen" que se meta solo en la opcion j.
			this->ImprimirFotos();
			break;


		case 'k':// ejercicio extra 
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "koefnen" que se meta solo en la opcion k.
			this->ExtraVista();
				
			break;

		case 'm':// debug
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "moefnen" que se meta solo en la opcion m.
			this->CambiarDebug();
				
			break;
		case 'n':// testing
			cin.ignore(256,'\n');//lo utilizamos por si el usuario metee "noefnen" que se meta solo en la opcion n.
			this->testing();	

			break;
	
		case 's': //salir
			if(this->t->getTotal_usuarios()==0){
				cout<<"hasta pronto!!"<<endl;// la memoria se eliminará despues, puesto que se llamará al destructor.
			}
			if(this->t->getTotal_usuarios()!=0){
				cout<<"Primero voy a eliminar la memoria de la que no te quieres hacer cargo, golfoo!!"<<endl;
				this->t->~Tabla_usuarios();
			}
	
			break;
		case 'o': //prueba aptitud
			this->EliminarFotosMinimo();

			
	
			break;

		default:
			break;
	}
}

