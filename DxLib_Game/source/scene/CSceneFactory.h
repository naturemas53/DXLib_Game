#pragma once
/**
* @file  CSceneFactory.h
* @brief シーンファクトリ定義.
* @author licrosea
* @date 20200513
*/

#include <map>

class IScene;
template < class T > class CSingleton;

/**
* @class CSceneFactory
* @brief シーンの生成を行います.
*/
class CSceneFactory final
{
	// シングルトンクラスに生成を許すため、下記クラスをフレンドとしています.
	friend CSingleton<CSceneFactory>;

private:
	// コピー、生成は禁止とします.
	CSceneFactory();
	CSceneFactory( CSceneFactory& );

public:
	// このクラスは継承されることがないため、仮想デストラクタにしません.
	~CSceneFactory();

	/**
	* @enum  EScene
	* @brief インスタンスを取得する際に使用します.
	*        ...めんどくさいかもしれませんが、新規シーンを作成した際は.
	*        こちらに新定義を追加し、その後.
	*        CreateSceneに生成処理を記述して下さい。(いい方法が思いつかなかったんです...).
	*/
	enum class EScene
	{
		ESceneSamle, // サンプルシーン.
		ESceneNum    // シーン総数　通常は使わない　はず...
	};

	/// シーンの取得を行います.
	IScene* GetScene( EScene i_scene );

private:

	/// シーンの生成を行います.
	IScene* CreateScene( EScene i_scene );

	using MapSceneItr  = std::map< EScene, IScene* >::iterator;
	using MapScenePair = std::pair< EScene, IScene* >;

	std::map< EScene, IScene* > m_sceneMap;

};