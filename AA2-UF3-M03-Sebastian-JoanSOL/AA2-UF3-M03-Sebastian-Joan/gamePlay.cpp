#include "gamePlay.h"

//guardar score

//ver score

void gamePlay(char botellas[X][Y]) {

	std::string userName;
	std::ofstream saveFile("scores.wcs", std::ios::out | std::ios::binary);

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

			std::cout << "HAS GANADO!" <<  ", con una puntuacion de: " << puntuacion << ", cual es tu nombre?" << std::endl;
			std::cout << ">> ";
			std::cin.ignore();
			std::getline(std::cin, userName);
			
			std::cout << std::endl;

			//NOTA PARA JOAN -> tuve que usar uint64_t por que el size_t me estaba dando problemas a mi, no se si es algo de mi pc pero intentalo con size_t a ver si no te da problemas xd
			uint64_t size = userName.size();

			saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
			saveFile.write(userName.c_str(), size);
			saveFile.write(reinterpret_cast<char*>(&puntuacion), sizeof(int));
			saveFile.close();

			system("pause");	
			gameOver = true;
		}
		else if (movimientos == 0) {
			std::cout << "HAS PERDIDO :(" << ", con una puntuacion de: " << puntuacion << ", cual es tu nombre?" << std::endl;
			std::cout << ">> ";
			std::cin.ignore();
			std::getline(std::cin, userName);

			std::cout << std::endl;

			uint64_t size = userName.size();

			saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
			saveFile.write(userName.c_str(), size);
			saveFile.write(reinterpret_cast<char*>(&puntuacion), sizeof(int));
			saveFile.close();


			system("pause");
			gameOver = true;
		}

		system("cls");

	} while (!gameOver);
}