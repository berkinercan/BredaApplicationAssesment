#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedSprite.h"

class Graphics;
class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimation();

private:
	float _dx;
	float _dy;
	
	Direction _facing;
};
#endif

