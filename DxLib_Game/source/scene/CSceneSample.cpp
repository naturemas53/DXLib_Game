/**
* @file   CSceneSample.cpp
* @brief  シーン実装.
* @author licrosea
* @date 
*/

#include "CSceneSample.h"
#include "DxLib.h"
#include "../singleton/CSingleton.h"
#include "../game/CGameApplication.h"

CSceneSample::CSceneSample()
{}

CSceneSample::~CSceneSample()
{}

/**
* @fn bool Initalize()
* @brief シーンの初期化を行います.
* @return 初期化成功でtrue 失敗時falseを返します.
*/
bool CSceneSample::Initalize()
{
	return true;
}

/**
* @fn void Finalize()
* @brief シーンの終了処理を行います.
*/
void CSceneSample::Finalize()
{}

/**
* @fn IScene* Update()
* @brief シーンの更新を行います.
* @return 別シーンに遷移する場合はインスタンスのポインタが それ以外はnullptrを返します.
*/
IScene* CSceneSample::Update()
{
	WaitKey();
	CSingleton< CGameApplication >::GetInstance()->RequestEndGame();

	return nullptr;
}

/**
* @fn bool Draw()
* @brief シーンの描画を行います.
* @return 描画成功でtrue それ以外はfalseを返します.
*/
bool CSceneSample::Draw()
{

	return true;
}