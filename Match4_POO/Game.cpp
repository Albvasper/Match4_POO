#include "Game.h"
#include <iostream>

Game::Game() {
}

void Game::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	background = new Sprite();
	background->LoadImage("../Assets/Sprites/GameBackground.png");
	SDL_Color red = { 212, 30, 75 };
	points = new Text(platform->renderer, "../Assets/Fonts/Pixeled.ttf", 45, "000000000", red);
	for (int i = 0; i < 64; i++) {
		grid[i] = new Tile(platform);
		graph.Insert(grid[i]);
	}

	#pragma region GraphEdges
	graph.AddEdge(grid[0], grid[1]);
	graph.AddEdge(grid[0], grid[8]);
	graph.AddEdge(grid[1], grid[2]);
	graph.AddEdge(grid[1], grid[9]);
	graph.AddEdge(grid[2], grid[3]);
	graph.AddEdge(grid[2], grid[10]);
	graph.AddEdge(grid[3], grid[4]);
	graph.AddEdge(grid[3], grid[11]);
	graph.AddEdge(grid[4], grid[5]);
	graph.AddEdge(grid[4], grid[12]);
	graph.AddEdge(grid[5], grid[6]);
	graph.AddEdge(grid[5], grid[13]);
	graph.AddEdge(grid[6], grid[7]);
	graph.AddEdge(grid[6], grid[14]);
	graph.AddEdge(grid[7], grid[15]);
	graph.AddEdge(grid[8], grid[9]);
	graph.AddEdge(grid[8], grid[16]);
	graph.AddEdge(grid[9], grid[10]);
	graph.AddEdge(grid[9], grid[17]);
	graph.AddEdge(grid[10], grid[11]);
	graph.AddEdge(grid[10], grid[18]);
	graph.AddEdge(grid[11], grid[12]);
	graph.AddEdge(grid[11], grid[19]);
	graph.AddEdge(grid[12], grid[13]);
	graph.AddEdge(grid[12], grid[20]);
	graph.AddEdge(grid[13], grid[14]);
	graph.AddEdge(grid[13], grid[21]);
	graph.AddEdge(grid[14], grid[15]);
	graph.AddEdge(grid[14], grid[22]);
	graph.AddEdge(grid[15], grid[23]);
	graph.AddEdge(grid[16], grid[17]);
	graph.AddEdge(grid[16], grid[24]);
	graph.AddEdge(grid[17], grid[18]);
	graph.AddEdge(grid[17], grid[25]);
	graph.AddEdge(grid[18], grid[19]);
	graph.AddEdge(grid[18], grid[26]);
	graph.AddEdge(grid[19], grid[20]);
	graph.AddEdge(grid[19], grid[27]);
	graph.AddEdge(grid[20], grid[21]);
	graph.AddEdge(grid[20], grid[28]);
	graph.AddEdge(grid[21], grid[22]);
	graph.AddEdge(grid[21], grid[29]);
	graph.AddEdge(grid[22], grid[23]);
	graph.AddEdge(grid[22], grid[30]);
	graph.AddEdge(grid[23], grid[31]);
	graph.AddEdge(grid[24], grid[25]);
	graph.AddEdge(grid[24], grid[32]);
	graph.AddEdge(grid[25], grid[26]);
	graph.AddEdge(grid[25], grid[33]);
	graph.AddEdge(grid[26], grid[27]);
	graph.AddEdge(grid[26], grid[34]);
	graph.AddEdge(grid[27], grid[28]);
	graph.AddEdge(grid[27], grid[35]);
	graph.AddEdge(grid[28], grid[29]);
	graph.AddEdge(grid[28], grid[36]);
	graph.AddEdge(grid[29], grid[30]);
	graph.AddEdge(grid[29], grid[37]);
	graph.AddEdge(grid[30], grid[31]);
	graph.AddEdge(grid[30], grid[38]);
	graph.AddEdge(grid[31], grid[39]);
	graph.AddEdge(grid[32], grid[33]);
	graph.AddEdge(grid[32], grid[40]);
	graph.AddEdge(grid[33], grid[34]);
	graph.AddEdge(grid[33], grid[41]);
	graph.AddEdge(grid[34], grid[35]);
	graph.AddEdge(grid[34], grid[42]);
	graph.AddEdge(grid[35], grid[36]);
	graph.AddEdge(grid[35], grid[43]);
	graph.AddEdge(grid[36], grid[37]);
	graph.AddEdge(grid[36], grid[44]);
	graph.AddEdge(grid[37], grid[38]);
	graph.AddEdge(grid[37], grid[45]);
	graph.AddEdge(grid[38], grid[39]);
	graph.AddEdge(grid[38], grid[46]);
	graph.AddEdge(grid[39], grid[47]);
	graph.AddEdge(grid[40], grid[41]);
	graph.AddEdge(grid[40], grid[48]);
	graph.AddEdge(grid[41], grid[42]);
	graph.AddEdge(grid[41], grid[49]);
	graph.AddEdge(grid[42], grid[43]);
	graph.AddEdge(grid[42], grid[50]);
	graph.AddEdge(grid[43], grid[44]);
	graph.AddEdge(grid[43], grid[51]);
	graph.AddEdge(grid[44], grid[45]);
	graph.AddEdge(grid[44], grid[52]);
	graph.AddEdge(grid[45], grid[46]);
	graph.AddEdge(grid[45], grid[53]);
	graph.AddEdge(grid[46], grid[47]);
	graph.AddEdge(grid[46], grid[54]);
	graph.AddEdge(grid[47], grid[55]);
	graph.AddEdge(grid[48], grid[49]);
	graph.AddEdge(grid[48], grid[56]);
	graph.AddEdge(grid[49], grid[50]);
	graph.AddEdge(grid[49], grid[57]);
	graph.AddEdge(grid[50], grid[51]);
	graph.AddEdge(grid[50], grid[58]);
	graph.AddEdge(grid[51], grid[52]);
	graph.AddEdge(grid[51], grid[59]);
	graph.AddEdge(grid[52], grid[53]);
	graph.AddEdge(grid[52], grid[60]);
	graph.AddEdge(grid[53], grid[54]);
	graph.AddEdge(grid[53], grid[61]);
	graph.AddEdge(grid[54], grid[55]);
	graph.AddEdge(grid[54], grid[62]);
	graph.AddEdge(grid[55], grid[63]);
	graph.AddEdge(grid[56], grid[57]);
	graph.AddEdge(grid[57], grid[58]);
	graph.AddEdge(grid[58], grid[59]);
	graph.AddEdge(grid[59], grid[60]);
	graph.AddEdge(grid[60], grid[61]);
	graph.AddEdge(grid[61], grid[62]);
	graph.AddEdge(grid[62], grid[63]);
	#pragma endregion

	//for (int i = 0; i < 64; i++) {

		if (graph.CheckLine(grid[4]) == true) {
			graph.EliminateLine();
		}
		else {
			std::cout << "Nope" << std::endl;
			graph.Reset();
		}
	//}
}

void Game::Draw() {
	platform->RenderClear();
	platform->RenderSprite(background, 0, 0, 0);
	points->Display(575, 23, Platform::renderer);
	#pragma region Grid
	//Row 1
	grid[0]->Draw(1230, 130);
	grid[1]->Draw(1310, 130);
	grid[2]->Draw(1390, 130);
	grid[3]->Draw(1470, 130);
	grid[4]->Draw(1550, 130);
	grid[5]->Draw(1630, 130);
	grid[6]->Draw(1710, 130);
	grid[7]->Draw(1790, 130);
	
	//Row 2
	grid[8]->Draw(1230, 230);
	grid[9]->Draw(1310, 230);
	grid[10]->Draw(1390, 230);
	grid[11]->Draw(1470, 230);
	grid[12]->Draw(1550, 230);
	grid[13]->Draw(1630, 230);
	grid[14]->Draw(1710, 230);
	grid[15]->Draw(1790, 230);

	//Row 3
	grid[16]->Draw(1230, 330);
	grid[17]->Draw(1310, 330);
	grid[18]->Draw(1390, 330);
	grid[19]->Draw(1470, 330);
	grid[20]->Draw(1550, 330);
	grid[21]->Draw(1630, 330);
	grid[22]->Draw(1710, 330);
	grid[23]->Draw(1790, 330);

	//Row 4				  
	grid[24]->Draw(1230, 430);
	grid[25]->Draw(1310, 430);
	grid[26]->Draw(1390, 430);
	grid[27]->Draw(1470, 430);
	grid[28]->Draw(1550, 430);
	grid[29]->Draw(1630, 430);
	grid[30]->Draw(1710, 430);
	grid[31]->Draw(1790, 430);

	//Row 5				  
	grid[32]->Draw(1230, 530);
	grid[33]->Draw(1310, 530);
	grid[34]->Draw(1390, 530);
	grid[35]->Draw(1470, 530);
	grid[36]->Draw(1550, 530);
	grid[37]->Draw(1630, 530);
	grid[38]->Draw(1710, 530);
	grid[39]->Draw(1790, 530);

	//Row 6				  
	grid[40]->Draw(1230, 630);
	grid[41]->Draw(1310, 630);
	grid[42]->Draw(1390, 630);
	grid[43]->Draw(1470, 630);
	grid[44]->Draw(1550, 630);
	grid[45]->Draw(1630, 630);
	grid[46]->Draw(1710, 630);
	grid[47]->Draw(1790, 630);

	//Row 7				  
	grid[48]->Draw(1230, 730);
	grid[49]->Draw(1310, 730);
	grid[50]->Draw(1390, 730);
	grid[51]->Draw(1470, 730);
	grid[52]->Draw(1550, 730);
	grid[53]->Draw(1630, 730);
	grid[54]->Draw(1710, 730);
	grid[55]->Draw(1790, 730);

	//Row 6				  
	grid[56]->Draw(1230, 830);
	grid[57]->Draw(1310, 830);
	grid[58]->Draw(1390, 830);
	grid[59]->Draw(1470, 830);
	grid[60]->Draw(1550, 830);
	grid[61]->Draw(1630, 830);
	grid[62]->Draw(1710, 830);
	grid[63]->Draw(1790, 830);
	#pragma endregion
	platform->RenderPresent();
}

bool Game::Input(int keyInput) {
	if (keyInput == 27) {
		//Quit
		exit(1);
	}
}

void Game::Update() {
}

void Game::Close() {
}

Game::~Game() {
}
