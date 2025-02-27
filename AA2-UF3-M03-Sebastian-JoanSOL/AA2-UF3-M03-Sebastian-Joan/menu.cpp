#include "menu.h"

//funcion para enseñar las puntuaciones
void scores() {

	std::cout << "------ HIGHSCORES ------" << std::endl;
	std::cout << std::endl;
	

}

//Funcion de menu principal al que le pasamos el array de botellas creado en main
void menu(char botellas[X][Y]) {

	short choice;
	bool menu = false;

	//do while para el loop del menu
	do {
		//Opciones del menu
		std::cout << "------WATER COLOUR SORT------" << std::endl;

		std::cout << std::endl;

		std::cout << "	1 - Nova partida" << std::endl;
		std::cout << "	2 - Scores" << std::endl;
		std::cout << "	3 - Sortir" << std::endl;

		std::cout << ">> ";
		std::cin >> choice;

		//Switch case para el menu
		switch (choice) {
		case 1:
			//Creacion de partida
			std::cout << "CREANDO PARTIDA..." << std::endl;

			system("pause");
			system("cls");

			//Llamada de inicioTablero para llenar el tablero
			inicioTablero(botellas);
			//Inicio del gameplay
			gamePlay(botellas);

			break;
		case 2:
			//Enseñando las puntuaciones de los jugadores
			system("cls");

			scores();

			system("pause");

			system("cls");

			break;
		case 3:
			//Salida del juego
			std::cout << std::endl;

			std::cout << "Adeu!" << std::endl;

			menu = true;

			break;
		default:
			//Caso por si el usuario no elige una opcion valida
			system("cls");
			std::cout << "Escoge una opcion valida!" << std::endl;

			break;
		}
	} while (!menu);


}