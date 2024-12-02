#ifndef CONFIGURACIONES_H

void configuracionConsola();
void gotoxy(short x, short y);
int segundosAMilisegundos(int segundos);
void centrar(short & X, short & Y, char incrementar);//lo usamos para centrar los datos en pantalla, utilizando dentro la funcion gotoxy();
void generarLinea(char Caracter, int Longitud); //genera una linea recta para los menu
void saliendo();//pantalla que muestra una CARGA mientras se sale del programa
#endif
