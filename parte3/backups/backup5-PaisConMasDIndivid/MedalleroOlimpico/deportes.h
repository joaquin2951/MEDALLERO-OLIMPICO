#ifndef DEPORTES_H
void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();
bool perteneceADeporteIndividual(const int indice);
bool perteneceADeporteColectivo(const int indice);
#endif
