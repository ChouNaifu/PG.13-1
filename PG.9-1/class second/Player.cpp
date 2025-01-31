#include "Player.h"
#include <Novice.h>

Player::Player() {
	transform_.pos.x = 500;
	transform_.pos.y = 360;
	transform_.speed = 10;
	transform_.radius = 10;
}

void Player::Move(char *keys) {

	if (keys[DIK_W]) {
		transform_.pos.y -= transform_.speed;
	}
	if (keys[DIK_S]) {
		transform_.pos.y += transform_.speed;
	}
	if (keys[DIK_A]) {
		transform_.pos.x -= transform_.speed;
	}
	if (keys[DIK_D]) {
		transform_.pos.x += transform_.speed;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(transform_.pos.x, transform_.pos.y, transform_.radius, transform_.radius, 0.0f, RED, kFillModeSolid);
}
