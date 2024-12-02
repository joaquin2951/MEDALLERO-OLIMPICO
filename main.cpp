#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime> //usada para obtener la fechaActual en pantalla login y funcion contrasenia()

using namespace std;

void mostrarAlumnos();
void generarLinea(char Caracter, int Longitud); //genera una linea recta para los menu
void dibujarRecuadro(int largoX,int altoY);
void centrar(short & X, short & Y, char incrementar);//lo usamos para centrar los datos en pantalla, utilizando dentro la funcion gotoxy();
void bienvenida();//pantalla de Bienvenida
void login(int & intentos); //pantalla de login
int contrasenia(int legajo); //generacion de password
void aro(short & X,short & Y);
void logo(); //generamos el logo aquí
void configuracionConsola();
void gotoxy(short x, short y);
void login();//pantalla que muestra el login
void menuPrincipal();//pantalla que muestra el menu principal
void saliendo();//pantalla que muestra una CARGA mientras se sale del programa
void volviendo();//pantalla que muestra una CARGA mientras se vuelve al menu anterior
void cargarMedallas();//pantalla que muestra el menu de  CARGA DE MEDALLAS
void menujuegos();//pantalla que muestra el mnenu de juegos
void MedalleroPais(); //sub-pantalla dentro del menu de juegos
void MedalleroDeporte();//sub-pantalla dentro del menu de juegos
void TopMedallero();//sub-pantalla dentro del menu de juegos
int segundosAMilisegundos(int segundos);



int main() {
	
int intentos = 0; //sera pasado por referencia en la funcion login()
configuracionConsola();
	
	while(!GetAsyncKeyState(VK_RETURN)){//muestra la funcion bienvenida() hasta que se toque ENTER
		
		bienvenida();
		Sleep(segundosAMilisegundos(2));//3000 milisegundos ___ 3 segundos
		
	}
	
	

	system("cls");//limpia la pantalla
	
	login(intentos);
	
	if(intentos < 3)
		menuPrincipal();
	else{
		system("cls");
		gotoxy(55,15); generarLinea('=',60);
		gotoxy(55,17); cout << "Usted ha alcanzado el maximo de intentos, la aplicacion se cerrara. " << endl;
		gotoxy(55,19); generarLinea('=',60);
		Sleep(segundosAMilisegundos(2));
		saliendo();
	}
	
	
	
		
	
	

	system("pause");
	return 0;
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

void login(int & intentos){
	
	int const intentos_maximos=3;
	bool logueado = false;
	


	while(intentos < intentos_maximos and !logueado){
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
					cout << "Contrasenha: ";
					gotoxy(87,24); //centrar menu
					cin >> contrasenia_ingresada;
					
					if(contrasenia_ingresada==contrasenia_valida){
						cout << "Login exitoso" << endl;
						logueado = true;
					}
					else{
						gotoxy(71,26); //centrar menu
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 4); //error en rojo
						cout << "Contrasenha Incorrecta." << endl;
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
	
void menuPrincipal(){
		
		char opcion;
	
		
		while(opcion != 'X'){
		short X = 75,Y = 15;
		system("cls");
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
		centrar(X,Y,'Y'); //centrar menu	
		cout << 
						"Menu Principal " << endl;  centrar(X,Y,'Y'); //centrar menu
		
		generarLinea('=',25); centrar(X,Y,'Y');
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
		cout <<
						"1. Cargar Medallas" << endl;  centrar(X,Y,'Y'); //centrar menu
		cout <<
						"2. Mostrar Medallero" << endl;  centrar(X,Y,'Y'); //centrar menu
		
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); 
		cout << 
						"X. Salir de la aplicacion" << endl;  centrar(X,Y,'Y'); //centrar menu
		
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
		Y++; centrar(X,Y,'A'); //centrar menu
		cout <<
						"Ingrese una opcion: ";  
		
		Y--; X+=20;
		
		centrar(X,Y,'X');
		
		cin >> opcion; //El usuario ingresa la opcion
	
			switch(opcion){
				
			case '1': cargarMedallas(); break;
			case '2': menujuegos(); break;
			case 'X': saliendo(); break;
			default: Y+=6; X=66; centrar(X,Y,'n'); 
								cout << "Opcion inexistente, vuelva a introducir un dato" << endl; 
								Sleep(segundosAMilisegundos(1));  break;
			
			}//FIN SWITCH
	
		}//FIN WHILE
		
}//FIN FUNCION

		
void cargarMedallas(){
			
	char opcion;
			
			
		while(opcion != 'X'){
			system("cls");
			short X = 75,Y = 15;
				
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0); 
			centrar(X,Y,'Y'); //centrar menu	
			cout << 
					"Menu Carga de Medallas " << endl;  centrar(X,Y,'Y'); //centrar menu
					
			generarLinea('=',25); centrar(X,Y,'Y');
					
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 9); 
			cout <<
						"1. Carga por Pais" << endl;  centrar(X,Y,'Y'); //centrar menu
			cout <<
						"2. Carga por Deporte" << endl;  centrar(X,Y,'Y'); //centrar menu
			cout <<
						"3. Carga por Deporte Individual" << endl;  centrar(X,Y,'Y'); //centrar men
			cout <<
						"4. Carga por Deporte Colectivo" << endl;  centrar(X,Y,'Y'); //centrar me
			cout <<
						"5. Carga por Categoria Deportiva" << endl;  centrar(X,Y,'Y'); //centrar menunuu
							
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 12); 
			cout << 
						"X. Volver al Menu Principal" << endl;  centrar(X,Y,'Y'); //centrar menu
								
								
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
			Y++; centrar(X,Y,'X'); //centrar menu
			cout <<
						"Ingrese una opcion: ";  
								
			X+=20;
			centrar(X,Y,'X');
								
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
			cout << "Opcion inexistente, vuelva a introducir un dato" << endl; 
			Sleep(segundosAMilisegundos(1));  break;
								
								}//FIN SWITCH
								
	}//FIN WHILE
			
}//FIN Cargar_Medallas		

	
	
void menujuegos(){
		system("mode con: cols=120 lines=30");
		
		char opcion;
		bool bandera = false;
		
		do{
			short X = 75,Y = 15;
			
			system("cls");
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 0);
			centrar(X,Y,'Y');
			cout << "=====================" << endl;
			centrar(X,Y,'Y');
			cout << "Menú juegos" << endl;
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
	
void volviendo(){//pantalla de VOLVIENDO al menu anterior
	system("cls");
	short X=60, Y=15;
		
	centrar(X,Y,'Y');
	cout << "Volviendo al menu anterior" << endl;
		
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7*16 + 2);
	for(int i = 0; i < 20; i++){
		centrar(X,Y,'X');
		Sleep(100);
		cout << "|||||" ;
	}
		
	Y+=3;
	centrar(X,Y,'0');
	
}

	
void mostrarAlumnos(){
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
	cout << "Alumno1     -     Alumno 2     -     Alumno 3" << endl;
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
	
void aro(short  & X, short & Y){
	
	centrar(X,Y,'Y');
	cout << "  .,::OOO::,.    " << endl; centrar(X,Y,'Y');
	cout << ".:\'         `:. " << endl; centrar(X,Y,'Y');
	cout << ":\"           \": "  << endl; centrar(X,Y,'Y');
	cout << ":,            \" "<< endl; centrar(X,Y,'Y');
	cout << " :,,         ,:    "<< endl; centrar(X,Y,'Y');
	cout << "  `^OOoo:\"O^'   " << endl; centrar(X,Y,'Y');
	
	
}
	
void gotoxy(short x, short y){
	COORD cp = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}
	
	
void configuracionConsola(){
	HWND hwnd = GetConsoleWindow();// Obtener el manejador de la consola
	system("mode con: cols=150 lines=200");
	system("color 70");
	ShowWindow(hwnd, SW_MAXIMIZE);// Maximizar la ventana de la consola
	
}

int segundosAMilisegundos(int segundos){
	return segundos*1000;
}
	

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

void cls(){
	system("cls");
}
