#include <iostream>
#include "configuraciones.h"
#include <windows.h>

using namespace std;


void aro(short  & X, short & Y){
	
	centrar(X,Y,'Y');
	cout << "  .,::OOO::,.    " << endl; centrar(X,Y,'Y');
	cout << ".:\'         `:. " << endl; centrar(X,Y,'Y');
	cout << ":\"           \": "  << endl; centrar(X,Y,'Y');
	cout << ":,            \" "<< endl; centrar(X,Y,'Y');
	cout << " :,,         ,:    "<< endl; centrar(X,Y,'Y');
	cout << "  `^OOoo:\"O^'   " << endl; centrar(X,Y,'Y');
	
	
}
	
void logo(){
	short X = 55, Y = 4;
	//medallero
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12);
	centrar(X,Y,'Y');
	
	cout << "___  ___ ___________  ___   _      _      ___________ _____ " << endl; centrar(X,Y,'Y');
	cout << "|  \\/  ||  ___|  _  \\/ _ \\ | |    | |    |  ___| ___ \\  _  |" << endl; centrar(X,Y,'Y');
	cout << "| .  . || |__ | | | / /_\\ \\| |    | |    | |__ | |_/ / | | |" << endl; centrar(X,Y,'Y'); 
	cout << "| |\\/| ||  __|| | | |  _  || |    | |    |  __||    /| | | |" << endl; centrar(X,Y,'Y');
	cout << "| |  | || |___| |/ /| | | || |____| |____| |___| |\\ \\\\ \\_/ /" << endl; centrar(X,Y,'Y');
	cout << "\\_|  |_/\\____/|___/ \\_| |_/\\_____/\\_____/\\____/\\_| \\_|\\___/ " << endl << endl; 
	
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9);
	X = 57; Y++; 
	aro(X,Y);
	
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
	X = 74; Y = 11; 
	aro(X,Y);
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4);
	X = 91; Y = 11; 
	aro(X,Y);
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6);
	X = 64; Y = 15; 
	aro(X,Y);
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 10);
	X = 84; Y = 15; 
	aro(X,Y);
	
}

	

	
void bienvenida(){
	
	logo();
	
	
	gotoxy(69,25);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
	cout << "Si desea avanzar presione ENTER" << endl;
	
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); 
	gotoxy(45,30);
	
	cout << "Albaristo Ignacio D.     -    Gallardo Ricardo E.     -     Hernandez Joaquin" << endl;
	
	
}


