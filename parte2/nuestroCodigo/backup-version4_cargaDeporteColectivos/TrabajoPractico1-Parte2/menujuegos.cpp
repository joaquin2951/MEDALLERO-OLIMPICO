#include <iostream>
#include <windows.h>
#include <limits>
#include "configuraciones.h"
#include "menuprincipal.h"


using namespace std;




void volviendo(){//pantalla de VOLVIENDO al menu anterior
	system("cls");
	short X=60, Y=15;
	
	centrar(X,Y,'Y');
	cout << "Volviendo al menú anterior" << endl;
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2);
	for(int i = 0; i < 20; i++){
		centrar(X,Y,'X');
		Sleep(100);
		cout << "|||||" ;
	}
	
	Y+=3;
	centrar(X,Y,'0');
	
}
	
void MedalleroPais(){
	system("cls");
	gotoxy(65,16);
	cout << "1.- Funcionalidad en desarrollo" << endl;
	Sleep(segundosAMilisegundos(2));
	volviendo();
}
	
void MedalleroDeporte(){
	system("cls");
	gotoxy(65,16);
	cout << "2.- Funcionalidad en desarrollo" << endl;
	Sleep(segundosAMilisegundos(2));
	volviendo();
}
		
		
void TopMedallero(){
	system("cls");
	gotoxy(65,16);
	cout << "3.- Funcionalidad en desarrollo" << endl;
	Sleep(segundosAMilisegundos(2));
	volviendo();
}
			
	
	
void menujuegos(){//AHORA LLAMADO MENÚ MEDALLERO
	//system("mode con: cols=120 lines=30");
	
	char opcion;
	bool bandera = false;
	
	do{
		short X = 75,Y = 15;
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		cout << "Menú Medallero" << endl;
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		cout << "1.- Medallero por País" << endl;
		centrar(X,Y,'Y');
		cout << "2.- Medallero por Deporte" << endl;
		centrar(X,Y,'Y');
		cout << "3.- Top Medallero" << endl;
		centrar(X,Y,'Y');
		cout << "X.- Volver al menú principal" << endl;
		Y+=2;
		centrar(X,Y,'Y');
		cout << "Ingrese una opción: ";
		cin >> opcion;
		switch(opcion){
			case '1':
				MedalleroPais();
				break;
			case '2':
				MedalleroDeporte();
				break;
			case '3':
				TopMedallero();
				break;
			case 'X':
			case 'x':
				bandera=true;
				volviendo();
				Sleep(1000);
				break;
			default:
				gotoxy(75,27);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4);
				cout << "¡OPCION INVALIDA!" << endl;
				Sleep(700);
			}
	} while(!bandera);
		
}//FIN MENU JUEGOS


