#pragma once
/**
* @file  CSceneOwner.h
* @brief �V�[���I�[�i�[��`.
* @author licrosea
* @date 20200513
*/

#include "IScene.h"

/**
* @class CSceneOwner
* @brief �V�[���I�[�i�[�ł��i�V�[���̐e�̂悤�ȗ����ʒu�ł��j.
*/
class CSceneOwner final
{
private:

	// ���̃N���X���R�s�[���邱�Ƃ͂Ȃ��@�͂�.
	CSceneOwner( CSceneOwner& );

public:

	CSceneOwner();

	// ���̃N���X�͌p������邱�Ƃ��Ȃ����߁A���z�f�X�g���N�^�ɂ��܂���.
	~CSceneOwner();

	/// �V�[�����n�߂܂�.
	bool Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut = nullptr );

	/// �V�[�����I�����܂�.
	void End();

	/// �X�V���s���܂�.
	bool Update();

private:

	/// �V�[���ύX���s���܂�.
	bool ChangeScene( IScene* i_nextScene );

	IScene* m_currentScene; // ���݂̃V�[���ł�.
	FuncErrorPut m_funcErrorPut; // �G���[�o�͂̊֐��ł�.
};