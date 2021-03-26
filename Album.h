#ifndef ALBUM_H
#define ALBUM_H
#include "Cancion.h"
#include "PlayList.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Album {
	public:
		Album();
		~Album();
		Album(string,vector<Cancion*>);
		void guardarAlbum(ofstream*);
		PlayList* operator*(int);
		Album* cargarAlbum(ifstream*, vector<Cancion*>);
	private:
		string nombre;
		vector<Cancion*> canciones;
};

#endif