#ifndef REPRODUCTORMUSICA_H
#define REPRODUCTORMUSICA_H
#include "Cancion.h"
#include "Genero.h"
#include "PlayList.h"
#include "Album.h"
#include <vector>
#include <string>
using namespace std;
class ReproductorMusica {
	public:
		ReproductorMusica();
		~ReproductorMusica();
		void cargarArchivos(string,string,string,string);
		void escribirCanciones(string);
		void escribirAlbumes(string);
		void escribirGeneros(string);
		void escribirPlaylists(string);
	private:
		vector<Cancion*> canciones;
		vector<Genero*> generos;
		vector<PlayList*> playlists;
		vector<Album*> albumes;
};

#endif