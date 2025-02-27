#include "tablero.h"

//Funcion para inicializar el tablero que recibe el array de botellas creado en main
void inicioTablero(char botellas[X][Y]) {
	
	srand(time(NULL));
	//Liquidos para llenar las botellas
	char liquids[4]{ 'X', 'O', '#', 'S' };
	//Iterador para esocger los liquidos
	short iLiquids = 0;
	short posRand = 0;

	//For para llenar las botellas espacio por espacio
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++)
		{
			//Asignacion de un caracter random a iLiquids
			iLiquids = rand() % 4;
			//Si esta en la primera posicion la dejamos vacia
			if (i == 0) {
				botellas[j][i] = ' ';
			}
			//Si no, la llenamos con iLiquids
			else {
				botellas[j][i] = liquids[iLiquids];
			}
		}
	}
	//for para llenar 2 botellas random al maximo
	for (int c = 0; c < 2; c++) {
		//Seleccion de 1 botella random
		posRand = rand() % 6;
		botellas[posRand][0] = liquids[iLiquids];
	}

}

//Renderizado del tablero
void renderTablero(char botellas[X][Y]) {
	short iLiquids = 0;

	//for donde creamos las botellas
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			//Si estamos en la primera posicion ponemos \ /, utilizamos char(92) porque \ es un caracter que c++ no toma en cuenta
			if (i == 0) {
				std::cout << char(92) << " / ";
			}
			//Si estamos en la penultima posicion cerramos la botella
			else if (i == 4) {
				std::cout << "''' ";
			}
			//Si estamos en la ultima posicion ponemos un numero para indicar que botella es
			else if (i == 5) {
				std::cout << ' ' << j + 1 << "  ";
			}
			//En el medio ponemos las barreras de las botellas con sis liquidos por dentro
			else {
				std::cout << '|' << botellas[j][iLiquids] << "| ";
			}
		}
		std::cout << std::endl;
		//si i no es 0 aumentamos iLiquids para indicar que liquido tiene dentro
		if (i != 0) {
			iLiquids++;
		}
	}
}