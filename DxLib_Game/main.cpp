/**
* @file  main.cpp
* @brief プログラムエントリポイントです.
* @author licrosea
* @date 20200513
*/

#include <windows.h>
#include "source/singleton/CSingleton.h"
#include "source/game/CGameApplication.h"

/// MEMO : 知らないうちに、InOut的なのをつけないといけなくなったっぽいです...(20200812).
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	CGameApplication* gameApp = CSingleton< CGameApplication >::GetInstance();
	gameApp->Initialize();

	while ( gameApp->Update() && (!gameApp->IsEndGame()) )
	{
	}

	gameApp->Finalize();

	CSingletonFinalizer::Finalize(); // シングルトン終了処理.

	return 0;				// ソフトの終了 
}
