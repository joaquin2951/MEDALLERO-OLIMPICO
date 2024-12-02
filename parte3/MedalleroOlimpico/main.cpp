#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime> //usada para obtener la fechaActual en pantalla login y funcion contrasenia()
#include "paises.h"
#include "deportes.h"
#include "bienvenida.h"
#include "menuprincipal.h"
#include "menujuegos.h"
#include "configuraciones.h"
#include "login.h"
using namespace std;





int main (int argc, char *argv[]) {
	
	int intentos = 0; //sera pasado por referencia en la funcion login()
	configuracionConsola();
	
	while(!GetAsyncKeyState(VK_RETURN)){//muestra la funcion bienvenida() hasta que se toque ENTER
		
		bienvenida();
		Sleep(segundosAMilisegundos(2));//3000 milisegundos ___ 3 segundos
		
	}
	
	
	
	system("cls");//limpia la pantalla
	
	login(intentos);
	
	if(intentos < 3)
		menuPrincipal();
	else{
		system("cls");
		gotoxy(55,15); generarLinea('=',60);
		gotoxy(55,17); cout << "Usted ha alcanzado el máximo de intentos, la aplicación se cerrará. " << endl;
		gotoxy(55,19); generarLinea('=',60);
		Sleep(segundosAMilisegundos(2));
		saliendo();
	}
	
	
	
	
	
	
	
	system("pause");
	
	
	return 0;
}



