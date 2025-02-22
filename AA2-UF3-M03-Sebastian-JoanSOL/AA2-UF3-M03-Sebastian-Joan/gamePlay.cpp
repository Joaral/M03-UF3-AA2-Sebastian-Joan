#include "gamePlay.h"

//guardar score

//ver score

void gamePlay(char botellas[X][Y]) {
	
	bool gameOver = false;
	short botellaOrigen = 0;
	short botellaDestino = 0;
	bool checkBotellas = false;

	short movimientos = 10;

	
	do {
	
		renderTablero(botellas);

		
		checkBotellas = false;

		std::cout << "Moves left: " << movimientos << std::endl;

		std::cout << std::endl;

		do {
		short errorCounter = 0;
			std::cout << "Que botella quieres llenar? >> ";
			std::cin >> botellaDestino;

			std::cout << std::endl;

			std::cout << "Que botella quieres vaciar? >> ";
			std::cin >> botellaOrigen;

			std::cout << std::endl;

			if (botellaOrigen <= 0 || botellaOrigen >= 7 || botellaDestino <= 0 || botellaDestino >= 7) {
				std::cout << "Esas botellas no existen! Escoge otras" << std::endl;

				std::cout << std::endl;

				errorCounter += 1;
			}

			botellaDestino -= 1;
			botellaOrigen -= 1;

			short contadorEspacio = 0;

			for (int i = 0; i < Y; i++) {

				if (botellas[botellaDestino][i] != ' ') {
					contadorEspacio++;

					if (contadorEspacio == 3) {
						std::cout << "La botella que quieres llenar esta llena, escoge otra!" << std::endl;
						std::cout << std::endl;
						errorCounter += 1;

						checkBotellas = false;
					}
				}

			}

			if (botellaDestino == botellaOrigen) {
				std::cout << "No puedes escoger la misma botella!" << std::endl;
				std::cout << std::endl;
				errorCounter += 1;
			}

			contadorEspacio = 0;

			for (int i = 0; i < Y; i++) {
				if (botellas[botellaOrigen][i] == ' ') {
					contadorEspacio++;

					if (contadorEspacio == 3) {
						std::cout << "La botella que quieres vaciar esta vacia, escoge otra!" << std::endl;

						std::cout << std::endl;
						errorCounter += 1;

						checkBotellas = false;
					}
				}
			
			}

			if(errorCounter == 0){
				checkBotellas = true;
				movimientos -= 1;
			}

		} while (!checkBotellas);

		system("cls");

		char casilla;

		for (int j = 0; j < Y; j++) {

			if (botellas[botellaOrigen][j] != ' ') {

				casilla = botellas[botellaOrigen][j];

				botellas[botellaOrigen][j] = ' ';

				j = Y;

			}
		}

		for (int j = Y - 1; j >= 0; j--) {

			if (botellas[botellaDestino][j] == ' ') {
				botellas[botellaDestino][j] = casilla;

				j = -1;
			}

		}

		short espacioLleno = 0;
		short botellasLlenas = 0;
		short espacioVacio = 0;
		short botellaVacia = 0;


		for (int i = 0; i < X; i++) {
			casilla = botellas[i][2];
			espacioLleno = 0;

			for (int j = 0; j < Y; j++) {

				if(botellas[i][j] == casilla || botellas[i][j] == ' ') {
					
					espacioLleno++;

				}
				
				if (botellas[i][j] == ' ') {
					espacioVacio++;
				}

				if (espacioLleno == 3) {
					botellasLlenas++;
				}

				if (espacioVacio == 3) {
					botellaVacia++;
				}
			}
		}

		int puntuacion = 0;

		puntuacion += (botellasLlenas * 30) + (botellaVacia * 50) + (movimientos * 3);

		if (botellasLlenas == 6) {

			std::cout << "HAS GANADO! nombre equis de " << puntuacion<< std::endl;
			gameOver = true;
		}
		else if (movimientos == 0) {
			std::cout << "HAS PERDIDO :( ,te quedaste sin movimientos, suerte la proxima!" << std::endl;
			gameOver = true;
		}


	} while (!gameOver);
}