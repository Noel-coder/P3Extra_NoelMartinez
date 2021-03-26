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

PlayList::PlayList(string _nombre){
	this->nombre=_nombre;
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

PlayList* PlayList::operator +(PlayList* playlist){
	vector<Cancion*> cancion;
	for(int i = 0; i < canciones.size(); i++){
		Cancion* _cancion = new Cancion();
		_cancion = canciones.at(i);
		cancion.push_back(_cancion);
	}
	for(int j = 0; j < playlist->getCanciones().size(); j++){
		Cancion* _cancion = new Cancion();
		_cancion = playlist->getCanciones().at(j);
		cancion.push_back(_cancion);
	}
	string toString = "union " + this->getNombre() + " " + playlist->getNombre();
	PlayList* newPlaylist = new PlayList(toString,cancion);
	
	return newPlaylist;
	
}

PlayList* PlayList::operator +(Album* album){
	PlayList* playlist = new PlayList(this->nombre);
	vector<Cancion*> cancion = canciones;
	for(int i = 0; i < album->getCancion().size(); i++){
		Cancion* _cancion = new Cancion();
		_cancion = album->getCancion().at(i);
		cancion.push_back(_cancion);
	}
	
	playlist->setCanciones(cancion);
	
	return playlist;
	
}

PlayList* PlayList::operator -(Cancion* c){
	PlayList* playlist = new PlayList(this->nombre);
	vector<Cancion*> cancion = this->getCanciones();
	
	for(int i = 0; i < cancion.size(); i++){
		Cancion* c = new Cancion();
		c = cancion.at(i);
		if(c->getNombreCancion()==c->getNombreCancion()){
			cancion.erase(cancion.begin() + i);
		}
	}
	
	playlist->setCanciones(cancion);
	
	return playlist;
	
}

PlayList* PlayList::operator -(Genero* genero){
	
	PlayList* playlist = new PlayList(this->nombre);
	
	vector<Cancion*> cancion = this->getCanciones();
	
	for(int i = 0; i < cancion.size(); i++){
		Cancion* c = new Cancion();
		c = cancion.at(i);
		Genero* genero = c->getGenero();
		if(genero->getNombreGenero()==genero->getNombreGenero()){
			cancion.erase(cancion.begin() + i);
		}
	}
	
	playlist->setCanciones(cancion);
	
	return playlist;
}

void PlayList::agregarPlaylist(){
	for(int i =0; i < canciones.size();i++){
		Cancion* cancion = canciones[i];
		cout <<"------" << "Cancion #" << i <<"------"<<endl;
		cout << "Nombre de la Cancion: "<< cancion->getNombreCancion() << endl;
		cout << "Nombre del Genero: " << cancion->getGenero()->getNombreGenero()<<endl;
		cout << "Nombre de la Artista: " << cancion->getArtista() << endl;
		cout << "Duracion: "<< cancion->getDuracion() << endl;
		cout << endl;
	}
}