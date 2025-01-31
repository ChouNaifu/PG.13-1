#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
    posX_ = 10;
    posY_ = 360;
    speedX_ = 10;
    radius_ = 10;
}

void Enemy::Move() {
	posX_ += speedX_;

	if (posX_ > 1270) {
		speedX_ = -speedX_;
	}
	if (posX_ < 10) {
		speedX_ = -speedX_;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}