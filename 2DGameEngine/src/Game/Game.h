#pragma once

// protection guard makes our header file included only once
#ifndef GAME_H
#define GAME_H

#include<SDL.h>

// C style  -> #define FPS 30
const int FPS = 60;
const int MILISECONDS_PER_FRAME = 1000 / FPS;

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	int milisecondsPreviousFrame = 0;

public:
	// Public API that other classes can invoke/interact
	Game();
	~Game();
	void Initialize();
	void Run();
	void ProcessInput();
	void Setup();
	void Update();
	void Render();
	void Destroy();

	int windowWidth;
	int windowHeight;
};

#endif