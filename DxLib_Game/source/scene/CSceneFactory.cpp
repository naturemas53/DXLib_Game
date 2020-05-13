/**
* @file  CSceneFactory.cpp
* @brief �V�[���t�@�N�g����`.
* @author licrosea
* @date 20200513
*/

#include "CSceneFactory.h"
#include "IScene.h"
#include "../CommonUtil.h"

CSceneFactory::CSceneFactory()
{
	m_sceneMap.clear();
}

/// �f�X�g���N�^�i�����őS�J�����s���܂��j.
CSceneFactory::~CSceneFactory()
{
	for ( MapScenePair itr : m_sceneMap )
	{
		safeDelete( &( itr.second ) );
	}
	m_sceneMap.clear();
}

/**
* @fn IScene* GetScene( EScene i_scene )
* @brief �V�[�����擾���܂�.
* @param[in] i_scene �擾�������V�[���̒�`��.
* @return ����Ɏ擾�ł���΃C���X�^���X�̃|�C���^���@�ł��Ȃ����false���Ԃ�܂�.
*/
IScene* CSceneFactory::GetScene( EScene i_scene )
{
	MapSceneItr itr = m_sceneMap.find( i_scene );

	// ���łɐ����ς݂ł���΂����Ԃ�.
	if ( itr != m_sceneMap.end() )
	{
		return itr->second;
	}

	// �����܂ŗ����ꍇ�͏��߂Ďw�肳�ꂽ.
	IScene* scene = CreateScene( i_scene );

	// �������萶������Ă���Βǉ�.
	if ( scene != nullptr ) m_sceneMap[ i_scene ] = scene;

	return scene;
}

/**
* @fn IScene* CreateScene( EScene i_scene )
* @brief �V�[���𐶐����܂�.
* @param[in] i_scene �����������V�[���̒�`��.
* @return ����ɐ����ł���΃C���X�^���X�̃|�C���^���@�ł��Ȃ����false���Ԃ�܂�.7
* @details �V�K�V�[���쐬���́A������ɐ����̏������L�q���Ă�������.
*/
IScene* CSceneFactory::CreateScene( EScene i_scene )
{
	IScene* scene = nullptr;
	switch ( i_scene )
	{
	default: break;
	}

	return scene;
}