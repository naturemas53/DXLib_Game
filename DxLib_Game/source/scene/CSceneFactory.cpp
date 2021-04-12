/**
* @file  CSceneFactory.cpp
* @brief シーンファクトリ定義.
* @author licrosea
* @date 20200513
*/

#include "CSceneFactory.h"
#include "IScene.h"
#include "../CommonUtil.h"

// MEMO : 以下派生後シーン.
#include "CSceneSample.h"
//        派生後シーン_ココマデ.

CSceneFactory::CSceneFactory()
{
	m_sceneMap.clear();
}

/// デストラクタ（ここで全開放を行います）.
CSceneFactory::~CSceneFactory()
{
	for ( MapScenePair itr : m_sceneMap )
	{
		SafeDelete( &( itr.second ) );
	}
	m_sceneMap.clear();
}

/**
* @fn IScene* GetScene( EScene i_scene )
* @brief シーンを取得します.
* @param[in] i_scene 取得したいシーンの定義名.
* @return 正常に取得できればインスタンスのポインタが　できなければfalseが返ります.
*/
IScene* CSceneFactory::GetScene( EScene i_scene )
{
	MapSceneItr itr = m_sceneMap.find( i_scene );

	// すでに生成済みであればそれを返す.
	if ( itr != m_sceneMap.end() )
	{
		return itr->second;
	}

	// ここまで来た場合は初めて指定された.
	IScene* scene = CreateScene( i_scene );

	// しっかり生成されていれば追加.
	if ( scene != nullptr ) m_sceneMap[ i_scene ] = scene;

	return scene;
}

/**
* @fn IScene* CreateScene( EScene i_scene )
* @brief シーンを生成します.
* @param[in] i_scene 生成したいシーンの定義名.
* @return 正常に生成できればインスタンスのポインタが　できなければfalseが返ります.
* @details 新規シーン作成時は、こちらに生成の処理を記述してください.
*/
IScene* CSceneFactory::CreateScene( EScene i_scene )
{
	IScene* scene = nullptr;
	switch ( i_scene )
	{
	case EScene::ESceneSamle: scene = new CSceneSample(); break;
	default: break;
	}

	return scene;
}