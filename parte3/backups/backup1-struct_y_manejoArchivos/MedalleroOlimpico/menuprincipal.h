#ifndef MENUPRINCIPAL_H
#include <ctime>
using namespace std;

struct competidores{
	int paises[16];//el máximo de países que pueden participar son 16. las ID de los paises van del 1 al 196.
	int tl; //el minimo es de 4 paises
};

struct archivoCompetencia{
	competidores competencia[87];
	int deporte_medallas[87][3];
	tm *fechaCreacion;
	int legajo;
};

void cargaPorDeporteIndividual(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas);
void cargaPorDeporteColectivo(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas);
bool busquedaPais(const competidores compe,const int TLcompe, const int IDpais);
void generarCompetencia();
void cargarMedallas(bool & cargaDeMedallas);//pantalla que muestra el menu de  CARGA DE MEDALLAS
void menuPrincipal();//pantalla que muestra el menu principal
void confirmarSalida();//la funcion que nos pregunta si estamos seguros de salir o no del programa
void cargarDeportes_Medallas2(int deportes_medallas2[87][3]);
void inicializarMedallero(int deporte_medallas[87][3]);
void menuGenerarCompetencia(bool & competenciaGenerada, bool & cargaDeMedallas);
void generarBin(archivoCompetencia & file);//genera el archivo .bin para guardar la estructura archivoCompetencia
void cargarBin(bool & competenciaGenerada,archivoCompetencia & file);//para poder abrir un archivo que el usuario nos indique
void actualizarBin();//se ejecuta luego de confirmar que queremos salir del programa, actualiza los datos en el archivo binario correspondiente
#endif
