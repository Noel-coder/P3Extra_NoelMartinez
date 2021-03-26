#include "Cancion.h"

Cancion::Cancion()
{
}

Cancion::~Cancion()
{
}

Cancion::Cancion(int _idCancion,string _nombreCancion, string _artista, Genero* _genero, string _duracion){
	this->idCancion=_idCancion;
	this->nombreCancion=_nombreCancion;
	this->artista=_artista;
	this->genero=_genero;
	this->duracion=_duracion;
}

Cancion::Cancion(string _nombreCancion){
	this->nombreCancion=_nombreCancion;
}

Cancion::Cancion(int _idCancion){
	this->idCancion=_idCancion;
}

int Cancion::getIdCancion(){
	return this->idCancion;
}

void Cancion::setIdCancion(int _idCancion){
	this->idCancion=_idCancion;
}

string Cancion::getNombreCancion(){
	return this->nombreCancion;
}

void Cancion::setNombreCancion(string _nombreCancion){
	this->nombreCancion=_nombreCancion;
}

string Cancion::getArtista(){
	return this->artista;
}

void Cancion::setArtista(string _artista){
	this->artista=_artista;
}

Genero* Cancion::getGenero(){
	return this->genero;
}

void Cancion::setGenero(Genero* _genero){
	this->genero = _genero;
}

string Cancion::getDuracion(){
	return this->duracion;
}

void Cancion::setDuracion(string _duracion){
	this->duracion=_duracion;
}