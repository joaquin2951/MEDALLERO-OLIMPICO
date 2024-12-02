#ifndef MENUPRINCIPAL_H

struct competidores{
	int paises[16];//el máximo de países que pueden participar son 16. las ID de los paises van del 1 al 196.
	int tl; //el minimo es de 4 paises
};

void cargaPorDeporteIndividual(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas);
void cargaPorDeporteColectivo(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas);
bool busquedaPais(const competidores compe,const int TLcompe, const int IDpais);
void generarCompetencia();
void cargarMedallas(bool & cargaDeMedallas);//pantalla que muestra el menu de  CARGA DE MEDALLAS
void menuPrincipal();//pantalla que muestra el menu principal
void confirmarSalida();//la funcion que nos pregunta si estamos seguros de salir o no del programa



#endif
