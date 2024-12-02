#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct competidores{
	int paises[16];
	int tl;
};

competidores competencia[87];//global variable


bool busquedaPais(const competidores compe,const int TLcompe, const int IDpais);
void generarCompetencia();


int main(int argc, char *argv[]) {
	
	
	generarCompetencia();
	
	for(int i = 0; i < 87; i++){
		
		cout << endl << "competencia " << i <<" con TL = " << competencia[i].tl << endl;
		
		for(int j = 0; j < competencia[i].tl; j++){
			
				cout << competencia[i].paises[j] << " ";
			
		}
		
	}
	
	return 0;
}



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
