#include <iostream>
#include <windows.h>
#include <limits>
#include "configuraciones.h"
#include "menujuegos.h"


using namespace std;

void cargarMedallas(){
	
	char opcion;
	
	
	while(opcion != 'X'){
		system("cls");
		short X = 75,Y = 15;
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
			"Menú Carga de Medallas " << endl;  centrar(X,Y,'Y'); //centrar menu
			
		generarLinea('=',25); centrar(X,Y,'Y');
			
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
		cout <<
			"1. Carga por País" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"2. Carga por Deporte" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"3. Carga por Deporte Individual" << endl;  centrar(X,Y,'Y'); //centrar men
		cout <<
			"4. Carga por Deporte Colectivo" << endl;  centrar(X,Y,'Y'); //centrar me
		cout <<
			"5. Carga por Categoría Deportiva" << endl;  centrar(X,Y,'Y'); //centrar menunuu
								
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); 
		cout << 
			"X. Volver al Menú Principal" << endl;  centrar(X,Y,'Y'); //centrar menu
									
									
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		Y++; centrar(X,Y,'X'); //centrar menu
		cout <<
			"Ingrese una opción: ";  
									
		X+=20;
		centrar(X,Y,'X');
					
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		cin >> opcion; //El usuario ingresa la opcion
									
		switch(opcion){
										
			case '1': ;
			case '2': ;
			case '3': ;
			case '4': ;
			case '5': system("cls"); cout << "funcionalidad en desarrollo, vuelva pronto" << endl;
			Sleep(segundosAMilisegundos(2)); volviendo(); break;
									
			case 'X': volviendo(); break;
			default: Y+=6; X=66; centrar(X,Y,'n'); 
			cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
			Sleep(segundosAMilisegundos(1)); cin.ignore(); cin.clear();   break;
									
					}//FIN SWITCH
									
	}//FIN WHILE
	
}//FIN Cargar_Medallas

void confirmarSalida(){
	char opcion;
	
	
	while(opcion != '1' and opcion!= '2'){
	system("cls");
	short X = 65,Y = 15;
	cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
	centrar(X,Y,'Y'); //centrar menu	
	cout << 
		"¿Estás seguro que deseas salir del programa?" << endl;  centrar(X,Y,'Y'); //centrar menu
		
		generarLinea('=',25); centrar(X,Y,'Y');
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
		cout <<
			"1. Sí" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"2. No" << endl;  centrar(X,Y,'Y'); //centrar menu
				
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		Y++; centrar(X,Y,'A'); //centrar menu
		cout <<
			"Ingrese una opción: ";  
			
		Y--; X+=20;
		centrar(X,Y,'X');
		cin >> opcion; //El usuario ingresa la opcion
			
		switch(opcion){
				
			case '1': saliendo(); break;
			case '2': break;
			default: Y+=6; X=66; centrar(X,Y,'n'); 
			cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
			Sleep(segundosAMilisegundos(1));  break;
			
		}//FIN SWITCH
	}//FIN DE WHILE
}//FIN DE FUNCION CONFIRMARSALIDA()
	
void menuPrincipal(){
	
char opcion;
	
	
while(opcion != 'X'){
	short X = 75,Y = 15;
	system("cls");
	cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
	centrar(X,Y,'Y'); //centrar menu	
	cout << 
		"Menú Principal " << endl;  centrar(X,Y,'Y'); //centrar menu
		
		generarLinea('=',25); centrar(X,Y,'Y');
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
		cout <<
			"1. Cargar Medallas" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"2. Mostrar Medallero" << endl;  centrar(X,Y,'Y'); //centrar menu
			
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); 
		cout << 
			"X. Salir de la aplicación" << endl;  centrar(X,Y,'Y'); //centrar menu
					
					
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		Y++; centrar(X,Y,'A'); //centrar menu
		cout <<
			"Ingrese una opción: ";  
					
		Y--; X+=20;
						
		centrar(X,Y,'X');
						
		cin >> opcion; //El usuario ingresa la opcion
						
		switch(opcion){
							
			case '1': cargarMedallas(); break;
			case '2': menujuegos(); break;
			case 'X': char opcionSalir; opcionSalir=' '; while(opcionSalir != '1' and opcionSalir != '2'){
						system("cls");
						short X = 65,Y = 15;
						cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos	
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
						centrar(X,Y,'Y'); //centrar menu	
						cout << 
							"¿Estás seguro que deseas salir del programa?" << endl;  centrar(X,Y,'Y'); //centrar menu
					
						generarLinea('=',25); centrar(X,Y,'Y');
					
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
						cout <<
							"1. Sí" << endl;  centrar(X,Y,'Y'); //centrar menu
						cout <<
							"2. No" << endl;  centrar(X,Y,'Y'); //centrar menu
							
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
						Y++; centrar(X,Y,'A'); //centrar menu
						cout <<
							"Ingrese una opción: ";  
							
						Y--; X+=20;
						centrar(X,Y,'X');
						cin >> opcionSalir; //El usuario ingresa la opcion
							
						switch(opcionSalir){
								
							case '1': saliendo(); break;
							case '2': opcion = 'a'; break;
							default: Y+=6; X=66; centrar(X,Y,'n'); 
							cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
							Sleep(segundosAMilisegundos(1));  break;
							
						}//FIN SWITCH
						}; break;
			
			
			default: Y+=6; X=66; centrar(X,Y,'n'); 
		cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
		Sleep(segundosAMilisegundos(1));  break;
						
					}//FIN SWITCH
						
	}//FIN WHILE
	
}//FIN FUNCION	
