#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Mirror.h"
#include "Level.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
	Mirror _mirror;

	Level _level;
};
#endif // !GAME_H

