#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "configuraciones.h"
#include "menujuegos.h"
#include "menuprincipal.h"
#include "deportes.h"
#include "paises.h"


using namespace std;


competidores competencia[87];//existen 87 disciplinas
int deporte_medallas[87][3] = {0}; // almacena el ID del país que ha ganado la medalla oro-plata-bronce (col 0 = oro, col 1 = plata, col 3 = bronce)
//para cada uno de los 87 deportes propuestos. 



void cargaPorDeporteColectivo(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas){
	
	int opcion;
	
	while(opcion != 0){
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");  mostrarDeportesColectivos(); 
		short X = 40,Y = 17;//X = 75
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
			"Ingrese el ID de alguno de los deportes de la lista desplegada o presione '0' para volver al Menú Anterior: " 
			<< endl; 
		
		Y--;
		X+=108;
		centrar(X,Y,'X');
		cin >> opcion; //El usuario ingresa la opcion
		
		
		if(cin.fail()){
			cin.clear();  cin.ignore(10000, '\n'); //ignorar si ingresa varios caracteres juntos
			gotoxy(60,20);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
			cout << "Introduzca un dato válido." << endl;
			gotoxy(60,22);
			opcion = -1;
			Sleep(1000);
		}
		else
		if(opcion > 0 and opcion <= 87){//los deportes Colectivos van del indice 12 al 87
			if(perteneceADeporteColectivo(opcion)){
				system("cls");
				int oro,plata,bronce;
				gotoxy(60,20);
				cout << "Los paises que participan en esta competencia son: " << endl;
				X = 122, Y = 20; 
				
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 3);
				for(int i = 0; i < compe[opcion-1].tl; i++){
					centrar(X,Y,'Y');
					cout << "ID: " << compe[opcion-1].paises[i] << " "; imprimirPais(compe[opcion-1].paises[i]);
				}//IMPRIMIMOS LA LISTA DE DEPORTES PERTENECIENTES A ESA COMPETENCIA, CON SU ID CORRESPONDIENTE
				gotoxy(40,37);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
				cout << "Puede abandonar la carga en cualquier momento, introduciendo cualquier dato que NO sea un ID de pais" << endl;
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//volvemos al color original
				Y = 22; X = 55;
				gotoxy(55,22);
				cout << "Indicar el ID del país que ha ganado la medalla de Bronce: ";
				gotoxy(114,22);
				cin >> bronce;
				if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,bronce)){//SI EL PAIS QUE GANÓ LA MEDALLA DE BRONCE ESTÁ EN LA LISTA
					
					cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
					gotoxy(55,24);
					cout << "Indicar el ID del país que ha ganado la medalla de Plata: ";
					gotoxy(114,24);
					
					cin >> plata;
					if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,plata)){//SI EL PAIS QUE GANO LA DE PLATA ESTÁ EN LA LISTA
						cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
						gotoxy(55,26);
						cout << "Indicar el ID del país que ha ganado la medalla de Oro: ";
						gotoxy(114,26);
						cin >> oro;
						if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,oro)){//si accede acá, significa que los datos de bronce, plata y oro son correctos
							
							gotoxy(57,29);
							deporteMedallas[opcion-1][0] = oro; //columna 0 es oro
							deporteMedallas[opcion-1][1] = plata; //columna 1 es plata
							deporteMedallas[opcion-1][2] = bronce; //columna 2 es bronce
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
							cout << "DATOS CARGADOS CORRECTAMENTE! " << endl; cargaDeMedallas = true;
							Sleep(2000);
						}
						
					}
					
				}
			}else{
				gotoxy(60,20);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
				cout << "El deporte con ID " << opcion << " no pertenece al listado. " << endl;
				Sleep(1500);
			}
		}
					
					
					
					
	}//FIN WHILE
}//FIN funcion cargaPorDeporteColectivo()



void cargaPorDeporteIndividual(int deporteMedallas[87][3],  competidores compe[], bool & cargaDeMedallas){
	
	int opcion;
	
	while(opcion != 0){
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");  mostrarDeportesIndividuales(); 
		short X = 40,Y = 17;//X = 75
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
				"Ingrese el ID de alguno de los deportes de la lista desplegada o presione '0' para volver al Menú Anterior: " 
			<< endl; 
			
		Y--;
		X+=108;
		centrar(X,Y,'X');
		cin >> opcion; //El usuario ingresa la opcion
		
		
		if(cin.fail()){
			cin.clear();  cin.ignore(10000, '\n'); //ignorar si ingresa varios caracteres juntos
			gotoxy(60,20);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
			cout << "Introduzca un dato válido." << endl;
			gotoxy(60,22);
			opcion = -1;
			Sleep(1000);
		}
		else
		if(opcion > 0 and opcion < 87){
			if(perteneceADeporteIndividual(opcion)){
				system("cls");
				int oro,plata,bronce;
				gotoxy(60,20);
				cout << "Los paises que participan en esta competencia son: " << endl;
				X = 122, Y = 20; 
				
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 3);
				for(int i = 0; i < compe[opcion-1].tl; i++){
					centrar(X,Y,'Y');
					cout << "ID: " << compe[opcion-1].paises[i] << " "; imprimirPais(compe[opcion-1].paises[i]);
				}//IMPRIMIMOS LA LISTA DE DEPORTES PERTENECIENTES A ESA COMPETENCIA, CON SU ID CORRESPONDIENTE
				gotoxy(40,37);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
				cout << "Puede abandonar la carga en cualquier momento, introduciendo cualquier dato que NO sea un ID de pais" << endl;
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//volvemos al color original
				Y = 22; X = 55;
				gotoxy(55,22);
				cout << "Indicar el ID del país que ha ganado la medalla de Bronce: ";
				gotoxy(114,22);
				cin >> bronce;
				if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,bronce)){//SI EL PAIS QUE GANÓ LA MEDALLA DE BRONCE ESTÁ EN LA LISTA
					
					cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
					gotoxy(55,24);
					cout << "Indicar el ID del país que ha ganado la medalla de Plata: ";
					gotoxy(114,24);
		
					cin >> plata;
					if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,plata)){//SI EL PAIS QUE GANO LA DE PLATA ESTÁ EN LA LISTA
						cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
						gotoxy(55,26);
						cout << "Indicar el ID del país que ha ganado la medalla de Oro: ";
						gotoxy(114,26);
						cin >> oro;
						if(busquedaPais(compe[opcion-1],compe[opcion-1].tl,oro)){//si accede acá, significa que los datos de bronce, plata y oro son correctos
							
							gotoxy(57,29);
							deporteMedallas[opcion-1][0] = oro; //columna 0 es oro
							deporteMedallas[opcion-1][1] = plata; //columna 1 es plata
							deporteMedallas[opcion-1][2] = bronce; //columna 2 es bronce
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
							cout << "DATOS CARGADOS CORRECTAMENTE! " << endl; cargaDeMedallas = true;
							Sleep(2000);
						}
						
					}
					
				}
			}else{
				gotoxy(60,20);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //aviso en rojo
				cout << "El deporte con ID " << opcion << " no pertenece al listado. " << endl;
				Sleep(1500);
			}
		}
			
			
			
	
		}//FIN WHILE
}//FIN funcion cargaPorDeporteIndividual()
	
	
bool busquedaPais(const competidores compe,const int TLcompe, const int IDpais){
	int i = 0;
	
	while(i < TLcompe){
		if(compe.paises[i] == IDpais)
			return true;//el pais ya está en el arreglo.
		i++;
	}
	
	return false;//el país NO está aún en el arreglo.
}

void generarCompetencia(){
	srand(time(NULL));
	int TL;//min 4, max 16
    int IDpais;//ID van del 1 al 196
	int paisesCargados;
	
	for(int i = 0; i < 87; i++){
			TL = (rand()%13) + 4;//genera numeros del 4 al 16.
			competencia[i].tl = TL;
			paisesCargados = 0;
			
			while(paisesCargados < competencia[i].tl){
				
				IDpais = (rand()%196) + 1; //genera ID aleatorio desde el 1 hasta el 196
				
				if(busquedaPais(competencia[i],paisesCargados,IDpais) == false){
					competencia[i].paises[paisesCargados] = IDpais; //se guarda solamente si el pais AUN NO ESTÁ EN EL ARRAY.
					paisesCargados++;
				}
				
			}
			
			
			
	}
	
}//fin de funcion generarCompetencia();

	
void cargarMedallas(bool & cargaDeMedallas){
	
	char opcion;
	
	
	while(opcion != 'X'){
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos
		system("cls");
		short X = 75,Y = 15;
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
			"Menú Carga de Medallas por Deporte " << endl;  centrar(X,Y,'Y'); //centrar menu
			
		generarLinea('=',25); centrar(X,Y,'Y');
			
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
//		cout <<
//			"1. Carga por País" << endl;  centrar(X,Y,'Y'); //centrar menu
//		cout <<
//			"2. Carga por Deporte" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"1. Carga por Deporte Individual" << endl;  centrar(X,Y,'Y'); //centrar men
		cout <<
			"2. Carga por Deporte Colectivo" << endl;  centrar(X,Y,'Y'); //centrar me
//		cout <<
//			"5. Carga por Categoría Deportiva" << endl;  centrar(X,Y,'Y'); //centrar menunuu
								
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); 
		cout << 
			"X. Volver al Menú Principal" << endl;  centrar(X,Y,'Y'); //centrar menu
									
									
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		Y++; centrar(X,Y,'X'); //centrar menu
		cout <<
			"Ingrese una opción: ";  
									
		X+=20;
		centrar(X,Y,'X');
					
		
		cin >> opcion; //El usuario ingresa la opcion
									
		switch(opcion){
										
			case '1': cargaPorDeporteIndividual(deporte_medallas,competencia,cargaDeMedallas); break;
			case '2': cargaPorDeporteColectivo(deporte_medallas,competencia,cargaDeMedallas); break;
									
			case 'X': volviendo(); break;
			default: Y+=6; X=66; centrar(X,Y,'n'); 
			cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
			Sleep(segundosAMilisegundos(1));    break;
									
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
bool competenciaGenerada = false, cargaDeMedallas = false;
	
while(opcion != 'X'){
	short X = 75,Y = 15;
	system("cls");
	cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); //TEXTO NEGRO
	centrar(X,Y,'Y'); //centrar menu	
	cout << 
		"Menú Principal " << endl;  centrar(X,Y,'Y'); //centrar menu
		
		generarLinea('=',25); centrar(X,Y,'Y');
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		cout <<
			"1. Generar Competencia" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"2. Cargar Medallas por Deporte" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
			"3. Mostrar Medallero" << endl;  centrar(X,Y,'Y'); //centrar menu
			
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << 
			"X. Salir de la aplicación" << endl;  centrar(X,Y,'Y'); //centrar menu
					
					
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);//TEXTO NEGRO
		Y++; centrar(X,Y,'A'); //centrar menu
		cout <<
			"Ingrese una opción: ";  
					
		Y--; X+=20;
						
		centrar(X,Y,'X');
						
		cin >> opcion; //El usuario ingresa la opcion
						
		switch(opcion){
					
			case '1': if(competenciaGenerada == false){
							gotoxy(70,25);
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
							generarCompetencia(); competenciaGenerada = true;
							cout << "Competencia generada con éxito." << endl; Sleep(1000);
						}else{
							gotoxy(70,25);
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //error en rojo
							cout << "usted ya ha generado una competencia. " << endl; Sleep(1000);
						}; break;
			case '2': if(competenciaGenerada == true){
							cargarMedallas(cargaDeMedallas); 
						}else{
							gotoxy(70,25);
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //error en rojo
							cout << "Usted aún NO ha generado ninguna competencia. " << endl; Sleep(1000);
						}; break;
			case '3': if(cargaDeMedallas == true){
							menujuegos();
						}else{
							gotoxy(70,25);
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //error en rojo
							cout << "Usted aún NO ha cargado ninguna medalla. " << endl; Sleep(1000);
						}; break;
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




void cargarDeportes_Medallas2(int deportes_medallas2[87][3]){
	for(int i = 0; i < 87; i++){
		for(int j = 0; j < 3; j++){
			deportes_medallas2[i][j] = deporte_medallas[i][j];
		}
	}
}
