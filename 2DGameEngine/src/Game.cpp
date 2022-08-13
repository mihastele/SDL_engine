
// include with "" is looking in the local folder, <> (angle brackets) look in the OS include folders
#include "Game.h" // sibling file in this folder
#include <iostream>
#include <SDL.h>

// scope resolution::contructor method
Game::Game() {
	std::cout << "Game Constructor called" << std::endl;
	isRunning = false;
}

Game::~Game() {

}

void Game::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Error Initilaizing SDL" << std::endl;
		return;
	}

	// C style of doing stuff :P
	SDL_DisplayMode displayMode;
	// populating structs data by passing it by reference, so the function modifies it
	SDL_GetCurrentDisplayMode(0, &displayMode);
	// properties populated, so now we can access them
	// prevent the fake full screen to be fair play on the different resolution sizes
	windowWidth = 800;// displayMode.w;
	windowHeight = 600; // displayMode.h;
	// this is fake fullscreen due to not using the fullscreen mode, but just using the screen size without borders.

	// instead of copying entire thing to memory, it only stores the address of the struct
	window = SDL_CreateWindow("Game made by the 2D Engine of Miha Stele",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_BORDERLESS);

	if (!window) {
		std::cerr << "Error creating SDL window." << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cerr << "Error creating SDL renderer." << std::endl;
		return;
	}

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	isRunning = true;
}

void Game::Run() {
	while (isRunning) {
		ProcessInput();
		Update();
		Render();
	}

}

void Game::ProcessInput() {
	SDL_Event sdlEvent; // pure struct
	while (SDL_PollEvent(&sdlEvent)) { // passing reference of the full struct
	// if you sent the entire struct, the function copies it and that is inefficient
		switch (sdlEvent.type) {
			case SDL_QUIT: // event that system triggers when you click the close window button
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
				break;
		}
	}

}

void Game::Update() {

}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 10, 0, 20, 100);
	SDL_RenderClear(renderer);

	// ctrl + shift + space to show parameter hints on VS
	SDL_RenderPresent(renderer);
	// SDL is handling all the dirty OS APIs to create windows.

}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit(); // opposite of SDL init
}