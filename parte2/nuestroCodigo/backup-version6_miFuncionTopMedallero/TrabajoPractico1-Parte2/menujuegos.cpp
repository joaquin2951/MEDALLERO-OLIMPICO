#include <iostream>
#include <windows.h>
#include <limits>
#include "configuraciones.h"
#include "menuprincipal.h"
#include "paises.h"

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
	
	for (int i = 0; i < cfilas; i++) {
		if (grupo[i][1] > 0 and (grupo[i][0] > 0 and grupo[i][0] < 197)) {
			
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
		
		
		
		gotoxy(10,8);
		cout << "-GANADORES DE MEDALLA DE PLATA-" << endl;
		mostrarGrupo(plata,196,10,10);
		
		gotoxy(60,8);
		cout << "-GANADORES DE MEDALLA DE ORO-" << endl;
		mostrarGrupo(oro,196,60,10);
		
		gotoxy(110,8);
		cout << "-GANADORES DE MEDALLA DE BRONCE-" << endl;
		mostrarGrupo(bronce,196,110,10);
		
		
		Sleep(500);
		gotoxy(60,5);
		cout << "Presione X para volver atrás:";
		gotoxy(90,5);
		cin >> opcionSalir;
	}
	
	
	
	
	
}
	
void MedalleroDeporte(){
	system("cls");
	gotoxy(65,16);
	cout << "2.- Funcionalidad en desarrollo" << endl;
	Sleep(segundosAMilisegundos(2));
	volviendo();
}
		
		
void TopMedallero(){
	
	int top = 0;
	
	
	
	do{
		system("cls");
		
		if(top != 0){
			
			//gotoxy(80,14);
			mostrarGrupo(TOP_ganadores,top,73,19);
			
		}
		
		gotoxy(65,14);
		cout << "ingrese 0 para volver atrás";
		
		gotoxy(65,16);
		cout << "Ingrese un numero TOP países que desea visualizar: ";
		cin >> top;// un valor entre 1 y 196
		
		
		
		while(top < 0 or top > 196){
			
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


