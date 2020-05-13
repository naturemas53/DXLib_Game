#pragma once
/**
* @file  IScene.h
* @brief �V�[���C���^�[�t�F�C�X��`.
* @author licrosea
* @date 20200513
*/
#include <functional>
#include <string>

/// �G���[�o�͊֐��̒�`.
using FuncErrorPut = std::function< void( std::string errorStr ) >;

/**
* @interface IScene
* @brief �V�[���̃C���^�[�t�F�C�X�ł�.
*/
class IScene
{
private:
	IScene() {}; // �C���^�[�t�F�C�X�Ȃ̂Ő����֎~.
	IScene( const IScene& ) {} // �����R�s�[���邱�Ƃ��Ȃ��@�͂�.

public:

	virtual ~IScene() {}; // �O�̂��߃f�X�g���N�^�͏����Ƃ��@���Ă������OK�ɂ��Ȃ��Ɖ���ł��Ȃ��C��.

	/**
	* @fn bool Initalize( FuncErrorPut i_funcErrorPut )
	* @brief �V�[���̏��������s���܂�.
	* @param[in] i_funcErrorPut �G���[���b�Z�[�W�̏o�͂��s���֐����w�肵�Ă�������.
	* @return ������������true ���s��false��Ԃ��܂�.
	*/
	virtual bool Initalize( FuncErrorPut i_funcErrorPut = nullptr ) = 0;

	/**
	* @fn void Finalize()
	* @brief �V�[���̏I���������s���܂�.
	*/
	virtual void Finalize() = 0;

	/**
	* @fn IScene* Update()
	* @brief �V�[���̍X�V���s���܂�.
	* @return �ʃV�[���ɑJ�ڂ���ꍇ�̓C���X�^���X�̃|�C���^�� ����ȊO��nullptr��Ԃ��܂�.
	*/
	virtual IScene* Update() = 0;

	/**
	* @fn bool Draw()
	* @brief �V�[���̕`����s���܂�.
	* @return �`�搬����true ����ȊO��false��Ԃ��܂�.
	*/
	virtual bool Draw() = 0;
};