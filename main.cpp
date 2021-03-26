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
										if(reproductor->getGenero().size()!=0) {
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
										} else {
											cout<<"ERROR...Para Crear una cancion, primero debe haber un genero!!"<<endl;
										}
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
							//listar albumes
							reproductor->listarAlbumes();
							break;
						}
						case 7: {
							//listar playlists
							reproductor->listarPlaylist();
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
				if(reproductor->getAlbum().size()!=0) {
					int idAlbum, repetir;
					reproductor->listarAlbumes();
					cout<<"Ingrese el indice del album que desea utilizar: ";
					cin>>idAlbum;

					while(idAlbum<0 || idAlbum>reproductor->getAlbum().size()) {
						cout<<"El album no puede ser negativo o no existe!"<<endl;
						cout<<"Ingrese el indice del album que desea utilizar: ";
						cin>>idAlbum;
					}

					cout<<"Ingrese el numero de veces a multiplicar: ";
					cin>>repetir;

					while(repetir<=1) {
						cout<<"El numero debe ser mayor a 1 !";
						cout<<"Ingrese el numero de veces a multiplicar: ";
						cin>>repetir;
					}

					Album* album = new Album();
					album = reproductor->getAlbum().at(idAlbum);
					Album* newAlbum = new Album();
					newAlbum = album->operator *(repetir);
					PlayList* play = new PlayList(newAlbum->getNombre(),newAlbum->getCancion());
					reproductor->agregarPlaylist(play);

					cout<<"PlayList: "<<endl;
					cout<<"Nombre: "<<play->getNombre()<<endl;
					cout<<"Canciones: "<<endl;
					play->agregarPlaylist();
				}
				case 3: {
					//sobrecargar operador +
					int opcionmas=1;
					while(opcionmas!= 5) {
						cout << "1. [Agregar Cancion a Playlist]: " << endl
						     << "2. [Agregar todas las canciones de un album a una playlist]: " << endl
						     << "3. [Agregar Cancion a Album]: "<<endl
						     << "4  [Unificar dos Playlists]: "<<endl
						     << "5. Regresar al Menu: " << endl;
						cout<< "Ingrese una opcion: "<<endl;
						cin >> opcionmas;
						switch(opcionmas) {
							case 1: {
								//agregar cancion a playlist
								int elegir,idCancion;
								string nombrePlaylist;
								cout<< "Si desea crear una Playlist ingrese [1] o si desea utilizar una ya existente ingrese [2]" <<endl;
								cin>>elegir;
								if(elegir==1) {
									//Crear Playlist
									cout<<"Ingrese el nombre de su Playlist: "<<endl;
									cin>>nombrePlaylist;
									reproductor->listarCanciones();
									cout<<"Por medio de su ID Ingrese la cancion que desea agregar a su Playlist: "<<endl;
									cin>>idCancion;
									while(idCancion < 0 || idCancion>reproductor->getCancion().size()) {
										cout<< "El id de la cancion no puede ser negativa o no se ha encontrado!"<<endl;
										cout<<"Por medio de su ID Ingrese la cancion que desea agregar a su Playlist: "<<endl;
										cin>>idCancion;
									}
									PlayList* playlist = new PlayList(nombrePlaylist);
									Cancion* song = new Cancion();
									song = reproductor->getCancion().at(idCancion);
									cout << "La cancion que se agregara a su playlist: "<< song->getNombreCancion()<<endl;
									PlayList* newPlaylist = new PlayList();
									newPlaylist = playlist->operator+(song);
									reproductor->agregarPlaylist(newPlaylist);
								} else if(elegir==2) {
									if(reproductor->getPlaylist().size()==0) {
										cout<< "No hay ninguna Playlist creada, Por favor cree una nueva Playlist" <<endl;
									}
								}
								break;
							}
							case 2: {
								//Agregar todas las canciones de un album a una playlist
								int idAlbum,idPlaylist;
								reproductor->listarAlbumes();
								cout<<"Ingrese el id del album que desea agregar a la playlist: ";
								cin>>idAlbum;
								while(idAlbum<0 || idAlbum>reproductor->getAlbum().size()) {
									cout<<"ERROR!...El album no puede ser negativo o no se encuentra! Intentelo de nuevo"<<endl;
									cout<<"Ingrese el id del album que desea agregar a la playlist: ";
									cin>>idAlbum;
								}
								Album* album = new Album();
								album=reproductor->getAlbum().at(idAlbum);
								reproductor->listarPlaylist();
								cout<<"Ingrese el id de la playlist que desea agregar: ";
								cin>>idPlaylist;
								while(idPlaylist<0 || idPlaylist>reproductor->getPlaylist().size()) {
									cout<<"ERROR!...La playlist no puede ser negativa o no se encuentra! Intentelo de nuevo"<<endl;
									cout<<"Ingrese el id de la playlist que desea agregar: ";
									cin>>idPlaylist;
								}
								PlayList* playlist = new PlayList();
								playlist = reproductor->getPlaylist().at(idPlaylist);

								PlayList* newPlaylist = new PlayList();
								newPlaylist = playlist->operator +(album);
								reproductor->agregarPlaylist(newPlaylist);
								break;
							}
							case 3: {
								//Agregar Cancion a Album
								int elegir,idCancion;
								string nombreAlbum;
								cout<< "Si desea crear una Album ingrese [1] o si desea utilizar una ya existente ingrese [2]" <<endl;
								cin>>elegir;
								if(elegir==1) {
									//Nuevo album
									cout<<"Ingrese el nombre del album: ";
									cin>>nombreAlbum;
									reproductor->listarCanciones();
									cout<<"Ingrese el id de la cancion que desea agregar: ";
									cin>>idCancion;

									while(idCancion<0 || idCancion>reproductor->getCancion().size()) {
										cout<<"ERROR!...La Cancion no puede ser negativa o no se encuentra! Intentelo de nuevo"<<endl;
										cout<<"Ingrese el id de la cancion que desea agregar: ";
										cin>>idCancion;
									}
									Album* album = new Album(nombreAlbum);
									Cancion* cancion = new Cancion();
									cancion = reproductor->getCancion().at(idCancion);
									Album* newAlbum = new Album();

									newAlbum = album->operator +(cancion);

									newAlbum->setArtista(cancion->getArtista());

									reproductor->agregarAlbumes(newAlbum);

								} else if(elegir==2) {
									//Ya existente
									int idAlbum,idCancion,contador = 0;;
									reproductor->listarAlbumes();
									cout<<"Ingrese el indice del album: ";
									cin>>idAlbum;

									Album* album = new Album();
									album = reproductor->getAlbum().at(idAlbum);

									reproductor->listarCanciones();
									cout<<"Ingrese el indice de la cancion que desea agregar: ";
									cin>>idCancion;
									Cancion* cancion = new Cancion();
									cancion = reproductor->getCancion().at(idCancion);

									Album* albumTemporal = new Album();
									albumTemporal = album->operator +(cancion);

									for(int i = 0; i < albumTemporal->getCancion().size(); i++) {
										Cancion* cancion = new Cancion();
										cancion = albumTemporal->getCancion().at(i);
										if(cancion->getArtista()!=cancion->getArtista()) {
											contador++;
										}
									}

									if(contador>0) {
										album->setArtista("Various Artists");
									}

									album->setCancion(albumTemporal->getCancion());
								}
								break;
							}
							case 4: {
								//union playlists
								reproductor->listarPlaylist();
								int idPlaylist,idPlaylist2;

								cout<<"Ingrese el id de la primera playlist: ";
								cin>>idPlaylist;
								while(idPlaylist<0 || idPlaylist>reproductor->getPlaylist().size()) {
									cout<<"ERROR!...Esa playlist no puede ser negativa o no se encuentra! Intentelo de nuevo"<<endl;
									cout<<"Ingrese el id de la primera playlist: ";
									cin>>idPlaylist;
								}

								cout<<"Ingrese el id de la segunda playlist: ";
								cin>>idPlaylist2;
								while(idPlaylist2>reproductor->getPlaylist().size() || idPlaylist2<0) {
									cout<<"ERROR!...Esa playlist no puede ser negativa o no se encuentra! Intentelo de nuevo"<<endl;
									cout<<"Ingrese el id de la segunda playlist: ";
									cin>>idPlaylist2;
								}
								PlayList* playlist1 = new PlayList();
								PlayList* playlist2 = new PlayList();

								playlist1 = reproductor->getPlaylist().at(idPlaylist);
								playlist2 = reproductor->getPlaylist().at(idPlaylist2);
								PlayList* newPlaylist = new PlayList();

								newPlaylist = playlist1->operator +(playlist2);
								reproductor->agregarPlaylist(newPlaylist);
								cout<<"La union de playlist se realizo correctamente!"<<endl;
								break;
							}
							case 5: {
								//regresar al menu principal
								break;
							}
						}
					}
					break;
				}
				case 4: {
					//sobrecargar operador -
					int opcionEliminarop=1;
					while(opcionEliminarop!=3) {
						cout << "1. [Eliminar canción o canciones de una playlist]: " << endl
						     << "2. [Eliminar las canciones de un género en específico Playlist]: " << endl
						     << "3. Regresar al Menu: " << endl;
						cout<< "Ingrese una opcion: "<<endl;
						cin >> opcionEliminarop;
						switch(opcionEliminarop) {
							case 1: {
								//Eliminar canción o canciones de una playlist
								int idPlaylist, idCancion;
								reproductor->listarPlaylist();;
								cout<<"Ingrese el id de la playlist que desea: ";
								cin>>idPlaylist;

								PlayList* playlist = new PlayList();
								playlist = reproductor->getPlaylist().at(idPlaylist);

								reproductor->listarCanciones();;
								cout<<"Ingrese el id de la cancion que desea eliminar: ";
								cin>>idCancion;

								Cancion* cancion = new Cancion();
								cancion = reproductor->getCancion().at(idCancion);

								PlayList* newPlaylist= new PlayList();

								newPlaylist = playlist->operator -(cancion);

								playlist->setCanciones(newPlaylist->getCanciones());
								break;
							}
							case 2: {
								//Eliminar las canciones de un género en específico Playlist
								int idPlaylist, idGenero;
								reproductor->listarPlaylist();
								cout<<"Ingrese el id de la playlist que desea: ";
								cin>>idPlaylist;
								PlayList* playlist = new PlayList();
								playlist = reproductor->getPlaylist().at(idPlaylist);
								reproductor->listarGeneros();
								cout<<"Ingrese el ide del genero que desea: ";
								cin>>idGenero;
								Genero* genero = new Genero();
								genero = reproductor->getGenero().at(idGenero);
								PlayList* newPlaylist = new PlayList();
								newPlaylist = playlist->operator -(genero);
								playlist->setCanciones(newPlaylist->getCanciones());
								break;
							}
						}
					}
					break;
				}
				case 5: {
					cout << "Gracias por usar el programa" << endl;
					break;
				}
			}
		}
	}
	return 0;
}