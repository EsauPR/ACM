#include <sstream>
 
//Varios tipos de datos
string nombre = "Daniela";
int edad = 19;
float estatura = 1.68;
 
//se crea el objeto stringstream
stringstream msg;
 
//y se usa como un flujo, como un cout solo que no imprime solo concatena
msg << nombre << " tiene " << edad << " años, y mide " << estatura << " metros.";
 
//Ahora con el metodo str() obtenemos la string
string linea = msg.str();
