#include "Genero.h"

Genero::Genero()
{
}

Genero::~Genero()
{
}

Genero::Genero(string _nombreGenero){
	this->nombreGenero= _nombreGenero;
}

Genero::Genero(int _idGenero){
	this->idGenero=_idGenero;
}
Genero::Genero(int _idGenero,string _nombreGenero){
	this->idGenero=_idGenero;
	this->nombreGenero= _nombreGenero;
}

string Genero::getNombreGenero(){
	return this->nombreGenero;
}

void Genero::setNombreGenero(string _nombreGenero){
	this->nombreGenero=_nombreGenero;
}