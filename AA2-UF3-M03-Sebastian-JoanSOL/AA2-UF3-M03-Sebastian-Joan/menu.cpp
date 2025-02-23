#include "menu.h"

void scores() {

	std::cout << "------ HIGHSCORES ------" << std::endl;
	std::cout << std::endl;
	

}

void menu(char botellas[X][Y]) {

	short choice;
	bool menu = false;

	do {
		std::cout << "------WATER COLOUR SORT------" << std::endl;

		std::cout << std::endl;

		std::cout << "	1 - Nova partida" << std::endl;
		std::cout << "	2 - Scores" << std::endl;
		std::cout << "	3 - Sortir" << std::endl;

		std::cout << ">> ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "CREANDO PARTIDA..." << std::endl;

			system("pause");
			system("cls");

			inicioTablero(botellas);
			gamePlay(botellas);

			break;
		case 2:
			system("cls");

			scores();

			system("pause");

			system("cls");

			break;
		case 3:
			std::cout << std::endl;

			std::cout << "Adeu!" << std::endl;

			menu = true;

			break;
		default:
			system("cls");

			std::cout << "Escoge una opcion valida!" << std::endl;

			break;
		}
	} while (!menu);


}