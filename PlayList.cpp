#include "PlayList.h"

PlayList::PlayList()
{
}

PlayList::~PlayList()
{
}

PlayList::PlayList(string _nombre,vector<Cancion*> _canciones){
	this->nombre=_nombre;
	this->canciones=_canciones;
}

PlayList::PlayList(string _nombre,int _id){
	
}

string PlayList::getNombre(){
	return this->nombre;
}

void PlayList::setNombre(string _nombre){
	this->nombre=_nombre;
}

vector<Cancion*> PlayList::getCanciones(){
	return this->canciones;
}

void PlayList::setCanciones(vector<Cancion*> _canciones){
	this->canciones=_canciones;
}

PlayList* PlayList::operator+(Cancion* c) {
	vector<Cancion*> canciones;
	canciones.push_back(c);
	PlayList* playlist = new PlayList(this->nombre, canciones);
	return playlist;
}

void PlayList::agregarPlaylist(){
	
}