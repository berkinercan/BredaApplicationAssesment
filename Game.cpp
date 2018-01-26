#include "Game.h"
#include <SDL.h>
#include "Graphics.h"
#include "input.h"
#include <algorithm>

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	
	SDL_Event event;
	Input input;

	_mirror = Mirror(graphics, 120, 120);
	_player = Player(graphics, 100, 100);
	
	_level = Level("map 1", Vector2(100, 100), graphics);

	int LAST_UPDATE_TIME = SDL_GetTicks();
	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			_player.moveRight();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
			_player.moveUp();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
			_player.moveDown();
		}
		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)) {
			_player.stopMoving();
		}

		if (input.isKeyHeld(SDL_SCANCODE_SPACE) == true) {
			
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics);
		
	}
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	_level.draw(graphics);
	_player.draw(graphics);
	_mirror.draw(graphics);
	
	graphics.flip();
}

void Game::update(float elapsedTime) {
	_level.update(elapsedTime);
	_mirror.update(elapsedTime);
	_player.update(elapsedTime);
}

