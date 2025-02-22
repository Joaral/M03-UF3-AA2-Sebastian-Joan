/*
#include <iostream>
#include <vector>
#define X 6
#define Y 3
void main() {
	srand(time(NULL));
	char liquids[4]{ 'X', 'O', '#', 'S' };
	short iLiquids = 0;
	short posRand = 0;
	char botellas[X][Y];
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++)
		{
			iLiquids = rand() % 4;
			if (i == 0) {
				botellas[j][i] = ' ';
			}
			else {
				botellas[j][i] = liquids[iLiquids];
			}
		}
	}
	for (int c = 0; c < 2; c++) {
		posRand = rand() % 6;
		botellas[posRand][0] = liquids[iLiquids];
	}
	iLiquids = 0;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i == 0) {
				std::cout << char(92) << " / ";
			}
			else if (i == 4) {
				std::cout << "''' ";
			}
			else if (i == 5) {
				std::cout << ' ' << j + 1 << "  ";
			}
			else {
				std::cout << '|' << botellas[j][iLiquids] << "| ";
			}
		}
		std::cout << std::endl;
		if (i != 0) {
			iLiquids++;
		}
	}
}
*/
#include <iostream>
#include "menu.h"
#include "tablero.h"
#include "gamePlay.h"

void main() {
	char botellas[X][Y];

	menu(botellas);
	
}