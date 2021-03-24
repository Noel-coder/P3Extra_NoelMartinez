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
		void guardarGenero(ofstream*);
		Genero* cargarGenero(ifstream*);
		int getIdGenero();
		void setIdGenero(int);
	private:
		int idGenero;
		string nombre;
		
};

#endif