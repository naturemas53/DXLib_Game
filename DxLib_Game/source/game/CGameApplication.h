#pragma once
/**
* @file   CGameApplication.h
* @brief  ゲームアプリ管理クラス定義.
* @author licrosea
* @date   20200813
*/

template < class T > class CSingleton;
class CSceneOwner;

/**
* @class CGameApplication
* @brief ゲームアプリ管理クラスです.
*/
class CGameApplication final
{
	// シングルトンクラスに生成を許すため、下記クラスをフレンドとしています.
	friend CSingleton<CGameApplication>;

private:
	// コピー、生成は禁止とします.
	CGameApplication();
	CGameApplication(CGameApplication&);

public:

	~CGameApplication(); // 継承しないのでvirtualはつけない.

	/// 初期化.
	bool Initialize();

	/// 終了処理.
	void Finalize();

	/// 更新.
	bool Update();

	/**
	* @fn bool IsEndGame()
	* @brief  ゲームを終わらせるか取得します.
	* @return 終わらせる場合はtrue 継続する場合はfalseが返ります.
	*/
	bool IsEndGame() { return m_isEndGame; }

	/**
	* @fn void RequestEndGame()
	* @brief   ゲーム終了のリクエストを行います.
	*/
	void RequestEndGame() { m_isEndGame = true; }

private:

	bool m_isInitialized; // 初期化済みか.
	bool m_isEndGame;     // ゲームを終了するか.
	
	CSceneOwner* m_sceneOwner; // シーン管理.
};