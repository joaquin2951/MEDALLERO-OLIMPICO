#ifndef MENUJUEGOS_H
void volviendo();//pantalla que muestra una CARGA mientras se vuelve al menu anterior
void menujuegos();//pantalla que muestra el mnenu de juegos
void MedalleroPais(); //sub-pantalla dentro del menu de juegos
void MedalleroDeporte();//sub-pantalla dentro del menu de juegos
void TopMedallero();//sub-pantalla dentro del menu de juegos
void ordenarGrupo(int grupo[196][2], const int cfilas); //funcion para ordenar vectores de medallero
void mostrarGrupo(int grupo[196][2], const int cfilas,short coordX,short coordY);//funcion creada para mostrar los grupos como lista
void generarTop();
#endif
