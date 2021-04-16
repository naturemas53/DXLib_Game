#pragma once
/**
* @file   CSceneSample.h
* @brief  シーン定義.
* @author licrosea
* @date   
*/

#include "IScene.h"

/**
* @class CSceneSample
* @brief シーンです.
*/

class CSceneSample final : public IScene
{
public:
	CSceneSample();
	virtual ~CSceneSample();

	bool    Initalize() override; // 初期化.
	void    Finalize()  override; // 終了処理.
	IScene* Update()    override; // 更新.
	bool    Draw()      override; // 描画.
};