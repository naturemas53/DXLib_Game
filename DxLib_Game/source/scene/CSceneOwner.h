#pragma once
/**
* @file  CSceneOwner.h
* @brief シーンオーナー定義.
* @author licrosea
* @date 20200513
*/

#include "IScene.h"

/**
* @class CSceneOwner
* @brief シーンオーナーです（シーンの親のような立ち位置です）.
*/
class CSceneOwner final
{
private:

	// このクラスをコピーすることはない　はず.
	CSceneOwner( CSceneOwner& );

public:

	CSceneOwner();

	// このクラスは継承されることがないため、仮想デストラクタにしません.
	~CSceneOwner();

	/// シーンを始めます.
	bool Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut = nullptr );

	/// シーンを終了します.
	void End();

	/// 更新を行います.
	bool Update();

private:

	/// シーン変更を行います.
	bool ChangeScene( IScene* i_nextScene );

	IScene* m_currentScene; // 現在のシーンです.
	FuncErrorPut m_funcErrorPut; // エラー出力の関数です.
};