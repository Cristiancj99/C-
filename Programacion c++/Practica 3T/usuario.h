#include <iostream>
#include "foto.h"
using namespace std;

class Usuario{

	protected:

		string login;
		string nombre;
		string apellido;
		string perfil;
		bool debug;

	public:

		/**
		@brief constructor  de Usuario
		@return nada. es un procedimiento
		@post se construirá un objeto de tipo Usuario.
		*/		
		Usuario();
		/**
		@brief método que utilizaremos como destructor
		@pre el objeto debe de estar creado
		@post el objeto estará eliminado correctamente.
		*/
		virtual ~Usuario();	
		/**
		@brief constructor por parametros de Usuario
		@param string login valor que le asignaemos al atributo login
		@string nombre valor que le asignaremos al atributo nombre
		@param string apellido valor que le asignaremos al atributo 
		@param string perfil_usuario valor que le asignremos al atributo perfil_usuario
		@return nada. es un procedimiento
		@post se construirá un objeto que con los parámetros mencionados anteriormente
		*/
		Usuario(string login, string nombre, string apellidos, string perfil_usuario);
		/** 
		@brief método que sirve para rellenar el login de un Usuario
		@param string login. vaariable de tipo string que tendrá asignado el valor que le asignaremos a login
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo login pasará a tener asignado el valor de login.
		*/
		void setLogin (string login);
		/**
		@brief método que sirve para rellenar el debug de un Usuario
		@param bool debug. vaariable de tipo bool que tendrá asignado el valor que le asignaremos a debug
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo debug pasará a tener asignado el valor de debug.
		*/
		void setDebug (bool debug);		
		/** 
		@brief método que sirve para rellenar el nombre de un Usuario
		@param string nombre. vaariable de tipo string que tendrá asignado el valor que le asignaremos a nombre
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo nombre pasará a tener asignado el valor de nombre.
		*/
		void setNombre (string nombre);
	
		/** 
		@brief método que sirve para rellenar el apellido de un Usuario
		@param string apellido. vaariable de tipo string que tendrá asignado el valor que le asignaremos a apellido
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo apellido pasará a tener asignado el valor de apellido.
		*/
		void setApellido (string apellido);

		/** 
		@brief método que sirve para rellenar el perfil_usuario de un Usuario
		@param string perfil. vaariable de tipo string que tendrá asignado el valor que le asignaremos a perfil
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo perfil_usuario pasará a tener asignado el valor de perfil.
		*/
		void setPerfil (string perfil);

		/** 
		@brief método que sirve para devolver el login de un Usuario
		@pre. el login del objeto debe de estar relleno
		@return devolverá un string que llevará asignado el valor de login
		@post. el valor de login será devuelto correctamente
		*/
		string getLogin ();
		/** 
		@brief método que sirve para devolver el nombre de un Usuario
		@pre. el nombre del objeto debe de estar relleno
		@return devolverá un string que llevará asignado el valor de nombre
		@post. el valor de nombre será devuelto correctamente
		*/
		string getNombre ();
		/** 
		@brief método que sirve para devolver el apellido de un Usuario
		@pre. el apellido del objeto debe de estar relleno
		@return devolverá un string que llevará asignado el valor de apellido
		@post. el valor de apellido será devuelto correctamente
		*/
		string getApellido ();
		/** 
		@brief método que sirve para devolver el Perfil_usuario de un Usuario
		@pre. el Perfil_usuario del objeto debe de estar relleno
		@return devolverá un string que llevará asignado el valor de Perfil_usuario
		@post. el valor de Perfil_usuario será devuelto correctamente
		*/
		string getPerfil_usuario ();
		/** 
		@brief método que sirve para devolver el debug de un Usuario
		@pre. el debug del objeto debe de estar relleno
		@return devolverá un bool que llevará asignado el valor de debug
		@post. el valor de debug será devuelto correctamente
		*/
		bool getDebug ();

		/**
		@brief método  que sirve para imprimir un objeto de tipo usuario
		@pre. el objeto debe de estar creado previamente y relleno
		@return nada. es un procedimiento
		@post. el objeto se imprimirá correctamente
		*/
		virtual void print();

};

class Admin : public Usuario{

	protected:

		// aqui estan declarados todos los atributos de usuario
		int total_consultas;
	public:
		
		/**
		@brief constructor  de Admin
		@return nada. es un procedimiento
		@post se construirá un objeto de tipo Usuario.
		*/		
		Admin();

		/**
		@brief método que utilizaremos como destructor
		@pre el objeto debe de estar creado
		@post el objeto estará eliminado correctamente.
		*/
		virtual ~Admin();
		/**
		@brief constructor por parametros de admin
		@param string login valor que le asignaemos al atributo login
		@string nombre valor que le asignaremos al atributo nombre
		@param string apellido valor que le asignaremos al atributo 
		@param string perfil_usuario valor que le asignremos al atributo perfil_usuario
		@return nada. es un procedimiento
		@post se construirá un objeto que con los parámetros mencionados anteriormente
		*/
		Admin(string login, string nombre, string apellidos, string perfil_usuario, int consultas);
		/** 
		@brief método que sirve para rellenar el total_consultas de un Usuario admin
		@param int numero. vaariable de tipo int que tendrá asignado el valor que le asignaremos a total_consultas
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo total_consultas pasará a tener asignado el valor de numero.
		*/
		void setTotal_consultas (int numero);

		/** 
		@brief método que sirve para devolver el total_consultas de un Usuario admin
		@pre. el atributo total_consultas deberá de estar relleno previamente
		@return devolverá un int que tendrá asignado el valor de total_consultas
		@post. total_consultas será devuelto correctamente.
		*/
		int getTotal_consultas ();
		/**
		@brief método  que sirve para imprimir un objeto de tipo admin
		@pre. el objeto debe de estar creado previamente y relleno
		@return nada. es un procedimiento
		@post. el objeto se imprimirá correctamente
		*/
		void print();
		/**
		@brief método  que sirve para buscar un fragmento en las fotos de nos usuarios normales
		@pre. deberá de haber creado al menos un admin
		@param string fragmento. fragmento que utilizaremos para buscar en el vector de fotos de un usuario normal
		@return nada. es un procedimiento
		@post. la cadena encontrada se imprimirá
		*/
		void BusquedaFragmento (string fragmento, Usuario *u);
};

class Normal : public Usuario{

	protected:

		// aqui estan declarados todos los atributos de usuario
		Foto * v_fotos;
		int TotalFotosUsuario;
		double saldo;
		int DimFotos;

		/**
		@brief modulo que sirve para redimensionar el vector de fotos (solo aumentará)
		@pre TotalFotosUsuario==DimFotos
		@param int dim_nueva dimension nueva que se le otorgará al vector(crecerá de 5 en 5)
		@post el vector pasará a tener la dimendion de dim_nueva
		*/
		void resize(int dim_nueva);
		/** 
		@brief método que sirve para rellenar la DimFotos de un Usuario normal
		@param int numero. variable de tipo int que tendrá asignado el valor que le asignaremos a DimFotos
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo DimFotos pasará a tener asignado el valor de numero.
		*/
		void setDimFotos (int numero);
		/** 
		@brief método que sirve para rellenar el TotalFotosUsuario de un Usuario normal
		@param int numero. variable de tipo int que tendrá asignado el valor que le asignaremos a TotalFotosUsuario
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo TotalFotosUsuario pasará a tener asignado el valor de numero.
		*/
		void setTotalFotosUsuario (int numero);

	public:

		/**
		@brief método que utilizaremos como constructor.
		@post el objeto Normal será creado correctamente
		*/
		Normal();
		/**
		@brief constructor por parametros de Normal
		@param string login valor que le asignaemos al atributo login
		@string nombre valor que le asignaremos al atributo nombre
		@param string apellido valor que le asignaremos al atributo 
		@param string perfil_usuario valor que le asignremos al atributo perfil_usuario
		@param doble salario. valor que le asignaremos al atributo salario
		@return nada. es un procedimiento
		@post se construirá un objeto que con los parámetros mencionados anteriormente
		*/
		Normal(string login, string nombre, string apellidos, string perfil_usuario, double salario, int util, int dim);
		/**
		@brief método que utilizaremos como destructor
		@pre. el objeto debe de estar creado previamente
		@post. el Usuario normal será eliminado correctamente.
		*/
		~Normal();
	



		/** 
		@brief método que sirve para rellenar el salario de un Usuario normal
		@param int numero. variable de tipo int que tendrá asignado el valor que le asignaremos a salario
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. el valor del atributo salario pasará a tener asignado el valor de numero.
		*/
		void setSaldo (double numero);



		/** 
		@brief método que sirve para devolver el TotalFotosUsuario de un Usuario Normal
		@pre. el atributo TotalFotosUsuario deberá de estar relleno previamente
		@return devolverá un int que tendrá asignado el valor de TotalFotosUsuario
		@post. TotalFotosUsuario será devuelto correctamente.
		*/
		int getTotalFotosUsuario ();
		/** 
		@brief método que sirve para devolver el salario de un Usuario Normal
		@pre. el atributo salario deberá de estar relleno previamente
		@return devolverá un int que tendrá asignado el valor de salario
		@post. salario será devuelto correctamente.
		*/
		double getSaldo ();
		/** 
		@brief método que sirve para devolver el DimFotos de un Usuario Normal
		@pre. el atributo DimFotos deberá de estar relleno previamente
		@return devolverá un int que tendrá asignado el valor de DimFotos
		@post. DimFotos será devuelto correctamente.
		*/
		int getDimFotos ();
		/** 
		@brief método que sirve para añadir Fotos a un usuario normal
		@param Foto f. puntero que apuntará al objeto que introduciremos
		@pre. el objeto debe de estar creado previamente
		@return nada. es un procedimiento
		@post. la foto estará insertada en el vector correctamente.
		*/

		void InsertarFotoVector(const Foto &f);

		/** 
		@brief método que sirve para eliminar una Foto a un usuario normal
		@param int i. posicion que queremos eliminar
		@pre. TotalFotosUsuario>0
		@return nada. es un procedimiento
		@post. la foto se eliminará en el vector correctamente.
		*/

		void eliminarFotoVector(int i);

		/**
		@brief modulo que imprimrá correctamente las fotos de un usuario.
		@pre TotalFotosUsuario >0
		@return nada. es un procedimiento 
		@post el vector de fotos será imprimido correctamente
		*/
		void imprimirVectorFotos();
		/**
		@brief método  que sirve para imprimir un objeto de tipo Normal
		@pre. el objeto debe de estar creado previamente y relleno
		@return nada. es un procedimiento
		@post. el objeto se imprimirá correctamente
		*/
		void print();
		/**
		@brief método  que sirve para devolver un objeto de tipo Foto
		@pre. TotalFotosUsuario>0
		@param int posicion. posicion que devolveremos del vector de fotos
		@return devolverá una variable de tipo Foto
		@post. la foto será devuelta correctamente
		*/
		Foto DevolverFotoVector(int posicion);
		/**
		@brief método  que sirve para insertar un objeto de tipo Foto en el vector de vfotos
		@pre. TotalFotosUsuario>0
		@param int posicion. posicion a la que le introduciremos la foto
		@param const Foto &f variable que introduciremos en el vector.
		@return nada. es un procedimiento
		@post. la foto será insertada correctamente
		*/
		void InsertarFotoVector(int posicion, const Foto &f);



};



