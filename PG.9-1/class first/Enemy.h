#pragma once

class Enemy {
public:
	Enemy();
	void Move();
	void Draw();
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
};

