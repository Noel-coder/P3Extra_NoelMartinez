#ifndef ALBUM_H
#define ALBUM_H
#include "Cancion.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Album {
	public:
		Album();
		~Album();
		void guardarAlbum(ofstream*);
		Album* cargarAlbum(ifstream*, vector<Cancion*>);
	private:
		string nombre;
		vector<Cancion*> canciones;
};

#endif