#include <iostream>
#include <windows.h>
#include <limits>
#include "configuraciones.h"
#include "menuprincipal.h"
#include "paises.h"
#include "deportes.h"

using namespace std;

int deporte_medallas2[87][3];
int TOP_ganadores[196][2] = {0};//primera col para ID, segunda para cant MEdallas Ganadas

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

	
	
//funcion creada para ordenar los grupos dejando las naciones con mas medallas obtenidas primero
void ordenarGrupo(int grupo[196][2], const int cfilas) {
	
	
	//hacemos un ordenamiento por seleccion
	for(int i = 0; i < cfilas - 1; i++){
		int mayor = grupo[i][1];//valor del mayor elemento
		int posMayor = i;//indice del mayor elemento
		
		for(int j = i + 1; j < cfilas; j++){
			
			if(grupo[j][1] > mayor){
				mayor = grupo[j][1]; //nuevo valor del mayor elemento
				posMayor = j; //nuevo indice de mayor elemento
			}
			
		}
		
		if(posMayor != i){	//si se encontró un nuevo mayor
			swap(grupo[posMayor][0], grupo[i][0]);
			swap(grupo[posMayor][1], grupo[i][1]);
		}
			
		
	}
	
}//fin del ordenamiento por seleccion
	

//funcion creada para mostrar los grupos como lista
void mostrarGrupo(int grupo[196][2], const int cfilas,short coordX,short coordY) {
	int colores_top = 0;
	
	for (int i = 0; i < cfilas; i++) {
		if (grupo[i][1] > 0 and (grupo[i][0] > 0 and grupo[i][0] < 197)) {
			
			switch(colores_top){
			case 0:  SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); colores_top++; break;
			case 1:  SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8);  colores_top++;break;
			case 2:  SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6);  colores_top++;break;
			default: SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);  break;
			}
			
			gotoxy(coordX,coordY);
			imprimirPais(grupo[i][0]);
			gotoxy(coordX+26,coordY);
			cout << grupo[i][1] << " medalla(s)" << endl; //los imprime segun id convirtiendo la ID en el nombre del pais
			coordY+=2;
		}
	}
	cout << endl;
	
}

void generarTop(){//generamos el TOP de los paises que más medallas ganaron
	
	int IDpais;
	
	for(int fil = 0; fil < 87; fil++){//recorre categorias de deportes (filas)
		for(int col = 0; col < 3; col++){//recorre las medallas, en este caso solo hay que sumar todas, no importa de qué importancia son.
			
			IDpais = deporte_medallas2[fil][col];//se guarda el ID del pais que ganó una medalla
			//si no hay deporte cargado, la FILA valdrá 0 en cada columna --> eso no será un ID existente (ID van de 1 a 196)
			if(IDpais > 0){
				TOP_ganadores[IDpais-1][0] = IDpais;   //le resto 1 ya que el vector se recorre de 0 a 195. En indice 0 está el pais con ID 1.
				TOP_ganadores[IDpais-1][1]++;//la columna 0 guarda el ID del pais, la col. 1 guarda las medallas totales del mismo
			}
			
			
			
		}
	}
	
	
	
	ordenarGrupo(TOP_ganadores,196);//lo ordenamos de mayor a menor
	
	
}//fin de la funcion imprimirTop

void MedalleroPais(){

	
	//declaracion de los grupos por medalla obtenida
	int oro[196][2] = {0}, plata[196][2] = {0}, bronce[196][2] = {0};
	//inicializados en 0 para evitar problemas a la hora de sumar las medallas obtenidas
	
	
	//cada posicion del arreglo corresponde a la (id - 1) de un pais especifico comenzando con id: 1 para la posicion 0
	
	int IDpais;
	for(int fila = 0; fila < 87; fila++){//recorre categorias
		for(int col = 0; col < 3; col++){//recorre rango de medallas (oro, plata, bronce)
			
			IDpais = deporte_medallas2[fila][col]  -  1;
			
			switch(col){
				case 0: oro[IDpais][1]++    ; oro[IDpais][0] = IDpais + 1   ;break;//col 0 = oro
				case 1: plata[IDpais][1]++  ; plata[IDpais][0] = IDpais + 1 ;break;// col 1 = plata
				case 2: bronce[IDpais][1]++ ; bronce[IDpais][0] = IDpais + 1 ;break;//col 2 = bronce
			}
			
		}
	}
	
	//ordenamos los grupos, que tienen un TL de 196 ya que son 196 paises
	ordenarGrupo(oro, 196);
	ordenarGrupo(plata,196);
	ordenarGrupo(bronce,196);
	
	char opcionSalir;
	
	while(opcionSalir != 'X'){
		system("cls");
		system("color");
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		
		gotoxy(60,8);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO GRIS
		cout << "-GANADORES DE MEDALLA DE PLATA-" << endl;
		mostrarGrupo(plata,196,60,10);
		
		gotoxy(10,8);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
		cout << "-GANADORES DE MEDALLA DE ORO-" << endl;
		mostrarGrupo(oro,196,10,10);
		
		gotoxy(110,8);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO MARRON
		cout << "-GANADORES DE MEDALLA DE BRONCE-" << endl;
		mostrarGrupo(bronce,196,110,10);
		
		
		Sleep(500);
		gotoxy(60,5);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		cout << "Presione X para volver atrás:";
		gotoxy(90,5);
		cin >> opcionSalir;
		
		
	}
	
	
	
	
	
}
	
void MedalleroDeporte(){
	
	
	
	char opcion;
	
	
	
	
	while(opcion != 'X'){
		
		short X = 30, Y = 8;
		
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		gotoxy(15,6);
		
		
		cout << "Presione X para volver al menú anterior: ";
		
		gotoxy(X-25,Y); cout << "Deporte" ;  
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
		gotoxy(X+35,Y); cout << "Oro"; 
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO GRIS
		gotoxy(X+65,Y); cout << "Plata"; 
		
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO MARRON
		gotoxy(X+97,Y); cout << "Bronce";
		
		
		
		Y+=2;//para imprimir los deportes debajo
	
		for (int i = 0; i < 87; i++) {//recorre las 87 filas que corresponden a los 87 deportes.
		// Verificar si hay un podio en la fila i
			if (deporte_medallas2[i][0] != 0 and deporte_medallas2[i][1] != 0 and deporte_medallas2[i][2] != 0) {
			
			
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
				gotoxy(X-29,Y); cout << i+1 <<".";
				gotoxy(X-25,Y); imprimirDeporte(i+1); // Muestra el NOMBRE del deporte
			
				// Mostrar los países del podio
				// Oro
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
				gotoxy(X+35,Y);	 imprimirPais(deporte_medallas2[i][0]); // ID del país que ganó oro
				
				// Plata
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO GRIS
				gotoxy(X+65,Y);	 imprimirPais(deporte_medallas2[i][1]); // ID del país que ganó plata
				
				// Bronce
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO MARRON
				gotoxy(X+97,Y);	 imprimirPais(deporte_medallas2[i][2]); // ID del país que ganó bronce
			
				Y++; // Línea en blanco para separar los podios
				
			}//fin del if
		
		}//fin del recorrido de filas correspondientes a los deportes
	
		gotoxy(57,6);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		cin >> opcion;
	}//fin WHILE
	
}//fin del MedalleroDeporte()
		
		
void TopMedallero(){
	
	int top = 0;
	
	
	
	do{
		system("cls");
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		
		if(top != 0){
			
			//gotoxy(80,14);
			mostrarGrupo(TOP_ganadores,top,73,19);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//texto negro
		}
		
		gotoxy(65,14);
		cout << "ingrese 0 para volver atrás";
		
		gotoxy(65,16);
		cout << "Ingrese un numero TOP países que desea visualizar: ";
		cin >> top;// un valor entre 1 y 196
		
		
		
		
		
		while(top < 0 or top > 196){
			cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
			system("cls");
			
			gotoxy(65,14);
			cout << "ingrese 0 para volver atrás";
			
			gotoxy(65,17);
			cout << "(valor mín. 1 y valor máx. 196)";
			
			gotoxy(65,16);
			cout << "Ingrese un numero TOP paises que desea visualizar: ";
			cin >> top;
			
		}
		
		
		
		
		
		
	} while(top != 0);
}
			
	
	
void menujuegos(){//AHORA LLAMADO MENÚ MEDALLERO
	//system("mode con: cols=120 lines=30");
	
	char opcion;
	bool bandera = false;
	cargarDeportes_Medallas2(deporte_medallas2);
	generarTop();
	
	do{
		short X = 75,Y = 15;
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		cout << "Menú Medallero" << endl;
		centrar(X,Y,'Y');
		cout << "=====================" << endl;
		centrar(X,Y,'Y');
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		cout << "1.- Medallero por País" << endl;
		centrar(X,Y,'Y');
		cout << "2.- Medallero por Deporte" << endl;
		centrar(X,Y,'Y');
		cout << "3.- Top Medallero" << endl;
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
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4);//TEXTO ROJO - ERROR
				cout << "¡OPCION INVALIDA!" << endl;
				Sleep(700);
			}
	} while(!bandera);
		
}//FIN MENU JUEGOS


