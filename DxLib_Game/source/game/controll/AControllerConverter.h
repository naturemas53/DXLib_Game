#pragma once
/**
* @file   AControllerConverter.h
* @brief  ゲーム入力への変換の抽象定義です.
* @author licrosea
* @date   20210413
*/
#include <functional>

using namespace std;

class AControllerConverter
{
public:
	/**
	 * @enum RunningStatus
	 * コンバータの稼働状態です.
	 */
	enum class RunningStatus
	{
		STATUS_NONE, // どの状態でもない.
		STATUS_STOP, // 停止中.
		STATUS_RUNNING, // 稼働中.
		STATUS_ASSIGNING, // ボタン変更中.
	};

	/**
	 * @enum AssignedResult
	 * ボタンや軸変更の結果です.
	 */
	enum class AssignedResult
	{
		ASSIGN_NONE,    // いずれでもない.
		ASSIGN_SUCCESS, // 成功.
		ASSIGN_ABORT,   // 中止.
		ASSIGN_ERROR_UNKNOWN // 不明なエラー.
	};

	/// <summary>
	/// 割り当て終了時のコールバックです.
	/// </summary>
	using OnEndedAssignCallBack = function<AssignedResult>;

protected:
	// 直接生成は禁止.
	AControllerConverter() : m_runningStatus( RunningStatus::STATUS_NONE )
							,m_assignResult ( AssignedResult::ASSIGN_NONE ){}

public:
	virtual ~AControllerConverter() {};

	/**
	* @fn bool Initialize()
	* @brief  初期化を行います.
	* @return 成功でtrue 失敗でfalseを返します.
	*/
	virtual bool Initialize() = 0;
	/**
	* @fn bool Finalize()
	* @brief  終了処理を行います.
	* @return 特になし　void.
	*/
	virtual void Finalize() = 0;
	/**
	* @fn bool Update()
	* @brief  入力情報を更新します.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	virtual bool Update() = 0;

	/**
	* @fn bool BeginChangeAssignButton()
	* @brief   ボタン割り当ての変更を開始します.
	* @param[in] i_callback 割り当て終了時に呼ばれるコールバックです.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	virtual bool BeginChangeAssignButton(OnEndedAssignCallBack i_callback = nullptr) = 0;
	/**
	* @fn bool BeginChangeAssignAxis()
	* @brief   軸割り当ての変更を開始します.
	* @param[in] i_callback 割り当て終了時に呼ばれるコールバックです.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	virtual bool BeginChangeAssignAxis(OnEndedAssignCallBack i_callback = nullptr) = 0;
	/**
	* @fn bool BeginChangeAssignAxis()
	* @brief   軸割り当ての変更を開始します.
	* @return 特に問題無ければtrue 問題が発生するとfalseを返します.
	*/
	virtual bool AbortChangeAssign() = 0;
	/**
	* @fn bool SetAssignedCallBack()
	* @brief   割り当て終了(また中断時)時のコールバックを設定します.
	* @param[in] i_callback 割り当て終了時に呼ばれるコールバックです.
	*/
	virtual void SetAssignedCallBack(OnEndedAssignCallBack i_callback) = 0;

	/**
	* @fn bool GetCurrentRunningStatus()
	* @brief   現在の稼働状態をRunningStatusで返します.
	* @return  説明と同上.
	*/
	RunningStatus GetCurrentRunningStatus() { return m_runningStatus; }
	/**
	* @fn bool GetAssignedResult()
	* @brief   割り当ての結果をAssignedResultで返します.
	* @return  説明と同上.
	*/
	AssignedResult GetAssignedResult() { return m_assignResult; }

protected:

	RunningStatus  m_runningStatus; // 稼働中の状態.
	AssignedResult m_assignResult;  // 割り当て結果.

};