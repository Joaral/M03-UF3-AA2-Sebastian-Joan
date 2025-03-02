#include "gamePlay.h"

//ver score
//cambiar magic numbers


//Funcion de gameplay que recibe el array de botellas creado en main
void gamePlay(char botellas[X][Y]) {
	
	//Variables para el guardado de puntuaciones
	std::string userName;
	std::ofstream saveFile("scores.wcs", std::ios::app | std::ios::binary);
	std::vector<std::string> savedNames;
	std::vector<int> savedScores;

	//Variables para el gameplay
	bool gameOver = false;
	bool checkBotellas = false;
	short botellaOrigen = 0;
	short botellaDestino = 0;
	short movimientos = 10;

	//Do while que controla el loop del gameplay
	do {
	
		//Renderizado del tablero
		renderTablero(botellas);
		
		checkBotellas = false;

		std::cout << "Moves left: " << movimientos << std::endl;

		std::cout << std::endl;

		//Do while que controla la eleccion de las botellas
		do {
		
			//Variable que controla cuantos errores hay en la eleccion del jugador
			short errorCounter = 0;

			//Eleccion de botellas
			std::cout << "Que botella quieres llenar? >> ";
			std::cin >> botellaDestino;

			std::cout << std::endl;

			std::cout << "Que botella quieres vaciar? >> ";
			std::cin >> botellaOrigen;

			std::cout << std::endl;

			//Check para ver si las botellas elegidas existen
			if (botellaOrigen <= 0 || botellaOrigen >= 7 || botellaDestino <= 0 || botellaDestino >= 7) {
				std::cout << "Esas botellas no existen! Escoge otras" << std::endl;

				std::cout << std::endl;

				errorCounter += 1;
			}

			//Normalizacion de las elecciones del jugador
			botellaDestino -= 1;
			botellaOrigen -= 1;

			//Variable para contar los espacios de las botellas
			short contadorEspacio = 0;

			//for para checkear si la botella por llenar esta llena
			for (int i = 0; i < Y; i++) {
				//Si el espacio i de la botella no esta vacia sumamos 1 a contadorEspacio
				if (botellas[botellaDestino][i] != ' ') {
					contadorEspacio++;

					//Si contadorEspacio es igual 3, la botella esta llena
					if (contadorEspacio == 3) {
						std::cout << "La botella que quieres llenar esta llena, escoge otra!" << std::endl;
						std::cout << std::endl;
						errorCounter += 1;

						checkBotellas = false;
					}
				}

			}

			//Check para ver si el usuario esocgio la misma botella para llenar y vaciar
			if (botellaDestino == botellaOrigen) {
				std::cout << "No puedes escoger la misma botella!" << std::endl;
				std::cout << std::endl;
				errorCounter += 1;
			}

			//Reset de la variable contadorEspacio para el siguiente check
			contadorEspacio = 0;

			//for para checkear si la botella por vaciar esta vacia
			for (int i = 0; i < Y; i++) {
				//Si el espacio i de la botella esta vacia sumamos 1 a contadorEspacio
				if (botellas[botellaOrigen][i] == ' ') {
					contadorEspacio++;

					//Si contadorEspacio es igual 3, la botella esta vacia
					if (contadorEspacio == 3) {
						std::cout << "La botella que quieres vaciar esta vacia, escoge otra!" << std::endl;

						std::cout << std::endl;
						errorCounter += 1;

						checkBotellas = false;
					}
				}
			
			}

			//Check para saber si podemos seguir con el juego o no
			if(errorCounter == 0){
				checkBotellas = true;
				movimientos -= 1;
			}

		} while (!checkBotellas);		

		//Variable para guardar el valor de ciertos espacios para chequeos
		char casilla;

		//For que mira cual es el liquido que esta m�s arriba en la botella que queremos vaciar
		for (int j = 0; j < Y; j++) {
			
			//Si la posicion j de la botella que queremos vaciar no esta vacia
			if (botellas[botellaOrigen][j] != ' ') {
				
				//guardamos el liquido epsecificado en casilla
				casilla = botellas[botellaOrigen][j];

				//borramos esa posicion para vaciar la botella
				botellas[botellaOrigen][j] = ' ';

				//Igualamos j a Y para acabar el for
				j = Y;

			}
		}

		//For que mira cual es el espacio que esta m�s abajo en la botella que queremos llenar
		for (int j = Y - 1; j >= 0; j--) {
			
			//Si la posicion j de la botella que queremos vaciar esta vacia
			if (botellas[botellaDestino][j] == ' ') {
				
				//igualamos la posicion de la botella con casilla para poner el liquido especificado
				botellas[botellaDestino][j] = casilla;

				//Igualamos j a -1 para acabar el for
				j = -1;
			}

		}

		//Variables para chequeos donde miramos si las botellas estan llenas o vacias
		short espacioLleno = 0;
		short botellasLlenas = 0;
		short espacioVacio = 0;
		short botellaVacia = 0;

		//for que mira que botellas estan llenas
		for (int i = 0; i < X; i++) {
			
			//guardando el ultimo liquido de la botella en casilla para los checks
			casilla = botellas[i][2];
			espacioLleno = 0;

			for (int j = 0; j < Y; j++) {

				//si la posicion j de la botella i es igual a casilla o esta vacia
				if(botellas[i][j] == casilla || botellas[i][j] == ' ') {
					
					//hay un espacio lleno
					espacioLleno++;

				}
				
				//Si la posicion j de la botella i esta vacia
				if (botellas[i][j] == ' ') {
					
					//hay un espacio vacio
					espacioVacio++;
				}

				//si hay 3 espacios llenos
				if (espacioLleno == 3) {
					
					//Hay 1 botella llena
					botellasLlenas++;
				}

				//si hay 3 espacios vacios
				if (espacioVacio == 3) {
					
					//hay una botella vacia
					botellaVacia++;
				}
			}
		}

		int puntuacion = 0;

		//Sistema de puntuacion
		puntuacion += (botellasLlenas * 30) + (botellaVacia * 50) + (movimientos * 3);

		//Check para saber si el jugador ha ganado
		if (botellasLlenas == 6) {

			std::cout << "HAS GANADO!" <<  ", con una puntuacion de: " << puntuacion << ", cual es tu nombre?" << std::endl;
			std::cout << ">> ";
			std::cin.ignore();
			std::getline(std::cin, userName);
			
			std::cout << std::endl;

			std::ifstream loadFile("scores.wcs", std::ios::in | std::ios::binary);
			bool leyendo = true; // Usamos 'leyendo' para controlar el bucle
			bool found = false;

			if (!loadFile.is_open()) {
				std::cout << "Error al abrir el archivo de puntuaciones o no hay puntuaciones guardadas." << std::endl;
				return;
			}

			while (leyendo) {
				//NOTA PARA MART� -> tuvimos que usar uint64_t por que el size_t no nos lee corecatmente los user_name, seguramente sea por el tama�o por el que los guarda, y investigando hemos encontrado este otro formato que si funciona.
				uint64_t fileSize = 0;
				std::string fileUsername;
				int fileScore = 0;

				// Lee el tama�o del nombre del usuario
				if (!loadFile.read(reinterpret_cast<char*>(&fileSize), sizeof(uint64_t))) {
					// Si no se puede leer m�s datos, terminamos la lectura
					leyendo = false;
					gameOver = true;
					break; // Salimos del bucle si no se puede leer el tama�o
				}

				// Reservamos el espacio para el nombre del usuario
				fileUsername.resize(fileSize);

				// Lee el nombre del usuario
				if (!loadFile.read(&fileUsername[0], fileSize)) {
					std::cout << "Error al leer el nombre del usuario." << std::endl;
					leyendo = false;
					break; // Salimos si hubo un error al leer el nombre
				}

				// Lee la puntuaci�n
				if (!loadFile.read(reinterpret_cast<char*>(&fileScore), sizeof(int))) {
					std::cout << "Error al leer la puntuacion." << std::endl;
					leyendo = false;
					break; // Salimos si hubo un error al leer la puntuaci�n
				}

				if (fileUsername == userName) {

					if (puntuacion > fileScore) {

						std::cout << "Hiciste una puntuacion mas alta, felicidades!!" << std::endl;

						fileScore = puntuacion;
						fileUsername = userName;
						system("pause");

					}
					else {

						std::cout << "Tienes una puntuacion mas alta ya guardada..." << std::endl;
						system("pause");

						fileUsername = userName;
						leyendo = false;
						gameOver = true;

					}

					found = true;

				}



				savedNames.push_back(fileUsername);
				savedScores.push_back(fileScore);

			}

			loadFile.close();

			if (found == false) {
				//Guardamos el tama�o del nombre de usuario
				std::ofstream saveFile("scores.wcs", std::ios::app | std::ios::binary);
				uint64_t size = userName.size();

				//Escribimos el nombre del usuario y la puntuacion del usuario
				saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
				saveFile.write(userName.c_str(), size);
				saveFile.write(reinterpret_cast<char*>(&puntuacion), sizeof(int));
				saveFile.close();

				system("pause");

				leyendo = false;
				gameOver = true;

			}
			else {
				//Guardamos el tama�o del nombre de usuario
				std::ofstream saveFile("scores.wcs", std::ios::trunc | std::ios::binary);

				if (!saveFile.is_open()) {
					std::cout << "ERROR: no encontre el archivo para guardar!" << std::endl;
				}

				for (uint64_t i = 0; i < savedNames.size(); i++) {

					uint64_t size = savedNames[i].size();

					//Escribimos el nombre del usuario y la puntuacion del usuario
					saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
					saveFile.write(savedNames[i].c_str(), size);
					saveFile.write(reinterpret_cast<char*>(&savedScores[i]), sizeof(int));


				}
				saveFile.close();
			}

		}
		//Si ya no tiene movimientos el jugador ha perdido
		else if (movimientos == 0) {
			std::cout << "HAS PERDIDO :(" << ", con una puntuacion de: " << puntuacion << ", cual es tu nombre?" << std::endl;
			std::cout << ">> ";
			std::cin.ignore();
			std::getline(std::cin, userName);

			std::cout << std::endl;

			std::ifstream loadFile("scores.wcs", std::ios::in | std::ios::binary);
			bool leyendo = true; // Usamos 'leyendo' para controlar el bucle
			bool found = false;

			if (!loadFile.is_open()) {
				std::cout << "Error al abrir el archivo de puntuaciones o no hay puntuaciones guardadas." << std::endl;
				return;
			}

			while (leyendo) {
				//NOTA PARA MART� -> tuvimos que usar uint64_t por que el size_t no nos lee corecatmente los user_name, seguramente sea por el tama�o por el que los guarda, y investigando hemos encontrado este otro formato que si funciona.
				uint64_t fileSize = 0;
				std::string fileUsername;
				int fileScore = 0;

				// Lee el tama�o del nombre del usuario
				if (!loadFile.read(reinterpret_cast<char*>(&fileSize), sizeof(uint64_t))) {
					// Si no se puede leer m�s datos, terminamos la lectura
					leyendo = false;
					gameOver = true;
					break; // Salimos del bucle si no se puede leer el tama�o
				}

				// Reservamos el espacio para el nombre del usuario
				fileUsername.resize(fileSize);

				// Lee el nombre del usuario
				if (!loadFile.read(&fileUsername[0], fileSize)) {
					std::cout << "Error al leer el nombre del usuario." << std::endl;
					leyendo = false;
					break; // Salimos si hubo un error al leer el nombre
				}

				// Lee la puntuaci�n
				if (!loadFile.read(reinterpret_cast<char*>(&fileScore), sizeof(int))) {
					std::cout << "Error al leer la puntuacion." << std::endl;
					leyendo = false;
					break; // Salimos si hubo un error al leer la puntuaci�n
				}

				if (fileUsername == userName) {

					if (puntuacion > fileScore) {

						std::cout << "Hiciste una puntuacion mas alta, felicidades!!" << std::endl;

						fileScore = puntuacion;
						system("pause");

					}
					else {

						std::cout << "Tienes una puntuacion mas alta ya guardada..." << std::endl;
						system("pause");

						leyendo = false;
						gameOver = true;

					}

					found = true;

				}

				savedNames.push_back(fileUsername);
				savedScores.push_back(fileScore);

			}

			loadFile.close();

			if (found == false) {
							//Guardamos el tama�o del nombre de usuario
				std::ofstream saveFile("scores.wcs", std::ios::app | std::ios::binary);
				uint64_t size = userName.size();

				//Escribimos el nombre del usuario y la puntuacion del usuario
				saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
				saveFile.write(userName.c_str(), size);
				saveFile.write(reinterpret_cast<char*>(&puntuacion), sizeof(int));
				saveFile.close();

				system("pause");

				leyendo = false;
				gameOver = true;
			
			}
			else {
				//Guardamos el tama�o del nombre de usuario
				std::ofstream saveFile("scores.wcs", std::ios::trunc | std::ios::binary);

				if (!saveFile.is_open()) {
					std::cout << "ERROR: no encontre el archivo para guardar!" << std::endl;
				}

				for (uint64_t i = 0; i < savedNames.size(); i++) {

					uint64_t size = savedNames[i].size();

					//Escribimos el nombre del usuario y la puntuacion del usuario
					saveFile.write(reinterpret_cast<char*>(&size), sizeof(uint64_t));
					saveFile.write(savedNames[i].c_str(), size);
					saveFile.write(reinterpret_cast<char*>(&savedScores[i]), sizeof(int));


				}
				saveFile.close();
			}
		}

		system("cls");

	} while (!gameOver);
}