#pragma once
/**
* @file  IScene.h
* @brief シーンインターフェイス定義.
* @author licrosea
* @date 20200513
*/
#include <functional>
#include <string>

/**
* @interface IScene
* @brief シーンのインターフェイスです.
*/
class IScene
{
private:
	IScene( const IScene& ) {} // 多分コピーすることはない　はず.

protected:
	IScene() {}; // インターフェイスなので直接生成禁止.

public:

	virtual ~IScene() {}; // 念のためデストラクタは書いとく　ってかこれをOKにしないと解放できない気が.

	/**
	* @fn bool Initalize()
	* @brief シーンの初期化を行います.
	* @return 初期化成功でtrue 失敗時falseを返します.
	*/
	virtual bool Initalize() = 0;

	/**
	* @fn void Finalize()
	* @brief シーンの終了処理を行います.
	*/
	virtual void Finalize() = 0;

	/**
	* @fn IScene* Update()
	* @brief シーンの更新を行います.
	* @return 別シーンに遷移する場合はインスタンスのポインタが それ以外はnullptrを返します.
	*/
	virtual IScene* Update() = 0;

	/**
	* @fn bool Draw()
	* @brief シーンの描画を行います.
	* @return 描画成功でtrue それ以外はfalseを返します.
	*/
	virtual bool Draw() = 0;
};