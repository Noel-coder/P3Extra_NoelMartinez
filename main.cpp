#include "Cancion.h"
#include "Genero.h"
#include "PlayList.h"
#include "Album.h"
#include "ReproductorMusica.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int opcion;
	ReproductorMusica* reproductor = new ReproductorMusica();
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
				while(opcionSubmenu!=8) {
					cout<< "[Mantenimiento]" << endl
					    << "1. Agregar: " << endl
					    << "2. Modificar: " << endl
					    << "3. Eliminar: " << endl
					    << "4. Listar Canciones: " << endl
					    << "5. Listar Generos: " <<endl
					    << "6. Listar albumes: " << endl
					    << "7. Listar Playlists: " << endl
					    << "8. Regresar al menu principal: " << endl;
					cout << "Ingrese una opcion: " << endl;
					cin >> opcionSubmenu;
					switch(opcionSubmenu) {
						case 1: {
							int opcionMenuAgregar=1;
							while(opcionMenuAgregar!=3) {
								cout << "1. [Agregar Genero]: " << endl
								     << "2. [Agregar Cancion]: " << endl
								     << "3. Regresar al Menu" << endl;
								cout << "Ingrese una opcion: "<< endl;
								cin >> opcionMenuAgregar;
								switch(opcionMenuAgregar) {
									case 1: {
										//agregar Genero
										string nombreGenero;
										int idGenero;
										cout<<"Ingrese el id del Genero: "<<endl;
										cin>>idGenero;
										cout<<"Ingrese el nombre del genero: " << endl;
										getline(cin,nombreGenero);
										getline(cin,nombreGenero);
										Genero* genero = new Genero(idGenero,nombreGenero);
										reproductor->agregarGenero(genero);
										cout << "El genero ha sido agregado con exito"<<endl;
										break;
									}
									case 2: {
										//agregar Cancion
										string nombreCancion,artista,duracion;
										int pos=0,idCancion;
										if(reproductor->getGenero().size()==0) {
											cout<<"Para poder crear una cancion, primero debe crear un genero!"<<endl;
										}
										cout<<"Ingrese el id de la cancion: "<<endl;
										cin>>idCancion;
										cout<<"Ingrese el nombre de la cancion: "<<endl;
										getline(cin,nombreCancion);
										getline(cin,nombreCancion);
										cout << "Ingrese el nombre del artista: "<<endl;
										getline(cin,artista);
										//listo los generos
										//aqui eligira uno y ese debo mandarlo al constructor
										reproductor->listarGeneros();
										cout<<endl;
										cout << "Ingrese la posicion del genero que desee: "<<endl;
										cin >>pos;
										cout << "Ingrese la duracion con el formato [minuto:segundos]: " << endl;
										cin >> duracion;

										Cancion* cancion = new Cancion(idCancion,nombreCancion,artista,reproductor->getGenero()[pos],duracion);
										reproductor->agregarCancion(cancion);
										cout << "La cancion ha sido agregada al genero seleccionado" << endl;
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
								cout << "1. [Modificar Genero]: " << endl
								     << "2. [Modificar Cancion]: " << endl
								     << "3. Regresar al Menu: " << endl;
								cout<< "Ingrese una opcion: "<<endl;
								cin >> opcionMenuModificar;
								switch(opcionMenuModificar) {
									case 1: {
										//modificar Genero
										string nombreGenero;
										int posicion;
										reproductor->listarGeneros();
										cout << "Ingrese la posicion del genero a modificar: "<<endl;
										cin>>posicion;
										cout << "Genero que se esta modificando..."<<endl;
										reproductor->listarGenero(posicion);
										cout<<"Ingrese el nuevo nombre del genero: " << endl;
										getline(cin,nombreGenero);
										getline(cin,nombreGenero);
										reproductor->modificarGenero(posicion,nombreGenero);
										cout << "Actualizando..." << endl;
										cout << "El genero ha sido modificado con exito:"<<endl;
										reproductor->listarGeneros();
										cout <<endl;
										break;
									}
									case 2: {
										//modificar Cancion
										string nombreCancion,artista,duracion;
										int posicion;
										reproductor->listarCanciones();
										cout << "Ingrese la posicion de la Cancion a modificar: "<<endl;
										cin>>posicion;
										cout << "Cancion que se esta modificando..."<<endl;
										reproductor->listarCancion(posicion);
										cout << "Ingrese el nombre de la nueva cancion: "<<endl;
										getline(cin,nombreCancion);
										getline(cin,nombreCancion);
										cout << "Ingrese el nombre del artista: "<<endl;
										cin>>artista;
										cout << "Ingrese la duracion de la cancion: "<<endl;
										cin>>duracion;
										reproductor->modificarCancion(posicion,nombreCancion,artista,duracion);
										cout << "Actualizando..." << endl;
										cout << "La Cancion ha sido modificado con exito:"<<endl;
										reproductor->listarCanciones();
										cout <<endl;
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
							int opcionEliminar=1;
							while(opcionEliminar!=3) {
								cout << "1. [Eliminar Genero]: " << endl
								     << "2. [Eliminar Cancion]: " << endl
								     << "3. Regresar al Menu: " << endl;
								cout<< "Ingrese una opcion: "<<endl;
								cin >> opcionEliminar;
								switch(opcionEliminar) {
									case 1: {
										//eliminar genero
										int idGenero;
										cout << "Ingrese el id del genero a eliminar: "<<endl;
										cin>>idGenero;
										cout << "Genero que se esta eliminando..."<<endl;
										reproductor->listarGenero(idGenero);
										Genero* genero = new Genero(idGenero);
										cout<<"Eliminando..."<<endl;
										cout<< "El Genero ha sido eliminado con exito!" << endl;
										reproductor->listarGenero(idGenero);
										cout<<endl;
										break;
									}
									case 2: {
										//eliminar cancion
										int idCancion;
										cout << "Ingrese el id de la cancion a eliminar: "<<endl;
										cin>>idCancion;
										cout << "Cancion que se esta eliminando..." <<endl;
										reproductor->listarCancion(idCancion);
										Cancion* cancion = new Cancion(idCancion);
										cout<<"Eliminando..."<<endl;
										cout<< "La Canciom ha sido eliminado con exito!" << endl;
										reproductor->listarCancion(idCancion);
										cout<<endl;
										break;
									}
									case 3: {
										//regresar al menu
										break;
									}
								}
							}
							break;
						}
						case 4: {
							//listar Canciones
							reproductor->listarCanciones();

							break;
						}
						case 5: {
							//listar Generos
							reproductor->listarGeneros();
							break;
						}
						case 6: {
							break;
						}
						case 7: {

							break;
						}
						case 8: {
							//menu principal
							break;
						}
					}
				}
			}
			case 2: {
				//sobrecargar operador *

				int prueba =3;
				Genero* genero = new Genero(1,"bachate");
				Cancion* cancion1 = new Cancion(1,"hola","noel",genero,"1:20");
				Cancion* cancion2 = new Cancion(2,"adaw","vale",genero,"3:20");
				vector<Cancion*> canciones;
				canciones.push_back(cancion1);
				canciones.push_back(cancion2);
				Album* album = new Album("Stereo Azul",canciones);
				PlayList* playlist = new PlayList();
				playlist=album->operator*(prueba);
				cout << "Nombre: "<<playlist->getNombre()<<"Tamano: "<<playlist->getCanciones().size()<<endl;
				break;
			}
			case 3: {
				//sobrecargar operador +
				int opcionmas=1;
				while(opcionmas!= 5) {
					cout << "1. [Agregar Cancion a Playlist]: " << endl
					     << "2. [Agregar todas las canciones de un álbum a una playlist]: " << endl
					     << "3. [Agregar Cancion a Album]: "<<endl
					     << "4  [Unificar dos Playlists]: "<<endl
					     << "5. Regresar al Menu: " << endl;
					cout<< "Ingrese una opcion: "<<endl;
					cin >> opcionmas;
					switch(opcionmas) {
						case 1: {
							int elegir,idCancion;
							string nombrePlaylist;
							cout<< "Si desea crear una Playlist ingrese [1] o si desea utilizar una ya existente ingrese [2]" <<endl;
							cin>>elegir;
							if(elegir==1) {
								//Crear Playlist
								cout<<"Ingrese el nombre de su Playlist: "<<endl;
								cin>>nombrePlaylist;
								reproductor->listarCanciones();
								cout<<"Por medio de su ID ingrese las canciones que desea agregar a su Playlist: "<<endl;
								cin>>idCancion;
								PlayList* playlist = new PlayList(nombrePlaylist,idCancion);
								reproductor->agregarPlaylist(playlist);
							} else if(elegir==2) {
								if(reproductor->getPlaylist().size()==0) {
									cout<< "No hay ninguna Playlist creada, Por favor cree una nueva Playlist" <<endl;
								}
							}
							break;
						}
						case 2: {

							break;
						}
						case 3: {

							break;
						}
						case 4: {

							break;
						}
						case 5: {

							break;
						}
					}
				}
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