#pragma once

struct Vector2 {
	int x;
	int y;
};

struct Transform {
	Vector2 pos;
	int radius;
	int speed;
};

class Player {
public:
	Player();
	Transform transform_;
	void Move(char* keys);
	void Draw();
};