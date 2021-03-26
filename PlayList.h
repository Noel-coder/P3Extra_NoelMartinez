#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Cancion.h"
#include "Album.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class PlayList
{
	public:
		PlayList();
		~PlayList();
		PlayList(string,int);
		PlayList(string);
		PlayList(string,vector<Cancion*>);
		void guardarPlaylist(ofstream*);
		PlayList* cargarPlaylist(ifstream*, vector<Cancion*>);
		string getNombre();
		void setNombre(string);
		vector<Cancion*> getCanciones();
		void setCanciones(vector<Cancion*>);
		PlayList* operator + (Album*);
		PlayList* operator+ (Cancion*);
		PlayList* operator+ (PlayList*);
		PlayList* operator- (Cancion*);
		PlayList* operator- (Genero*);
		void agregarPlaylist();
	private:
		string nombre;
		vector<Cancion*> canciones;
};

#endif