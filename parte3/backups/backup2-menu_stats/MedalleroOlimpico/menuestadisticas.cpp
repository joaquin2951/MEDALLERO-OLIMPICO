#include <iostream>
#include <limits>
#include <windows.h>
#include "configuraciones.h"
#include "menuprincipal.h"
#include "menujuegos.h"
#include "menuestadisticas.h"


using namespace std;

archivoCompetencia arch = obtenerArchivo();//traemos la estructura de archivoCompetencia generada en menuPrincipal para poder hacer uso
//de la misma en este menuEstadisticas


void menuEstadisticas(){
	char opcion;
	bool bandera = false;

	
	do{
		short X = 75,Y = 15;
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		cout << "Menú Estadísticas" << endl;
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		cout << "1.- País con más medallas" << endl;
		centrar(X,Y,'Y');
		cout << "2.- Medallas del país" << endl;
		centrar(X,Y,'Y');
		cout << "3.- País con más deportes individuales" << endl;
		centrar(X,Y,'Y');
		cout << "4.- Países premiados del deporte" << endl;
		centrar(X,Y,'Y');
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << "X.- Volver al menú principal" << endl;
		Y+=2;
		centrar(X,Y,'Y');
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		cout << "Ingrese una opción: ";
		cin >> opcion;
		switch(opcion){
		case '1':
			
			break;
		case '2':
			
			break;
		case '3':
			
			break;
		case '4':
			
			break;
		case 'x':
			bandera=true;
			volviendo();
			Sleep(1000);
			break;
		default:
			gotoxy(75,27);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4);//TEXTO ROJO - ERROR
			cout << "¡OPCION INVALIDA!" << endl;
			Sleep(700);
		}
	} while(!bandera);
	
}//FIN FUNCION	

