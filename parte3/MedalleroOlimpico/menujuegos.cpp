#include <iostream>
#include <windows.h>
#include <limits>
#include "configuraciones.h"
#include "menuprincipal.h"
#include "paises.h"
#include "deportes.h"

#define cant_paises 197
using namespace std;

archivoCompetencia file; 
//int deporte_medallas2[87][3];
int TOP_ganadores[cant_paises][2] = {0};//primera col para ID, segunda para cant MEdallas Ganadas



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
void ordenarGrupo(int grupo[cant_paises][2], const int cfilas) {
	
	
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
void mostrarGrupo(int grupo[cant_paises][2], const int cfilas,short coordX,short coordY) {
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

void generarTop(int mat_Top[cant_paises][2], int mat_deporteMedallas[87][3]){//generamos el TOP de los paises que más medallas ganaron
	
	int IDpais;
	
	//inicializamos la matriz en 0
	for(int f = 0; f < cant_paises; f++)
		for(int c = 0; c < 2; c++)
			mat_Top[f][c] = 0;
	
	
	for(int fil = 0; fil < 87; fil++){//recorre categorias de deportes (filas)
		for(int col = 0; col < 3; col++){//recorre las medallas, en este caso solo hay que sumar todas, no importa de qué importancia son.
			
			IDpais = mat_deporteMedallas[fil][col];//se guarda el ID del pais que ganó una medalla
			//si no hay deporte cargado, la FILA valdrá 0 en cada columna --> eso no será un ID existente (ID van de 1 a 196)
			if(IDpais > 0){
				mat_Top[IDpais-1][0] = IDpais;   //le resto 1 ya que el vector se recorre de 0 a 196. En indice 0 está el pais con ID 1.
				mat_Top[IDpais-1][1]++;//la columna 0 guarda el ID del pais, la col. 1 guarda las medallas totales del mismo
			}
			
			
			
		}
	}
	
	
	
	ordenarGrupo(mat_Top,cant_paises);//lo ordenamos de mayor a menor
	
	
}//fin de la funcion imprimirTop

void MedalleroPais(){

	
	int medalleroTotal[cant_paises][4] = {0}; // col 0: IDpais, col1: cant Medallas Doradas, col2: cant Medallas platas, c3: cantMedallas Bronce
	//inicializados en 0 para evitar problemas a la hora de sumar las medallas obtenidas
	
	
	//cada posicion del arreglo corresponde a la (id - 1) de un pais especifico comenzando con id: 1 para la posicion 0
	
	int IDpais;
	for(int fila = 0; fila < 87; fila++){//recorre categorias
		for(int col = 0; col < 3; col++){//recorre rango de medallas (oro, plata, bronce) de deporte_medallas
			
			IDpais = file.deporte_medallas[fila][col]  -  1;
			
			switch(col){
				case 0: medalleroTotal[IDpais][1]++; medalleroTotal[IDpais][0] = IDpais + 1 ;break;//col 0 de deporte_medallas = oro
				case 1: medalleroTotal[IDpais][2]++; medalleroTotal[IDpais][0] = IDpais + 1 ;break;// col 1 de deporte_medallas = plata
				case 2: medalleroTotal[IDpais][3]++; medalleroTotal[IDpais][0] = IDpais + 1 ;break;//col 2 de deporte_medallas = bronce
			}
			
		}
	}
	
	
	
	
	//ORDENAMOS LA MATRIZ, POR CANTIDAD DE MEDALLAS DORADAS , PLATEADAS Y DE BRONCE.
	//SI DOS PAISES TIENEN LA MISMA CANT DE DORADAS --> SE DEFINE POR CANT DE PLATA. 
	//SI DOS PAISES TIENEN LA MISMA CANT DE PLATA --> SE DEFINE POR CANT DE BRONCE.
	//SI TAMBIÉN TIENEN LA MISMA CANT DE BRONCE --> Da igual el orden, están empatados.
	
	
	for(int i = 0; i < cant_paises - 1; i++){
		int mayor = medalleroTotal[i][1];//valor del mayor elemento
		int posMayor = i;//indice del mayor elemento
		
		for(int j = i + 1; j < cant_paises; j++){
			
			if(medalleroTotal[j][1] > mayor or //si tiene más medallas de oro
			  (medalleroTotal[j][1] == mayor and medalleroTotal[j][2] > medalleroTotal[posMayor][2]) or //si tiene igual medallas de oro pero más de plata
			  (medalleroTotal[j][1] == mayor and medalleroTotal[j][2] == medalleroTotal[posMayor][2] and medalleroTotal[j][3] > medalleroTotal[posMayor][3]))//si tiene igual medallas de oro y plata pero más de bronce
			{
				mayor = medalleroTotal[j][1]; //nuevo valor del mayor elemento
				posMayor = j; //nuevo indice de mayor elemento
			}
			
		}
		
		if(posMayor != i){	//si se encontró un nuevo mayor
			swap(medalleroTotal[posMayor][0], medalleroTotal[i][0]);//intercambiamos las filas completas.
			swap(medalleroTotal[posMayor][1], medalleroTotal[i][1]);
			swap(medalleroTotal[posMayor][2], medalleroTotal[i][2]);
			swap(medalleroTotal[posMayor][3], medalleroTotal[i][3]);
		}
		
		
	}//FIN DEL ORDENAMIENTO DE LA MATRIZ medalleroTotal[][]
	
	
	
	char opcionSalir;
	
	while(opcionSalir != 'X'){//SE EJECUTA HASTA QUE EL USUARIO INGRESE 'X' PARA VOLVER AL MENU ANTERIOR
		system("cls");
		//system("color");
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		
		
		gotoxy(5,8);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		cout << "PAIS" << endl;
		
		gotoxy(40,8); //X 40 Y 8
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
		cout << "ORO" << endl;
		
		gotoxy(50,8);//X 50 Y 8
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO GRIS
		cout << "PLATA" << endl;
		
		gotoxy(60,8); //X 60 Y 8
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO MARRON
		cout << "BRONCE" << endl;
	
		gotoxy(70,8); //X 70 Y 8
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //TEXTO MARRON
		cout << "TOTAL" << endl;
		
		
		//MOSTRAMOS EL TOP ORDENADO
		
		short X = 5, Y = 10; bool filaVacia;
		int totalMedallasPais, totalMedallasRepartidas = 0;
		
		for(int fil = 0; fil < cant_paises; fil++){//196 filas de la matriz
			filaVacia = false; // ese pais no tiene ninguna medalla?
			
			if(medalleroTotal[fil][1] == 0 and medalleroTotal[fil][2] == 0 and medalleroTotal[fil][3] == 0)
				filaVacia = true;
			
			if(filaVacia == false){//si el pais gano alguna medalla...
				totalMedallasPais = 0;//contaremos cuantas ha ganado en total
				
				for(int col = 0; col < 4; col++){//4 columnas de la matriz
					if(col>0)
						totalMedallasPais+= medalleroTotal[fil][col];
					switch(col){//segun en qué columna estamos, mostraremos cierta información
					case 0:	gotoxy(X,Y);//X 5 Y 10
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); //TEXTO NEGRO
							imprimirPais(medalleroTotal[fil][col]); break;
						
					case 1:gotoxy(X+35,Y);//X 40 10
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
							cout << medalleroTotal[fil][col]; break;
						
					case 2:gotoxy(X+45,Y);//X 50 Y 10
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO PLATA
							cout << medalleroTotal[fil][col]; break;
						
					case 3:gotoxy(X+55,Y);//X 60 Y 10
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO BRONCE
							cout << medalleroTotal[fil][col]; break;
						
					}//fin del Switch
				
				}//fin del FOR que recorre las columnas
				
					gotoxy(X+65,Y);
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //TEXTO 
					cout << totalMedallasPais << endl;
					totalMedallasRepartidas+=totalMedallasPais;
				
					Y+=2;
			}//fin del IF
				
			
		}//fin del recorrido de las FILAS
		
		
		gotoxy(X+90,Y-25);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); //TEXTO 
		cout << "TOTAL DE MEDALLAS REPARTIDAS" << endl;
		gotoxy(X+102,Y-23);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); //TEXTO 
		cout << totalMedallasRepartidas << endl;
		
		
		//FIN DEL CODIGO PERTENECIENTE A LA MUESTRA DEL TOP ORDENADO
		
		
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
			if (file.deporte_medallas[i][0] != 0 and file.deporte_medallas[i][1] != 0 and file.deporte_medallas[i][2] != 0) {
			
			
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
				gotoxy(X-29,Y); cout << i+1 <<".";
				gotoxy(X-25,Y); imprimirDeporte(i+1); // Muestra el NOMBRE del deporte
			
				// Mostrar los países del podio
				// Oro
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 14); //TEXTO ORO
				gotoxy(X+35,Y);	 imprimirPais(file.deporte_medallas[i][0]); // ID del país que ganó oro
				
				// Plata
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 8); //TEXTO GRIS
				gotoxy(X+65,Y);	 imprimirPais(file.deporte_medallas[i][1]); // ID del país que ganó plata
				
				// Bronce
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 6); //TEXTO MARRON
				gotoxy(X+97,Y);	 imprimirPais(file.deporte_medallas[i][2]); // ID del país que ganó bronce
			
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
		
		
		
		
		
		while(top < 0 or top > cant_paises){
			cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
			system("cls");
			
			gotoxy(65,14);
			cout << "ingrese 0 para volver atrás";
			
			gotoxy(65,17);
			cout << "(valor mín. 1 y valor máx. 197)";
			
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
//	cargarDeportes_Medallas2(deporte_medallas2);
	file = obtenerArchivo();
	generarTop(TOP_ganadores, file.deporte_medallas);
	
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


