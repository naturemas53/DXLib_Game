/**
* @file  CSceneOwner.cpp
* @brief �V�[���I�[�i�[����.
* @author licrosea
* @date 20200513
*/

#include "CSceneOwner.h"
#include "../common_util.h"

CSceneOwner::CSceneOwner() : m_currentScene( nullptr ), m_funcErrorPut( nullptr )
{
}

CSceneOwner::~CSceneOwner()
{
	m_currentScene = nullptr;
	m_funcErrorPut = nullptr;
}

/**
* @fn bool Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut )
* @brief �V�[�����J�n���܂�.
* @param[in] i_firstScene �ǂ̃V�[������n�߂邩.
* @param[in] i_funcErrorPut �G���[�o�͎��̊֐�.
* @return ����ɊJ�n�ł����true �ł��Ȃ����false��Ԃ��܂�.
*/
bool CSceneOwner::Start( IScene* i_firstScene, FuncErrorPut i_funcErrorPut )
{
	m_currentScene = i_firstScene;
	m_funcErrorPut = i_funcErrorPut;

	return this->ChangeScene( i_firstScene );
}

/**
* @fn void End()
* @brief �V�[�����I�����܂�.
*/
void CSceneOwner::End()
{
	m_currentScene->Finalize();
}

/**
* @fn bool Update()
* @brief �V�[�����X�V���܂�.
* @return ����ғ�����true ��蔭����false��Ԃ��܂�.
*/
bool CSceneOwner::Update()
{
	m_currentScene->Draw();

	IScene* nextScene = m_currentScene->Update();

	// ���}���A�V�[���J�ڂ��Ȃ���΃Z�[�t�Ƃ��܂�.
	if ( nextScene == nullptr ) return true;

	return this->ChangeScene( nextScene );
}

/**
* @fn bool ChangeScene( IScene* i_nextScene )
* @brief ���̃V�[�����J�n���܂�.
* @param[in] i_nextScene ���ɊJ�n����V�[��.
* @return ����ɊJ�n�ł����true �ł��Ȃ����false��Ԃ��܂�.
*/
bool CSceneOwner::ChangeScene( IScene* i_nextScene )
{
	if( m_currentScene != nullptr ) m_currentScene->Finalize();

	m_currentScene = i_nextScene;

	if ( !m_currentScene->Initalize( m_funcErrorPut ) )
	{
		// �O�̂��߁A�I���������s��.
		m_currentScene->Finalize();
		return false;
	}

	return true;
}