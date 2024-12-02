#include <iostream>
#include <windows.h>

using namespace std;

int segundosAMilisegundos(int segundos){
	return segundos*1000;
}
	
void configuracionConsola(){
	HWND hwnd = GetConsoleWindow();// Obtener el manejador de la consola
	system("mode con: cols=150 lines=200");
	system("color 70");
	ShowWindow(hwnd, SW_MAXIMIZE);// Maximizar la ventana de la consola
	
}

	
void gotoxy(short x, short y){
	COORD cp = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

	
void centrar(short & X, short & Y, char incrementar){
	gotoxy(X,Y);
	switch(incrementar){
		case 'X': X++; break;
		case 'Y': Y++; break;
		case 'A': X++; Y++; break;
	}
		
}

	
void generarLinea(char Caracter, int Longitud){
	for(int i = 0; i < Longitud ; i++){
		cout << Caracter;
	}
}

	
void saliendo(){
	system("cls");
	short X=60, Y=15;
		
	centrar(X,Y,'Y');
	cout << "Usted esta saliendo del programa" << endl;
		
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2);
	for(int i = 0; i < 40; i++){
		centrar(X,Y,'X');
		Sleep(100);
		cout << "|||||" ;
	}
		
	Y+=3;
	centrar(X,Y,'0');
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 13);
	cout << "Adios!" << endl;
	
}
