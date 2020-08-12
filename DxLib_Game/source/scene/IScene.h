#pragma once
/**
* @file  IScene.h
* @brief シーンインターフェイス定義.
* @author licrosea
* @date 20200513
*/
#include <functional>
#include <string>

/// エラー出力関数の定義.
using FuncErrorPut = std::function< void( std::string errorStr ) >;

/**
* @interface IScene
* @brief シーンのインターフェイスです.
*/
class IScene
{
private:
	IScene() {}; // インターフェイスなので生成禁止.
	IScene( const IScene& ) {} // 多分コピーすることもない　はず.

public:

	virtual ~IScene() {}; // 念のためデストラクタは書いとく　ってかこれをOKにしないと解放できない気が.

	/**
	* @fn bool Initalize( FuncErrorPut i_funcErrorPut )
	* @brief シーンの初期化を行います.
	* @param[in] i_funcErrorPut エラーメッセージの出力を行う関数を指定してください.
	* @return 初期化成功でtrue 失敗時falseを返します.
	*/
	virtual bool Initalize( FuncErrorPut i_funcErrorPut = nullptr ) = 0;

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