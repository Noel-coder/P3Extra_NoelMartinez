#include "Album.h"

Album::Album()
{
}

Album::~Album()
{
}

Album::Album(string _nombre){
	this->nombre=_nombre;
}

string Album::getNombre(){
	return this->nombre;
}

void Album::setNombre(string _nombre){
	this->nombre = _nombre;
}

Album::Album(string _nombre, vector<Cancion*> _canciones){
	this->nombre=_nombre;
	this->canciones=_canciones;
}

vector<Cancion*> Album::getCancion(){
	return this->canciones;
}

void Album::setCancion(vector<Cancion*> _canciones){
	this->canciones=_canciones;
}

string Album::getArtista(){
	return this->artista;
}

void Album::setArtista(string _artista){
	this->artista=_artista;
}

void Album::listarCanciones() {
	for(int i = 0; i < canciones.size(); i++) {
		Cancion* cancion = canciones[i];
		cout <<"------" << "Cancion #" << i <<"------"<<endl;
		cout << "Nombre de la Cancion: "<< cancion->getNombreCancion() << endl;
		cout << "Nombre del Genero: " << cancion->getGenero()->getNombreGenero()<<endl;
		cout << "Nombre de la Artista: " << cancion->getArtista() << endl;
		cout << "Duracion: "<< cancion->getDuracion() << endl;
		cout << endl;
	}
}

Album* Album::operator *(int numero){
	
	vector<Cancion*> canciones;
	
	for(int i = 0; i < numero; i++){
		for(int j = 0; j < canciones.size(); j++){
			Cancion* cancion = new Cancion();
			cancion = canciones.at(j);
			canciones.push_back(cancion);
		}
	}
	string nombreAlbum = this->nombre +" "+std::to_string(numero) + " veces";
	Album* album = new Album(nombreAlbum,canciones);
	return album;
	
}

Album* Album::operator +(Cancion* cancion){
	string nombreCancion = nombre;
	Album* newAlbum = new Album(nombreCancion);
	
	vector<Cancion*> listaCancion = this->canciones;
	listaCancion.push_back(cancion);
	newAlbum->setCancion(listaCancion);
	
	return newAlbum;
	
}

     
	