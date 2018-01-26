#include "Mirror.h"
#include "Graphics.h"

namespace mirror_constants {
	const float WALK_SPEED = 0.2f;
}

Mirror::Mirror()
{
}

Mirror::Mirror(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "Bullet.png", 0, 0, 16, 16, x, y, 100)
{
	graphics.loadImage("Bullet.png");
	setupAnimation();
	playAnimation("RunRight");
}

void Mirror::setupAnimation() {
	addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
	addAnimation(2, 0, 32, "RunUpwards", 16, 16, Vector2(0, 0));
	addAnimation(2, 0, 48, "RunDownwards", 16, 16, Vector2(0, 0));
}

void Mirror::animationDone(std::string currentAnimation) {}

void Mirror::update(float elapsedTime) {
	_x += _dx * elapsedTime;
	_y += _dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Mirror::moveLeft() {
	_dx = -mirror_constants::WALK_SPEED;
	playAnimation("RunLeft");
	_facing = LEFT;
}

void Mirror::moveRight() {
	_dx = mirror_constants::WALK_SPEED;
	playAnimation("RunRight");
	_facing = RIGHT;
}

void Mirror::moveUp() {
	_dy = -mirror_constants::WALK_SPEED;
	playAnimation("RunUpwards");
	_facing = UP;
}

void Mirror::moveDown() {
	_dy = mirror_constants::WALK_SPEED;
	playAnimation("RunDownwards");
	_facing = DOWN;
}

void Mirror::stopMoving() {
	_dx = 0.0f;
	_dy = 0.0f;
	playAnimation(_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Mirror::draw(Graphics & graphics) {
	AnimatedSprite::draw(graphics, _x, _y);
}
