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
		void guardarPlaylist(ofstream*);
		PlayList* cargarPlaylist(ifstream*, vector<Cancion*>);
	private:
		string nombre;
		vector<Cancion*> canciones;
};

#endif