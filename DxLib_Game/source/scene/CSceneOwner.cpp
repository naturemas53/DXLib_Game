/**
* @file  CSceneOwner.cpp
* @brief シーンオーナー実装.
* @author licrosea
* @date 20200513
*/

#include "CSceneOwner.h"

CSceneOwner::CSceneOwner() : m_currentScene( nullptr ), m_funcErrorPut( nullptr )
{
}

CSceneOwner::~CSceneOwner()
{
	m_currentScene = nullptr;
	m_funcErrorPut = nullptr;
}

/**
* @fn bool Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut )
* @brief シーンを開始します.
* @param[in] i_firstScene どのシーンから始めるか.
* @param[in] i_funcErrorPut エラー出力時の関数.
* @return 正常に開始できればtrue できなければfalseを返します.
*/
bool CSceneOwner::Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut )
{
	m_currentScene = i_firstScene;
	m_funcErrorPut = i_funcErrorPut;

	return this->ChangeScene( i_firstScene );
}

/**
* @fn void End()
* @brief シーンを終了します.
*/
void CSceneOwner::End()
{
	m_currentScene->Finalize();
}

/**
* @fn bool Update()
* @brief シーンを更新します.
* @return 正常稼働中はtrue 問題発生でfalseを返します.
*/
bool CSceneOwner::Update()
{
	m_currentScene->Draw();

	IScene* nextScene = m_currentScene->Update();

	// 取り急ぎ、シーン遷移がなければセーフとします.
	if ( nextScene == nullptr ) return true;

	return this->ChangeScene( nextScene );
}

/**
* @fn bool ChangeScene( IScene* i_nextScene )
* @brief 次のシーンを開始します.
* @param[in] i_nextScene 次に開始するシーン.
* @return 正常に開始できればtrue できなければfalseを返します.
*/
bool CSceneOwner::ChangeScene( IScene* i_nextScene )
{
	if( m_currentScene != nullptr ) m_currentScene->Finalize();

	m_currentScene = i_nextScene;

	if ( !m_currentScene->Initalize( m_funcErrorPut ) )
	{
		// 念のため、終了処理を行う.
		m_currentScene->Finalize();
		return false;
	}

	return true;
}