#ifndef REPRODUCTORMUSICA_H
#define REPRODUCTORMUSICA_H
#include "Cancion.h"
#include "Genero.h"
#include "PlayList.h"
#include "Album.h"
#include <vector>
#include <string>
#include <iostream>
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
		void agregarGenero(Genero*);
		void agregarCancion(Cancion*);
		void agregarPlaylist(PlayList*);
		void agregarAlbumes(Album*);
		void modificarGenero(int,string);
		void modificarCancion(int,string,string,string);
		bool validarAgregado();
		void eliminarGenero(int);
		void eliminarCancion(int);
		void listarCanciones();
		void listarCancion(int);
		void listarGenero(int);
		void listarGeneros();
		void listarAlbumes();
		void listarPlaylist();
		vector<Genero*> getGenero();
		void setGenero(vector<Genero*>);
		vector<PlayList*> getPlaylist();
		void setPlaylist(vector<PlayList*>);
		vector<Cancion*> getCancion();
		void setCancion(vector<Cancion*>);
		vector<Album*>getAlbum();
		void setAlbum(vector<Album*>);
		private:
		vector<Cancion*> canciones;
		vector<Genero*> generos;
		vector<PlayList*> playlists;
		vector<Album*> albumes;
};

#endif