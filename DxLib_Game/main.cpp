/**
* @file  main.cpp
* @brief プログラムエントリポイントです.
* @author licrosea
* @date 20200513
*/

#include <windows.h>
#include "DxLib.h"
#include "source/singleton/CSingleton.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode( true ); // ウィンドウモードに設定.
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	WaitKey();				// キー入力待ち

	CSingletonFinalizer::Finalize(); // シングルトン終了処理.

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
