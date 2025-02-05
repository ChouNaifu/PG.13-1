#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1B_10_チョウ_ナイーフ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* ball = new Player;
	Bullet* bullet = nullptr;
	Enemy* enemies[2];
	for (int i = 0; i < 2; i++) {
		enemies[i] = new Enemy(200 + i * 400, 200 + i * 100);		
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			if (bullet == nullptr) {
				bullet = new Bullet(ball->player_.pos.x, ball->player_.pos.y);
			}
		}
		if (!Enemy::isAlive_) {
			if (keys[DIK_R] && !preKeys[DIK_R]) {
				for (int i = 0; i < 2; i++) {
					enemies[i] = new Enemy(200 + i * 400, 200 + i * 100);
				}
			}
		}

		if (bullet != nullptr) {
			bullet->Update();
			for (int i = 0; i < 2; i++) {
				if (bullet->GetPosX() > enemies[i]->GetPosX() && bullet->GetPosX() < enemies[i]->GetPosX() + 50 &&
					bullet->GetPosY() > enemies[i]->GetPosY() && bullet->GetPosY() < enemies[i]->GetPosY() + 50) {
					Enemy::isAlive_ = false;
				}
			}
			if (bullet->GetPosY() < 0) {
				delete bullet;
				bullet = nullptr;
			}
		}
		for (int i = 0; i < 2; i++) {
			enemies[i]->Update();
		}
		ball->Update(keys);
	

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		if (Enemy::isAlive_) {
			for (int i = 0; i < 2; i++) {
				enemies[i]->Draw();
			}
		}	
		ball->Draw();
		if (bullet != nullptr) {
			bullet->Draw();
		}
		//Novice::ScreenPrintf(20, 20, "%d", bullet->GetPosY());
		///
		/// ↑描画処理ここまで
		///
		
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}