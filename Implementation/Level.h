#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "Globals.h"

class Graphics;
struct SDL_Texture;

class Level {
public:
	Level();
	~Level();
	Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
	void update(int elapsedTime);
	void draw(Graphics &graphics);

private:
	std::string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	SDL_Texture* _backgroundTexture;

	void loadMap(std::string mapName, Graphics &graphics);
};

#endif 

