#include "Player.h"
#include <Novice.h>

Player::Player() {
	player_.pos.x = 500;
	player_.pos.y = 360;
	player_.speed = 10;
	player_.radius = 10;
	bullet_ = nullptr;
}

Player::~Player() {
		
}

void Player::Update(char *keys) {

	if (keys[DIK_W]) {
		player_.pos.y -= player_.speed;
	}
	if (keys[DIK_S]) {
		player_.pos.y += player_.speed;
	}
	if (keys[DIK_A]) {
		player_.pos.x -= player_.speed;
	}
	if (keys[DIK_D]) {
		player_.pos.x += player_.speed;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(player_.pos.x, player_.pos.y, player_.radius, player_.radius, 0.0f, RED, kFillModeSolid);
}

