#ifndef CANCION_H
#define CANCION_H
#include "Genero.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Cancion
{
	public:
		Cancion();
		~Cancion();
		void guardarCancion(ofstream*);
		Cancion* cargarUsuario(ifstream*,vector<Genero*>);
		int getIdCancion();
		void setIdCancion(int);
		string getNombre();
		void setNombre(string);
		Genero* getGenero();
		void setGenero(Genero*);
		string getDuracion();
		void setDuracion(string);
	private:
		int idCancion;
		string nombre;
		Genero* genero;
		string duracion;
};

#endif