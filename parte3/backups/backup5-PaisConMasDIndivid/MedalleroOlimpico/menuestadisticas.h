#ifndef MENUESTADISTICAS_H
#define MENUESTADISTICAS_H

void menuEstadisticas(); //muestra el menú
void paisMasMedallas(); //muestra al usuario el nombre del pais que ganó más medallas, y cuántas ganó.
void medallasDelPais(); //el usuario elige un país y se muestran las medallas obtenidas del mismo
void paisMasDeportesIndiv();//Se muestra el nombre del país que tiene más cant. de medallas de deporte Individual, y su total de medallas.
void paisesPremiadosDeporte(); //Usuario ingresa una letra con la que comienza el deporte. Se muestra el podio de todos los deportes que comienzan con la letra ingresada,
//se muestra el podio, el nombre del deporte y los nombres de los países que han conformado el podio.
void calcularMedallasIndividuales(int medallas[197][2]);//calcula la cant. de medallas de cada pais en deport. Individuales
bool tieneMedallas(int podio[3], int idPais); // devuelve true si el pais tiene alguna medalla en ese deporte.
	
#endif
