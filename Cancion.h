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
		Cancion(int,string,string,Genero*,string);
		Cancion(int);
		Cancion(string);
		void guardarCancion(ofstream*);
		Cancion* cargarUsuario(ifstream*,vector<Genero*>);
		int getIdCancion();
		void setIdCancion(int);
		string getNombreCancion();
		void setNombreCancion(string);
		string getArtista();
		void setArtista(string);
		Genero* getGenero();
		void setGenero(Genero*);
		string getDuracion();
		void setDuracion(string);
	private:
		int idCancion;
		string nombreCancion;
		string artista;
		Genero* genero;
		string duracion;
};

#endif