#include "Player.h"
#include "Graphics.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}
Player::Player() {}

Player::Player(Graphics & graphics, float x, float y) :
	AnimatedSprite(graphics, "MyChar.png", 0, 0, 16, 16, x, y, 100) 
{
	graphics.loadImage("MyChar.png");
	setupAnimation();
	playAnimation("RunRight");
}

void Player::setupAnimation() {
	addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 32, "RunUpwards", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 48, "RunDownwards", 16, 16, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::update(float elapsedTime) {
	_x += _dx * elapsedTime;
	_y += _dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::moveLeft() {
	_dx = -player_constants::WALK_SPEED;
	playAnimation("RunLeft");
	_facing = LEFT;
}

void Player::moveRight() {
	_dx = player_constants::WALK_SPEED;
	playAnimation("RunRight");
	_facing = RIGHT;
}

void Player::moveUp() {
	_dy = -player_constants::WALK_SPEED;
	playAnimation("RunUpwards");
	_facing = UP;
}

void Player::moveDown() {
	_dy = player_constants::WALK_SPEED;
	playAnimation("RunDownwards");
	_facing = DOWN;
}

void Player::stopMoving() {
	_dx = 0.0f;
	_dy = 0.0f;
	playAnimation(_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::draw(Graphics & graphics) {
	AnimatedSprite::draw(graphics, _x, _y);
}