/**
* @file  CGameController.h
* @brief ゲーム入力定義.
* @author licrosea
* @date 20210413
*/
#pragma once
#include <map>

using namespace std;

class AControllConverter;

/// <summary>
/// 複製はいいけど、継承はちげえ.
/// </summary>
class CGameController final
{
public:
	/**
	 * @enum ButtonType
	 * 攻撃やキャンセルなど、ゲーム中で使うボタンを定義します.
	 */
	enum class ButtonType
	{
		BUTTON_NONE = 0,

		BUTTON_OK,
		BUTTON_CANCEL,

		BUTTON_NUM
	};

	/**
	 * @enum AxisType
	 * 移動やカメラなど、ゲーム中で使う軸を定義します.
	 */
	enum class AxisType
	{
		AXIS_NONE = 0,

		AXIS_MOVE_X,
		AXIS_MOVE_Y,

		AXIS_NUM
	};

private:

	/**
	 * @struct ButtonData
	 * 各ボタンの押下状況を格納した構造体です.
	 */
	struct ButtonData
	{
		bool isDown    = false;
		bool isPress   = false;
		bool isRelease = false;

		ButtonData() :isDown(false),
			         isPress(false),
			       isRelease(false){}
	};

private:
	// ポインタはともかく、コピーはないかなぁ...
	CGameController(CGameController&) {};
	// コンバータは必須とします.
	CGameController() {};

public:
	CGameController(AControllConverter* i_converter);

	/**
	* @fn bool Initialize()
	* @brief  初期化を行います.
	* @return 成功でtrue 失敗でfalseを返します.
	*/
	bool Initialize();
	/**
	* @fn bool Finalize()
	* @brief  終了処理を行います.
	* @return 特になし　void.
	*/
	void Finalize();
	/**
	* @fn bool Update()
	* @brief  入力情報を更新します.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	bool Update();

	/**
	* @fn bool IsDownButton()
	* @brief  ボタンが押されているか取得します.
	* @param[in] i_buttonType 確認するボタン.
	* @return 押されていればtrue 押されてなければfalse.
	*/
	bool IsDownButton(ButtonType i_buttonType);
	/**
	* @fn bool IsPressButton()
	* @brief  ボタンが押下した瞬間か取得します.
	* @param[in] i_buttonType 確認するボタン.
	* @return 押下した瞬間ならtrue それ以外はfalse.
	*/
	bool IsPressButton(ButtonType i_buttonType);
	/**
	* @fn bool IsUoButton()
	* @brief  ボタンが押されていないか取得します.
	* @param[in] i_buttonType 確認するボタン.
	* @return 押されていなければtrue 押されていればfalse.
	*/
	bool IsUpButton(ButtonType i_buttonType);
	/**
	* @fn bool IsReleaseButton()
	* @brief  ボタンが離された瞬間か取得します.
	* @param[in] i_buttonType 確認するボタン.
	* @return 離された瞬間ならtrue それ以外はfalse.
	*/
	bool IsReleaseButton(ButtonType i_buttonType);

	//bool IsRepeatButton();
	//void SetEnableRepeatButton();
	//void SetRepeatOption();

	/**
	* @fn float GetAxisValue()
	* @brief  軸の値を取得します.
	* @param[in] i_axisType 確認する軸.
	* @return 説明と同上です.
	*/
	float GetAxisValue(AxisType i_axisType);

	/**
	* @fn void ChangeConverter()
	* @brief  コンバーター（実質入力）を取り替えます.
	* @param[in] i_converter 取り替えるコンバータ.
	*/
	void ChangeConverter(AControllConverter* i_converter);

private:

	AControllConverter* m_converter;

	map<ButtonType, ButtonData> m_buttonDataMap;
	map<AxisType, float>        m_axisValueMap;

	// ここはクラス化かも.
	//RepeatType m_repeatType;
	//int        m_repeatFrame;
	//float      m_repeatTime;
	//int		   m_elapsedFrame;
	//float      m_elapsedTime;

};