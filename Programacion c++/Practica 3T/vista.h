
#include <iostream>
#include "Tabla_usuarios.h"
using namespace std;

class Vista {

	private:
		Tabla_usuarios *t;
		bool debug;

	public:

		/**
		@brief constructor clase vista
		@post el objeto será creado correctamente
		*/
		Vista();
		/**
		@brief constructor clase vista
		@pre el onjeto deberá de estar creado previamente.
		@post el objeto será eliminado correctamente
		*/
		~Vista();
		/**
		@brief método que sirve para rellenar el debug de una Vista
		@param bool debug. vaariable de tipo bool que tendrá asignado el valor que le asignaremos a debug
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo debug pasará a tener asignado el valor de debug.
		*/
		void setDebug (bool debug);
		/** 
		@brief método que sirve para devolver el debug de una vista
		@pre. el debug del objeto debe de estar relleno
		@return devolverá un bool que llevará asignado el valor de debug
		@post. el valor de debug será devuelto correctamente
		*/
		bool getDebug ();
		/**
		@brief modulo que sirve para realizar el testing
		@pre el objeto debe de estar creado previamente
		@return nad. es un procedimiento
		@post la tabla será testada correctamente
		*/

		void testing();
		/**
		@brief modulo que sirve para ver todas las opciones que podremos hacer durante la práctica
		@param char opcion. opcion que utilizaremos para enrar en el menu
		@param bool creada. variable que utilizaremos para el filtrado del menu
		@pre deberemos de crear un objeto vista previamente
		@return nada. es un procedimiento
		@post el menu se mostrara correctammente
		*/
		void menu (char &opcion, bool &creada);
		/**
		@brief metodo que utilizaremos para insertar los primeros usuarios en la tabla
		@pre. eel objeto vista deberá de estar creado previamente.
		@return nada. es un procedimiento
		@post la Tabla de Usuarios estará actualizada.
		*/

		void creacionInicial();
		/*
		@brief módulo que sirve para introducir una usuario en un objeto vista
		@pre. el objeto deberá de estar creado previamente
		@return nada. es un procedimietno
		@post el usuario rellenado estará impreso correctamente
		*/

		void InsertarUsuarioVista();
		/*
		@brief módulo que sirve para eliminar un usuario en un objeto vista
		@pre. el objeto deberá de estar creado previamente y totalusuarios>0
		@return nada. es un procedimietno
		@post el usuario se eliminará correctamente
		*/

		void EliminarUsuarioVista();
		/**
		@brief metodo que sirve para interactuar con el usuario y buscar el login que el nos diga.
		@pre. totalUsuarios >0
		@return nada. es un procedimiento
		@post si se encuentra el usuario, se imprimirá por pantalla
		*/

		void BuscarPorLoginDado();
		/**
		@brief método que sirve para insertar una foto en un usuario interactuando con el administrador
		@pre totlUsuarios>0
		@return nada. es un procedimiento
		@post la foto se insertará correctamente si es un usuario normal.
		*/
		void InsertarFotoDada();
		/**
		@brief método que sirve para eliminar una foto en un usuario interactuando con el administrador
		@pre totlUsuarios>0
		@return nada. es un procedimiento
		@post la foto se eliminará correctamente si es un usuario normal.
		*/
		void EliminarFoto();
		/**
		@brief método que utilizaremos para imprimir las fotos de un usuario
		@pre TotalUsuarios>0. en caso de que un usuario no tenga fotos, podrá imprimirse tambien, pero se mostrará un mensaje de error
		@return nada. es un procedimiento
		@post el vector de fotos se imprimirá correctamente.
		*/
		void ImprimirFotos();
		/**
		@brief método que utilizaremos para ordenar una tabla con dos criterios distintos
		@pre TotalUsuarios>0. 
		@return nada. es un procedimiento
		@post La tabla de usuarios estará ordenada correctamente
		*/
		void OrdenarTabla();
		/**
		@método que sirve para buscar un fragmento interactuando con el usuario
		@pre debe de haber creado un administrados.
		@retunr nada. es un procedimiento
		@post las rutas que tengan el fragmento se imprimirán
		*/
		void ExtraVista();
		/**
		@brief. metodo que servirá para activar o desactivar todos los debug de todo el programa
		@pre el objeto vista deberá de estar creado
		@return nada. es un procedimiento
		@post los debug serán activados.
		*/
		void CambiarDebug();
		/**
		@brief. metodo que servirá eliminar aquellos usuarios que tengan un minimo de fotos.
		@pre el objeto vista deberá de estar creado y totalUsuarios de nuestra tabla de usuarios deberá de ser > 0

		@return nada. es un procedimiento
		@post los usuarios serán correctamente eliminados, y su impresion será eliminado correctamente
		*/
		void EliminarFotosMinimo();

};
