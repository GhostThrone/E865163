class E865163
{
private:
	std::string cadena;
public:
	E865163(std::string);
	std::string encrypt();
	std::string decrypt(std::string);
	std::string convertIntToBin(int);
	void guardarCadena(std::string);
	std::string leerCadena();
};

E865163::E865163(std::string cad)
{
	cadena = cad;
}


std::string E865163::encrypt()
{
	std::string c = cadena, cadenaBinaria = "", cadenaFinal = "";
	for (unsigned int i = 0; i < c.length(); i++)
	{
		cadenaBinaria += convertIntToBin(c[i]) + ",";
	}
	for (unsigned int u = 0; u < cadenaBinaria.length(); u++)
	{
		if(cadenaBinaria[u] == '1')
			cadenaFinal += "aB";
		else if(cadenaBinaria[u] == '0')
			cadenaFinal += "Cd";
		else if(cadenaBinaria[u] == ',')
			cadenaFinal += "&H1";
		else
			cadenaFinal += "uk";
	}
	return cadenaFinal;
}

std::string E865163::convertIntToBin(int ascii_num)
{
	int r, a = ascii_num;
	std::string binString = "";
	if(ascii_num < 32)
		r = 5;
	else if(ascii_num < 64)
		r = 6;
	else if(ascii_num < 128)
		r = 7;
	else if(ascii_num < 256)
		r = 8;
	std::vector<int> bin(r);
	for (unsigned int i = 0; i < bin.size(); i++)
	{
		bin[i] = a % 2;
		a >>= 1;
	}
	reverse(bin.begin(), bin.end());
	for (unsigned int i = 0; i < bin.size(); i++)
		binString += std::to_string(bin[i]);

	return binString;
}

void E865163::guardarCadena(std::string cadena)
{
	std::ofstream file ("fileResult.crygt");
	if(file.is_open())
	{
		file << cadena;
		file.close();
		std::cout << "Terminado, archivo de recopilacion guardado..." << std::endl;
	}else
		std::cout << "No se pudo crear el archivo :(!" << std::endl;
}

std::string E865163::decrypt(std::string cadenaEncriptada)
{

}

std::string E865163::leerCadena()
{
	std::string linea, dec;
	std::ifstream ifile ("fileResult.crygt");
	if(ifile.is_open())
	{
		std::ofstream __ofile ("Desencrypted.txt");
		if(__ofile.is_open())
		{
			while(getline(ifile, linea))
			{
				dec = decrypt(linea);
				__ofile << dec;
			}
		}
	}
}

