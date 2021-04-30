#pragma once

/**
* @file   IControllerInput.h
* @brief  物理入力系のインターフェイスです.
* @author licrosea
* @date   20210413
*/

/// <summary>
/// 思ったけどこのクラス、いらないかもしれない...
/// (まぁメモとして残します).
/// </summary>

class IControllerInput
{

protected:
	//　直接生成の生成禁止.
	IControllerInput();

public:
	// おまじない（ﾊｧﾄ）.
	// 厳密には、デストラクタを確実に実行させるためのそれ.
	virtual ~IControllerInput();

	/**
	* @fn bool Initialize()
	* @brief  初期化を行います.
	* @return 成功でtrue 失敗でfalseを返します.
	*/
	virtual bool Initialize() = 0;
	/**
	* @fn void Finalize()
	* @brief  終了処理を行います.
	* @return 特になし　void.
	*/
	virtual void Finalize()   = 0;
	/**
	* @fn bool Update()
	* @brief  入力情報を更新します.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	virtual bool Update()     = 0;

	/**
	* @fn bool IsKeyDown()
	* @brief  指定したキーが押下されているか取得します.
	* @param[in] i_checkKey 確認するキーを指定してください（適当にintに変換してもろて）.
	* @return 押下されていればtrue されていなければfalseが帰ります.
	*/
	virtual bool IsKeyDown   (int i_checkKey) = 0;
	/**
	* @fn int GetKeyNum()
	* @brief  取得できるキーの数を返します.
	* @return 説明と同様です.
	*/
	virtual int GetKeyNum() = 0;
	/**
	* @fn float GetAxisValue()
	* @brief  コントローラーから取得できる軸を0.0～1.0fの間で取得します.
	* @param[in] i_axisIdx 取得する軸（範囲外参照した時は...　その時次第？）.
	* @return 入力されている軸の値です.
	*/
	virtual float  GetAxisValue(int i_axisIdx)  = 0;
	/**
	* @fn int GetAxisNum()
	* @brief  コントローラーから取得できる軸の数を取得します.
	* @return 説明と同様です.
	*/
	virtual int  GetAxisNum() = 0;

};