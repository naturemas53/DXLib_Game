﻿/**
* @file  main.cpp
* @brief プログラムエントリポイントです.
* @author licrosea
* @date 20200513
*/

#include <windows.h>
#include "DxLib.h"
#include "source/singleton/CSingleton.h"
#include "source/scene/CSceneOwner.h"
#include "source/scene/CSceneFactory.h"

/// MEMO : 知らないうちに、InOut的なのをつけないといけなくなったっぽいです...(20200812).
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode( true ); // ウィンドウモードに設定.
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	CSceneOwner sceneManager;
	using EScene = CSceneFactory::EScene;
	sceneManager.Start( CSingleton< CSceneFactory >::GetInstance().GetScene( EScene::ESceneSamle ) );

	while ( sceneManager.Update() )
	{
		WaitKey();
		break;
	}

	sceneManager.End();

	CSingletonFinalizer::Finalize(); // シングルトン終了処理.

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
