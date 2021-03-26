#include "Album.h"

Album::Album()
{
}

Album::~Album()
{
}

Album::Album(string _nombre, vector<Cancion*> _canciones){
	this->nombre=_nombre;
	this->canciones=_canciones;
}

PlayList* Album::operator*(int prueba){
	string name = this->nombre+" "+std::to_string(prueba)+" veces";
	vector<Cancion*>songs;
	for(int i = 0; i < prueba; i++){
		for(int j=0; j < this->canciones.size();j++){
			songs.push_back(this->canciones.at(j));
		}
	}
	PlayList* playlist = new PlayList(name,songs);
	return playlist;                              
}       
	