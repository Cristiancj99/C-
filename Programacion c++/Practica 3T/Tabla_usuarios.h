#include <iostream>
#include "usuario.h"

using namespace std;

class Tabla_usuarios{

	private: 

		Usuario ** puntero_a_puntero;
		int total_usuarios;
		bool debug;

		/**
		@brief método que utilizaremos para redimensionar el vector de punteroapunter
		@param int dim nueva. será la nueva dimension que tomará el vector 
		@pre el objeto deberá de estar credo previamente
		@return nada. es un procedimiento
		@post el nuevo vector tendrá la dimension e dimnueva
		*/
		void resize(int dim_nueva);
		/**
		@brief método que utilizaremos para asignarle un valor a total_usuarios
		@param int numero. variable de tipo int que llevará asignado el valor de total_usuarios
		@pre el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post el atributo total_usuarios pasará a tener el valor de numero.
		*/

		void setTotal_usuarios(int numero);

	public:

		/**
		@brief modulo que utilizaremos como constructor para el objeto Tabla_usuarios
		@post. el objeto estará creado correctamente
		*/

		Tabla_usuarios();
	
		/**
		@brief modulo que utilizaremos como destructor para el objeto Tabla_usuarios
		@pre el objeto deberá de estar creado previamente
		@post. el objeto será eliminado sin problemas.
		*/
		~Tabla_usuarios();

		/**
		@brief metodo que sirve para devolver el valor de total_usuarios
		@pre el atributo total_usuarios debe de estar relleno
		@return devolvera un int con el valor asignaado de total_usuarios
		@post el atributo total_usuarios será devuelto correctamente.
		*/

		int getTotal_usuarios ();
		/**
		@brief método que sirve para rellenar el debug de un taba_usuario
		@param bool debug. vaariable de tipo bool que tendrá asignado el valor que le asignaremos a debug
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo debug pasará a tener asignado el valor de debug.
		*/
		void setDebug (bool debug);
		/** 
		@brief método que sirve para devolver el debug de un tabla_usuarios
		@pre. el debug del objeto debe de estar relleno
		@return devolverá un bool que llevará asignado el valor de debug
		@post. el valor de debug será devuelto correctamente
		*/
		bool getDebug ();
		/**
		@brief método que utilizaremos para devolver un usuario de  puntero_a_puntero
		@param int posicion. variable de tipo int que llevará asignado la posicion a devolver
		@pre el objeto debe de estar creado previamente
		@return devolverá un puntero a un usuario
		@post se devolverá un puntero a usuaario
		*/

		Usuario* DevolverPosicion(int numero);
		/** 
		@brief método que sirve para imprimir una variable de tipo Tabla_Usuarios
		@pre total_usuarios>0
		@return nada. es un procecdimiento
		@post el objeto se imprimirá correctamente.
		*/

		void print();
	
		/**
		@brief método que sirve para insertar un usuario en el vector de puntero_a_puntero
		@pre el objeto debe de estar creado previamente
		@param usuario *u puntero que apunta al usuario que introduciremos en nuestro vector.
		@return nada. es un procedimiento
		@post el usuario quedará insertado correctamente.
		*/
		void InsertarUsuarioenVector(Usuario *u);
		/**
		@brief método que sirve para buscar por login e imprimir  un usuario en el vector de puntero_a_puntero
		@pre TotalUsuarios>0
		@param string u variable que utilizaremos para buscar
		@return nada. es un procedimiento
		@post si se encuentra, el usuario será imprimido correctamente.
		*/
		bool BuscarLogin(string u, int &posicion, bool imprimir);
		/**
		@brief método que sirve para introducir una foto en un usuario de nuestro vector
		@pre TotalUsuarios>0;
		@param Foto &f foto que utilizaremos para introducir en el vector
		@return nada. es un procedimietno
		@post el usuario será introducido correctamente
		*/
	 	void InsertarFotoUsuarioTabla(Foto &f, int i);
		/**
		@brief método que sirve para eliminar una foto en un usuario de nuestro vector
		@pre TotalUsuarios>0;
		@param int i posicion del vector con la cual interactuaremos.
		@param posicion_foto foto que eliminaremos
		@return nada. es un procedimietno
		@post la foto será eliminada correctamente
		*/
	 	void EliminarFotoUsuarioTabla(int i, int posicion_foto);
		/**
		@brief método que sirve para imprimirel vector de fotos en un usuario de nuestro vector
		@pre TotalUsuarios>0;
		@param int i. Posicion que ocupa el Usuario que imprimiremos
		@return nada. es un procedimietno
		@post el vector de fotos se imprimirá correctamente.
		*/
	 	void ImprimirFotosUsuarioTabla(int i);

		/**
		@brief método que utilizaremos para ordenar por login una tabla de usuarios
		@pre TotalUsuarios>0
		@return nada. es un procedimiento
		@post el vector puntero_a_puntero estará ordenado correctamente por el atributo login
		*/
		void OrdenarPorLogin();
	
		/**
		@brief método que utilizaremos para ordenar por TotalFotosUsuario una tabla de usuarios
		@pre TotalUsuarios>0
		@return nada. es un procedimiento
		@post el vector puntero_a_puntero estará ordenado correctamente por el atributo TotalFotosUsuario
		*/
		void OrdenarPorTotalFotos();

		/**
		@brief método que sirve para eliminar una posucion del vector puntero_a_puntero
		@pre totalUsuarios>o
		@param int i. Posicion que queremos eliminar.
		@return nada. es un procedimiento
		@post el usuario quedará eliminado correctamente y la dimension del vector disminuirá en uno
		*/			
		void EliminarUsuarioVector(int eliminar);

		/**
		@brief método que sirve para buscar un fragmento en las rutas de un usuario
		@pre TotalUsuarios>0
		@param string ruta. Ruta a buscar en las fotos.
		@retunr nada. es un procedimiento
		@post si el fragmento es encontrado, se imprimirá, la ruta donde ha sido encontrada.
		*/
		void ExtraFragmento (string fragmento, int posicion);
		/**
		@brief. metodo que servirá para activar o desactivar todos los debug, tanto de tabla_usuarios como de los usuarios que esta contenga
		@pre el objeto debe de estar creado, ya que aun sin tener ningun usuario dentro, podemos activar el debug del objeto.
		@param bool debug. variable que tendrá 
		@return nada. es un procedimiento
		@post los debug serán activados.
		*/
		void CambiarDebugTabla(bool debug);

		/**
		@brief método que sirve para imprimir solo los usuarios Normales de un vector polimórfico de usuarios.
		@pre TotaUsuarios>0
		@return nada. es un procedimiento
		@post se imprimirán correctamente 
		*/

		void printNormal();

		/** 
		@brief método que sirve para añadir Usuario a un vector de puntero_a_puntero
		@param Usuario *u. puntero que apuntará al objeto que introduciremos
		@param int i posicion donde introduciremos el usuario
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el Usuario estará insertada en el vector correctamente.
		*/

		void InsertarUsuarioVector(int i, Usuario *u);

		/** 
		@brief método que buscar aquellos usuarios con un minimo de fotos y eliminarlos de la tabla

		@param int fotos_min numero de fotos minimas que revisaremos

		@pre. TotalUsuarios > 0
		@return nada. es un procedimiento

		@post. los usuarios serán eliinados correctamente.
		*/

		void EliminarMinimoFotosTabla(int fotos_min);


};
