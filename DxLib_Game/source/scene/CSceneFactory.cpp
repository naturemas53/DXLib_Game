/**
* @file  CSceneFactory.cpp
* @brief シーンファクトリ定義.
* @author licrosea
* @date 20200513
*/

#include "CSceneFactory.h"
#include "IScene.h"
#include "../CommonUtil.h"

CSceneFactory::CSceneFactory()
{
	m_sceneMap.clear();
}

/// デストラクタ（ここで全開放を行います）.
CSceneFactory::~CSceneFactory()
{
	for ( MapScenePair itr : m_sceneMap )
	{
		safeDelete( &( itr.second ) );
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
* @return 正常に生成できればインスタンスのポインタが　できなければfalseが返ります.7
* @details 新規シーン作成時は、こちらに生成の処理を記述してください.
*/
IScene* CSceneFactory::CreateScene( EScene i_scene )
{
	IScene* scene = nullptr;
	switch ( i_scene )
	{
	default: break;
	}

	return scene;
}