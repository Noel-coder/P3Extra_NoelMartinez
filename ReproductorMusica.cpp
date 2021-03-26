#include "ReproductorMusica.h"

ReproductorMusica::ReproductorMusica() {
}

ReproductorMusica::~ReproductorMusica() {
}

vector<Genero*> ReproductorMusica::getGenero() {
	return this->generos;
}

void ReproductorMusica::setGenero(vector<Genero*>_generos) {
	this->generos=_generos;
}

vector<PlayList*> ReproductorMusica::getPlaylist(){
	return this->playlists;
}

void ReproductorMusica::agregarGenero(Genero* g) {
	this->generos.push_back(g);
}

void ReproductorMusica::agregarCancion(Cancion* c) {
	this->canciones.push_back(c);
}
void ReproductorMusica::agregarPlaylist(PlayList* p){
	this->playlists.push_back(p);
}

bool ReproductorMusica::validarAgregado() {
	while(generos.size() < 0) {
		return false;
	}
	return false;
}
//reproductor->getGeneros()[pos];
void ReproductorMusica::listarGenero(int pos) {
	for(int i = 0; i < generos.size(); i++) {
		if(pos==i) {
			Genero* genero = generos[i];
			cout <<"------" << "Genero #" << i <<"------"<<endl;
			cout <<"Nombre del Genero: "<< genero->getNombreGenero()<<endl;
		}
	}
}

void ReproductorMusica::listarCancion(int pos) {
	for(int i = 0; i < canciones.size(); i++) {
		if(pos==i) {
			Cancion* listarCancion = canciones[i];
			cout <<"------" << "Cancion #" << i <<"------"<<endl;
			cout <<"Cancion: "<< listarCancion->getNombreCancion()<<endl;
		}
	}
}

void ReproductorMusica::modificarGenero(int posicion, string nombre) {
	for(int i = 0; i < generos.size(); i++) {
		if(i==posicion) {
			generos.at(i)->setNombreGenero(nombre);
		}
	}
}

void ReproductorMusica::modificarCancion(int pos,string nombre,string artista, string duracion) {
	for(int i = 0; i < canciones.size(); i++) {
		if(i==pos) {
			canciones.at(i)->setNombreCancion(nombre);
			canciones.at(i)->setArtista(artista);
			canciones.at(i)->setDuracion(duracion);
		}
	}
}

void ReproductorMusica::eliminarGenero(int posicion) {
	for(int i=0; i < generos.size(); i++) {
		if(i==posicion) {
			generos.erase(generos.begin()+1);
		}
	}
}

void ReproductorMusica::eliminarCancion(int posicion) {
	for(int i=0; i < canciones.size(); i++) {
		if(i==posicion) {
			canciones.erase(canciones.begin()+1);
		}
	}
}



void ReproductorMusica::listarCanciones() {
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

void ReproductorMusica::listarGeneros() {
	for(int i=0; i < generos.size(); i++) {
		Genero* genero = generos[i];
		cout << "------"<< "Genero #"<< i << "------" << endl;
		cout << "Nombre del Genero: "<<genero->getNombreGenero()<<endl;
		cout << endl;
	}
}
