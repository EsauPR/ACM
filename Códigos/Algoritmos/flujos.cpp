#include <sstream>

char str[100]={Hola Mundo Feliz};
char str2[100];
string x;

//para leer desde una cadena
istringstream flujo( str );
ostringstream flujoSalida( str2 );

	while(flujo >> x){

		cout << x <<endl;
		//para imprimir a una cadena
		flujoSalida << x;
	}
	
