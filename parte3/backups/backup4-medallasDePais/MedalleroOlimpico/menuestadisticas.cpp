#include <iostream>
#include <limits>
#include <windows.h>
#include "configuraciones.h"
#include "menuprincipal.h"
#include "menujuegos.h"
#include "menuestadisticas.h"
#include "paises.h"


using namespace std;

archivoCompetencia arch;//traemos la estructura de archivoCompetencia generada en menuPrincipal para poder hacer uso
//de la misma en este menuEstadisticas

int total_medallas[197][2]={0};//matriz que guarda ID del pais en la pos 0 y la cant. de medallas totales en la pos 1

void paisesPremiadosDeporte(){
	
}

void paisMasDeportesIndiv(){
	
}

void medallasDelPais()
{
	int opcion;
	bool bandera = false;
	
	do{
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		
		listarPaises();//imprimo todos los paises
		
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		gotoxy(14, 25); cout << "SELECCIONE UN PAIS O PULSE '0' PARA SALIR: ";
		gotoxy(59,25); cin >> opcion;
		
		if(opcion == 0)
			bandera = true;
		else
		{
			if(opcion > 197 || opcion < 1){
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
				gotoxy(14,28); cout << "ID INCORRECTO, INTENTE NUEVAMENTE" << endl;
				Sleep(1000);
			}
			else{
				
				//buscamos el pais en la matriz total_medallas, que está ordenada segun la cantidad de medallas de cada pais
				bool encontrado = false;
				int pos = 0;
				while(!encontrado && pos < 197)
				{
					if(total_medallas[pos][0] == opcion)
						encontrado = true;
					else
						pos++;
				}
				
				if(encontrado){
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //Texto verde
					gotoxy(14,28); imprimirPais(total_medallas[pos][0]); 
					gotoxy(14,29); cout << "HA GANADO " << total_medallas[pos][1] << " MEDALLAS" << endl;
				}else
				{
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //Texto verde
					gotoxy(14,28); imprimirPais(opcion); 
					gotoxy(14,29); cout << "NO HA GANADO MEDALLAS" << endl;
				}
				
				Sleep(2000);
			}
		}
		
	} while(!bandera);
	
	volviendo();
}

void paisMasMedallas()
{
	char opcion;
	bool bandera = false;
	
	do{
		
		
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		gotoxy(14,10); cout << "EL PAIS QUE MAS MEDALLAS HA GANADO ES ";
		gotoxy(54,10); imprimirPais(total_medallas[0][0]);
		gotoxy(14,13); cout << "CON " << total_medallas[0][1] << " MEDALLAS" << endl;
		
		gotoxy(14,4); cout << "PRESIONE X PARA VOLVER AL MENU ANTERIOR" << endl;
		gotoxy(54,4); cin >> opcion;
		
		if(opcion == 'X')
			bandera = true;
		
		
	} while(!bandera);
	
	volviendo();
}

void menuEstadisticas(){
	char opcion;
	bool bandera = false;
	arch = obtenerArchivo();
	generarTop(total_medallas,arch.deporte_medallas);
	
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
			paisMasMedallas();
			break;
		case '2':
			medallasDelPais();
			break;
		case '3':
			paisMasDeportesIndiv();
			break;
		case '4':
			paisesPremiadosDeporte();
			break;
		case 'X':
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

