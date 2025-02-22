#include "gamePlay.h"

void gamePlay(char& botellas[X][Y]) {
	
	bool gameOver = false;
	short botellaOrigen = 0;
	short botellaDestino = 0;
	bool checkBotellas = false;

	renderTablero(botellas);
	
	do {

		checkBotellas = false;

		std::cout << "Moves left: " << "numero" << std::endl;

		std::cout << std::endl;

		do {
			std::cout << "Que botella quieres llenar? >> ";
			std::cin >> botellaDestino;

			std::cout << std::endl;

			std::cout << "Que botella quieres vaciar? >> ";
			std::cin >> botellaOrigen;

			short contadorEspacio = 0;

			for (int i = 0; i < Y; i++) {

				if (botellas[botellaDestino][i] != ' ') {
					contadorEspacio++;

					if (contadorEspacio == 3) {
						std::cout << "Botella llena, escoge otra!" << std::endl;

						checkBotellas = false;
					}
				}
			}

			std::cout << std::endl;

			if (botellaOrigen <= 0 || botellaOrigen >= 7 || botellaDestino <= 0 || botellaDestino >= 7) {
				std::cout << "Esas botellas no existen! Escoge otras" << std::endl;

				std::cout << std::endl;
			}
			else {
				checkBotellas = true;
			}

		} while (!checkBotellas);

		botellaDestino -= 1;
		botellaOrigen -= 1;

		//system("cls");


		for (int j = Y; j >= 0; j--) {

			if (botellas[botellaDestino][j] == ' ') {

				botellas[botellaDestino][j] = botellas[botellaOrigen][i];

				botellas[botellaOrigen][i] = '  ';

				i = Y;
				j = -1;
			}
		}



	} while (!gameOver);
}