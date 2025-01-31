#pragma once

struct Vector2 {
    int x;
    int y;
};

class Enemy {
private:
    Vector2 pos_;
    int speed_;
public:
    Enemy(int x, int y);  
    static bool isAlive_;
    void Update();
    void Draw();
    int GetPosX();
    int GetPosY();
};


