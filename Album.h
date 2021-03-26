#ifndef ALBUM_H
#define ALBUM_H
#include "Cancion.h"
#include "PlayList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Album {
	public:
		Album();
		~Album();
		Album(string);
		Album(string,vector<Cancion*>);
		void guardarAlbum(ofstream*);
		Album* cargarAlbum(ifstream*, vector<Cancion*>);
		string getNombre();
		void setNombre(string);
		string getArtista();
		void setArtista(string);
		Album* operator *(int);
		Album* operator +(Cancion*);
		void listarCanciones();
		vector<Cancion*> getCancion();
		void setCancion(vector<Cancion*>);
	private:
		string nombre;
		vector<Cancion*> canciones;
		string artista;
		//perdonameee tuve que crearla ya que no tenia tiempo y no me salia sin esta variable T_T
};

#endif