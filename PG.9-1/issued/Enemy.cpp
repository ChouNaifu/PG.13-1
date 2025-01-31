#include "Enemy.h"
#include <Novice.h>

bool Enemy::isAlive_ = true;

Enemy::Enemy(int x, int y) {
    pos_.x = x;
    pos_.y = y;
    speed_ = 10;
}
void Enemy::Update() {

    if (isAlive_) {
        pos_.x += speed_;
        if (pos_.x - 50 <= 0 || pos_.x + 50 >= 1280) {
            speed_ *= -1;
        }
    } 
}

void Enemy::Draw() {
    if (isAlive_) {
        Novice::DrawBox(pos_.x, pos_.y, 50, 50, 0.0f, WHITE, kFillModeSolid);
    }
}

int Enemy::GetPosX() { return pos_.x; }
int Enemy::GetPosY() { return pos_.y; }