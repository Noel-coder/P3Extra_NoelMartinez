#ifndef GENERO_H
#define GENERO_H
#include <fstream>
#include <string>
using namespace std;
class Genero
{
	public:
		Genero();
		~Genero();
		Genero(int,string);
		Genero(string);
		Genero(int);
		void guardarGenero(ofstream*);
		Genero* cargarGenero(ifstream*);
		int getIdGenero();
		void setIdGenero(int);
		string getNombreGenero();
		void setNombreGenero(string);
	private:
		int idGenero;
		string nombreGenero;
		
};

#endif