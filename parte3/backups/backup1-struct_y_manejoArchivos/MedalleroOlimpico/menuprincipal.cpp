#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include "login.h"
#include "configuraciones.h"
#include "menujuegos.h"
#include "menuprincipal.h"
#include "deportes.h"
#include "paises.h"



using namespace std;


//competidores competencia[87];//existen 87 disciplinas //ahora está guardado en la struct archivo
//int deporte_medallas[87][3] = {0}; // almacena el ID del país que ha ganado la medalla oro-plata-bronce (col 0 = oro, col 1 = plata, col 3 = bronce)
//para cada uno de los 87 deportes propuestos. //ahora estará guardado en la struct Archivo

archivoCompetencia archivo; 
string nombre_archivo;


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
			archivo.competencia[i].tl = TL;
			paisesCargados = 0;
			
			while(paisesCargados < archivo.competencia[i].tl){
				
				IDpais = (rand()%196) + 1; //genera ID aleatorio desde el 1 hasta el 196
				
				if(busquedaPais(archivo.competencia[i],paisesCargados,IDpais) == false){
					archivo.competencia[i].paises[paisesCargados] = IDpais; //se guarda solamente si el pais AUN NO ESTÁ EN EL ARRAY.
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
										
			case '1': cargaPorDeporteIndividual(archivo.deporte_medallas,archivo.competencia,cargaDeMedallas); break;
			case '2': cargaPorDeporteColectivo(archivo.deporte_medallas,archivo.competencia,cargaDeMedallas); break;
									
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
	
	
void inicializarMedallero(int deporte_medallas[87][3]){
		deporte_medallas = {0};
}//FIN DE FUNCION inicializarMedallero();




void actualizarBin()
{
	ofstream f; //modo escritura
	
	system("cls");
	
	f.open(nombre_archivo, ios::binary);//intentamos abrirlo
	
	gotoxy(25,10);
	
	if(f.fail())//si falla la apertura...
	{
	
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << "No existe archivo en el cual guardar los datos." << endl;
		
	}
	else
	{
		f.write((char *)&archivo,sizeof(archivoCompetencia));//sobreescribimos todo el archivo, actualizandolo
		f.close();
		
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << "Guardado con exito." << endl;
		
	}
	
	Sleep(2000);
}




void cargarBin(bool & competenciaGenerada,archivoCompetencia & file)
{
	system("cls");
	
	int Anio, Mes, Dia, Hora, Minutos, Segundos;	
	short X = 35, Y = 10;
	gotoxy(X,Y); SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
	cout << "A continuación debe introducir la fecha de creación del archivo que está buscando";
	
	gotoxy(X,Y+2); cout << "Año: "; 
	gotoxy(X+5,Y+2); cin >> Anio;
	gotoxy(X,Y+4); cout << "Mes: "; 
	gotoxy(X+5,Y+4); cin >> Mes;
	gotoxy(X,Y+6); cout << "Dia: "; 
	gotoxy(X+5,Y+6); cin >> Dia;
	
	gotoxy(X,Y+8); cout << "Hora: "; 
	gotoxy(X+6,Y+8); cin >> Hora;
	gotoxy(X,Y+10); cout << "Minutos: "; 
	gotoxy(X+10,Y+10); cin >> Minutos;
	gotoxy(X,Y+12); cout << "Segundos: "; 
	gotoxy(X+11,Y+12); cin >> Segundos;
	
	string nombreArch = to_string(Anio) + "-" + to_string(Mes) + "-" + to_string(Dia) + "-" + to_string(Hora) + "-" + to_string(Minutos) + "-" + to_string(Segundos) + ".bin";
	
	ifstream f; //creamos un ifstream ya que queremos leer datos del archivo
	
	f.open(nombreArch,ios::binary);//intentamos abrirlo
	
	
	system("cls");
	
	if(f.fail())
	{
		gotoxy(X,Y);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << "ERROR AL ABRIR EL ARCHIVO. QUIZA NO EXISTE." << endl;
		Sleep(3000);
	}
	else
	{
		f.read((char *) &file, sizeof(archivoCompetencia));
		f.close();
		
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
		gotoxy(X,Y); cout << "Competencia cargada con éxito." << endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
		gotoxy(X,Y+2); cout << "CREADO POR EL USUARIO CON LEGAJO: " << file.legajo;
		
		nombre_archivo = nombreArch;//lo guardo en la variable global solamente si el nombre del archivo es correcto
		
		//Anio = file.fechaCreacion->tm_year+1900;  // Hora = file.fechaCreacion->tm_hour;
		//Mes = file.fechaCreacion->tm_mon+1;		//Minutos = file.fechaCreacion->tm_min;
		//Dia = file.fechaCreacion->tm_mday;			//Segundos = file.fechaCreacion->tm_sec;
		
	
		gotoxy(X,Y+4); cout << "EN LA FECHA: " << Anio << "/" << Mes << "/" << Dia << " a las " << Hora << ":" << Minutos << ":" << Segundos << endl;
		
		Sleep(10000);
		competenciaGenerada = true;
	}
	
	
	
	
}

void generarBin(archivoCompetencia & file)
{
	ofstream f;
	int Anio, Mes, Dia, Hora, Minutos, Segundos;
	
	//hacemos uso de la biblioteca time.h para obtener la fecha y hora actual
	time_t ahora;
	tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	
	Anio = fecha->tm_year + 1900;
	Mes = fecha->tm_mon+1;
	Dia = fecha->tm_mday;
	
	Hora = fecha->tm_hour;
	Minutos = fecha->tm_min;
	Segundos = fecha->tm_sec;
	
	string fechaEnCadena = to_string(Anio) + "-" + to_string(Mes) + "-" + to_string(Dia) + "-" + to_string(Hora) + "-" + to_string(Minutos) + "-" + to_string(Segundos) + ".bin";
	
	
	f.open(fechaEnCadena, ios::binary);//abrimos el archivo con el nombre fechaEnCadena en modo binario
	
	if(f.fail())//falla al abrirse?
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
		cout << "ERROR AL GENERAR ARCHIVO" << endl;
		Sleep(3000);
	}
	else//si no falla al abrirse...
	{
		file.legajo = obtenerLegajo();//guardamos el legajo del usuario que creó esta competencia
		file.fechaCreacion = fecha;//guardamos la misma fecha en la que fue creada
		f.write((char *) &file,sizeof(archivoCompetencia));//escribimos todo el el archivo binary
		f.close();//cerramos archivo
	
		nombre_archivo = fechaEnCadena; //lo guardo en la variable global si se generó el archivo correctamente
	}
	
}//FIN DE FUNCION generarBin()




void menuGenerarCompetencia(bool & competenciaGenerada, bool & cargaDeMedallas){
	
	char opcion;
	
	
	while(opcion != 'X'){
		short X = 75,Y = 15;
		system("cls");
		cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar si ingresa varios caracteres juntos	
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); //TEXTO NEGRO
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
			"Menú Generar Competencia " << endl;  centrar(X,Y,'Y'); //centrar menu
			
			generarLinea('=',25); centrar(X,Y,'Y');
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); //TEXTO AZUL
			cout <<
				"1. Generar Competencia" << endl;  centrar(X,Y,'Y'); //centrar menu
			cout <<
				"2. Cargar Competencia" << endl;  centrar(X,Y,'Y'); //centrar menu
						
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //TEXTO ROJO
			cout << 
				"X. Volver al menú principal" << endl;  centrar(X,Y,'Y'); //centrar menu
	
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
							inicializarMedallero(archivo.deporte_medallas);//hacemos que el medallero arranque en 0 en todos los valores
							generarCompetencia(); competenciaGenerada = true;
							//una vez generada la competencia, almacenamos el contenido de archivoCompetencia en un archivo .bin
							generarBin(archivo);
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
							cout << "Competencia generada con éxito." << endl; Sleep(1000);
							}else{
								gotoxy(70,25);
								SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //error en rojo
								cout << "usted ya ha generado una competencia. " << endl; Sleep(1000);
							}; break;
							
				case '2': if(competenciaGenerada == false){
							cargarBin(competenciaGenerada, archivo);
							//funcion para cargar un archivo creado anteriormente por otro usuario
							}else{
								gotoxy(70,25);
								SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); //error en rojo
								cout << "usted ya ha generado una competencia. " << endl; Sleep(1000);
							}; break;
							
				case 'X': volviendo(); break;
							
				default: Y+=6; X=66; centrar(X,Y,'n'); 
							cout << "Opción inexistente, vuelva a introducir un dato" << endl; 
							Sleep(segundosAMilisegundos(1));  break;
							
			}//FIN SWITCH
							
	}//FIN WHILE
}


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
							//gotoxy(70,25);
							//SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2); //validacion en verde
							menuGenerarCompetencia(competenciaGenerada,cargaDeMedallas);
							//cout << "Competencia generada con éxito." << endl; Sleep(1000);
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
								
							case '1': actualizarBin(); saliendo(); break;
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
			deportes_medallas2[i][j] = archivo.deporte_medallas[i][j];
		}
	}
}
