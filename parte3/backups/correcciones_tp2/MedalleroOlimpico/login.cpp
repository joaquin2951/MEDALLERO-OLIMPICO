#include <iostream>
#include <ctime>
#include <windows.h>
#include "configuraciones.h"
#include <limits>
using namespace std;



int contrasenia(int legajo){
	
	//Digitos
	int N1=(legajo%10);
	int N2=((legajo/100)%10)*10;
	int N3=(legajo/10000)*100;
	int N = N1+N2+N3;
	
	//Obtener capicua
	int capicua=N;
	
	while((capicua%10)!=(capicua/100))
		capicua++;
	
	//Anio actual
	time_t t = time(0);
	tm* now = localtime(&t);
	int anioActual = now->tm_year + 1900;
	
	int contrasenia_valida = (anioActual*capicua)+(legajo%1000);
	
return contrasenia_valida;
}	//fin de function contrasenia()

	
void dibujarRecuadro(int largoX,int altoY){
	
	short X = 56, Y = 17;
	
	for(int i = 0; i < altoY; i++){
		centrar(X,Y,'Y');
		cout << "|" ;
	}
		
	Y = 17; X = 56 + largoX;
		
	for(int i = 0; i < altoY; i++){
		centrar(X,Y,'Y');
		cout << "|" ;
	}
		
	Y = 17; X = 56;
	for(int i = 0; i <= largoX; i++){
		centrar(X,Y,'X');
		cout << "=" ;
	}
		
	Y = 17 + altoY; X = 56;
	for(int i = 0; i <= largoX; i++){
		centrar(X,Y,'X');
		cout << "=" ;
	}
		
}	//Fin de dibujarRecuadro();
	
void login(int & intentos){
	
	int const intentos_maximos=3;
	bool logueado = false;
	
	
	
	while(intentos < intentos_maximos and !logueado){
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		dibujarRecuadro(50,12);
		
		int legajo;    	      
		gotoxy(75,20); //centrar menu
		cout << "Legajo: "; 	gotoxy(83,20); //centrar menu
		cin >> legajo;   
		
		
		if(legajo >= 10000 and legajo <= 99999){
			int contrasenia_valida = contrasenia(legajo);
			int contrasenia_ingresada;
			
			gotoxy(75,24); //centrar menu
			cout << "Contraseña: ";
			gotoxy(87,24); //centrar menu
			cin >> contrasenia_ingresada;
			
			if(contrasenia_ingresada==contrasenia_valida){
				cout << "Login exitoso" << endl;
				logueado = true;
			}
			else{
				gotoxy(71,26); //centrar menu
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4); //error en rojo
				cout << "Contraseña Incorrecta." << endl;
				Sleep(segundosAMilisegundos(2));
				intentos++;
			}
		}
		else{
			gotoxy(66,22);//centrar menu
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4); //error en rojo
			cout << "Numero de legajo incorrecto." ;
			gotoxy(66,23);//centrar menu
			cout << "Debe ser un N° de 5 dígitos. ";
			Sleep(segundosAMilisegundos(2));
			intentos++;
		}
}//fin del while
	
	
	
	
}	//fin de function login()
	
	
	
