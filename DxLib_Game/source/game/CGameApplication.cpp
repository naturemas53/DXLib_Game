/**
* @file   CGameApplication.cpp
* @brief  ゲームアプリ管理クラス実装.
* @author licrosea
* @date   20200813
*/

#include "CGameApplication.h"

#include "../singleton/CSingleton.h"
#include "../scene/CSceneFactory.h"
#include "../scene/CSceneOwner.h"
#include "../CommonUtil.h"
#include "DxLib.h"

// コンストラクタ.
CGameApplication::CGameApplication() : 
	m_isInitialized( false ),
	m_isEndGame( false ), 
	m_sceneOwner( nullptr )
{}

// デストラクタ.
CGameApplication::~CGameApplication()
{}

/**
* @fn bool Initalize()
* @brief ゲームの初期化を行います.
* @return 初期化成功でtrue 失敗時falseを返します.
*/
bool CGameApplication::Initialize()
{
	ChangeWindowMode(true); // ウィンドウモードに設定.

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return false;			// エラーが起きたら直ちに終了
	}

	m_sceneOwner = new CSceneOwner();
	using EScene = CSceneFactory::EScene;
	m_sceneOwner->Start(CSingleton< CSceneFactory >::GetInstance()->GetScene(EScene::ESceneSamle));

	m_isInitialized = true;
	return true;
}

/**
* @fn void Finalize()
* @brief ゲームの終了処理を行います.
*/
void CGameApplication::Finalize()
{
	m_sceneOwner->End();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	SafeDelete(&m_sceneOwner);
	
	m_isInitialized = false;
}

/**
* @fn bool Update()
* @brief  ゲームの更新を行います.
* @return 正常に動作している場合はtrue 何かしら不具合が出た場合はfalseを返します.
*/
bool CGameApplication::Update()
{
	// 未初期化.
	if (!m_isInitialized) return false;

	m_sceneOwner->Update();

	// DxLibの方でなんか起きたっぽいですよ.
	if( ProcessMessage()  < 0 ) return false;

	return true;
}