#include "Cancion.h"
#include "Genero.h"
#include "PlayList.h"
#include "Album.h"
#include "ReproductorMusica.h"
#include <iostream>
using namespace std;

int main() {
	int opcion;
	while(opcion != 5) {
		cout << "Menu" << endl
		     << "1. Mantenimiento: " << endl
		     << "2. Sobrecargar el operador *: " << endl
		     << "3. Sobrecargar el operador +: "<< endl
		     << "4. Sobrecargar el operador -: "<<endl
		     << "5. Salir "<<endl;
		cout << "Ingrese una opcion: " << endl;
		cin>>opcion;
		switch(opcion) {
			case 1: {
				int opcionSubmenu=1;
				while(opcionSubmenu!=6) {
					cout<< "[Mantenimiento]" << endl
					    << "1. SubMenu Agregar" << endl
					    << "2. SubMenu Modificar" << endl
					    << "3. Eliminar: " << endl
					    << "4. Listar canciones y generos: " << endl
					    << "5. Listar albumes y playlists: " << endl
					    << "6. Regresar al menu principal: " << endl;
					cout << "Ingrese una opcion: " << endl;
					cin >> opcionSubmenu;
					switch(opcionSubmenu) {
						case 1: {
							int opcionMenuAgregar=1;
							while(opcionMenuAgregar!=3) {
								cout << "1. Agregar Genero: " << endl
								     << "2. Agregar Cancion: " << endl
								     << "3. Regresar al Menu" << endl;
								cout << "Ingrese una opcion: "<< endl;
								cin >> opcionMenuAgregar;
								switch(opcionMenuAgregar) {
									case 1: {
										//agregar Genero
										string nombreGenero;
										cout<<"Ingrese el nombre del genero: " << endl;
										cin >> nombreGenero;
										//generos.push_back(new Genero(nombreGenero));
										break;
									}
									case 2: {
										//agregar Cancion
										string nombreCancion,artista,duracion;
										int pos=0;
										cout<<"Ingrese el nombre de la cancion: "<<endl;
										cin >> nombreCancion;
										cout << "Ingrese el nombre del artista: "<<endl;
										getline(cin,artista);
										//listo los generos
										//aqui eligira uno y ese debo mandarlo al constructor
										cout << "Ingrese la posicion del genero que desee: "<<endl;
										cin >>pos;
										cout <<"------Generos------"<<endl;
										/*for(int i = 0; i < generos.size(); i++) {
											if(pos==i) {
												Genero* genero = generos[i];
												cout << i<<") "<<"Nombre: "<< genero->getNombreGenero() <<endl;

											}
											cout << "Ingrese la duracion con el formato [minuto:segundos]: " << endl;
											cin >> duracion;
											canciones.push_back(new Cancion(nombreCancion,artista,generos[i],duracion));*/
										break;
									}
									case 3: {
										//volver al menu
										break;
									}
								}
							}
						}
						case 2: {
							int opcionMenuModificar=1;
							while(opcionMenuModificar!=3) {
								cout << "1. Modificar Genero: " << endl
								     << "2. Modificar Cancion: " << endl
								     << "3. Regresar al Menu: " << endl;
								cout<< "Ingrese una opcion: "<<endl;
								cin >> opcionMenuModificar;
								switch(opcionMenuModificar) {
									case 1: {
										//modificar Genero


										break;
									}
									case 2: {
										//modificar Cancion

										break;
									}
									case 3: {
										//volver al menu
										break;
									}
								}
							}
							break;
						}
						case 3: {
							//Eliminar genero o cancion

							break;
						}
						case 4: {
							//listar
							/*for(int i = 0; i < canciones.size(); i++) {
								Cancion *listadoCanciones = canciones[i];
								cout <<"------" << "Cancion #" << i <<"------"<<endl;
								cout << "Nombre de la Cancion: "<< listadoCanciones->getNombre() << endl;
								cout << "Nombre de la Artista: " << listadoCanciones->getArtista() << endl;
								cout << "Nombre del Genero: " << genero->getNombreGenero() << endl;
								cout << "Duracion: "<< listadoCanciones->getDuracion() << endl;
								cout << endl;*/
							break;
						}
						case 5: {

							break;
						}
						case 6: {
							//menu principal
							break;
						}
					}
				}
			}
			case 2: {
				//sobrecargar operador *

				break;
			}
			case 3: {
				//sobrecargar operador +

				break;
			}
			case 4: {
				//sobrecargar operador -
				break;
			}
			case 5: {
				cout << "Gracias por usar el programa" << endl;
				break;
			}
		}
	}

	return 0;
}