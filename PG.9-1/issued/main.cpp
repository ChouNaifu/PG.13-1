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
	Enemy* enemies[2];
	for (int i = 0; i < 2; i++) {
		enemies[i] = new Enemy(200 + i * 100, 200 + i * 100);		
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

		for (int i = 0; i < 2; i++) {
			enemies[i]->Update();
		}
		ball->Update(keys, preKeys);

		//if (ball->GetBullet().GetPosY() < 100) {
		//	Enemy::isAlive_ = false;
		//}

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
		//Novice::ScreenPrintf(20, 20, "%d", ball->GetBullet().GetPosY());
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