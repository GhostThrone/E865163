#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "core.h"

using namespace std;

int main()
{
	string resultado;/*, cadena;
	cout << "Ingrese la cadena de texto qye quiere encriptar: ";
	cin >> cadena;*/
	E865163 e1 ("Hola que tal");
	resultado = e1.encrypt();
	//cout << "La cadena original es: " << e1.encrypt() << endl;
	cout << "Cadena encriptada: " << resultado << endl;
	e1.guardarCadena(resultado);
	cin.get();
	return 0;
}
	