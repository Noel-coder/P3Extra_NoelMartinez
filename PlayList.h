#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Cancion.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class PlayList
{
	public:
		PlayList();
		~PlayList();
		PlayList(string,int);
		PlayList(string,vector<Cancion*>);
		void guardarPlaylist(ofstream*);
		PlayList* cargarPlaylist(ifstream*, vector<Cancion*>);
		string getNombre();
		void setNombre(string);
		vector<Cancion*> getCanciones();
		void setCanciones(vector<Cancion*>);
		PlayList* operator+(Cancion*);
		void agregarPlaylist();
	private:
		string nombre;
		vector<Cancion*> canciones;
};

#endif