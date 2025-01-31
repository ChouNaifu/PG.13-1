#pragma once
#include "Bullet.h"

struct Transform {
	Vector2 pos;
	int radius;
	int speed;
};

class Player {
public:
	Player();
	~Player();
	int posX_;
	Transform player_;
	Bullet *bullet_;

	void Update(char* keys, char* preKeys);
	void Draw();
	Bullet GetBullet() const;
};