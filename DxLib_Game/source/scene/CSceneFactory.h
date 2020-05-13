#pragma once
/**
* @file  CSceneFactory.h
* @brief �V�[���t�@�N�g����`.
* @author licrosea
* @date 20200513
*/

#include <map>

class IScene;
template < class T >
class CSingleton;

/**
* @class CSceneFactory
* @brief �V�[���̐������s���܂�.
*/
class CSceneFactory final
{
	// �V���O���g���N���X�ɐ������������߁A���L�N���X���t�����h�Ƃ��Ă��܂�.
	friend CSingleton<CSceneFactory>;

private:
	// �R�s�[�A�����͋֎~�Ƃ��܂�.
	CSceneFactory();
	CSceneFactory( CSceneFactory& );

public:
	// ���̃N���X�͌p������邱�Ƃ��Ȃ����߁A���z�f�X�g���N�^�ɂ��܂���.
	~CSceneFactory();

	/**
	* @enum  EScene
	* @brief �C���X�^���X���擾����ۂɎg�p���܂�.
	*        ...�߂�ǂ�������������܂��񂪁A�V�K�V�[�����쐬�����ۂ�.
	*        ������ɐV��`��ǉ����A���̌�.
	*        CreateScene�ɐ����������L�q���ĉ������B(�������@���v�����Ȃ�������ł�...).
	*/
	enum class EScene
	{
		ESCENE_NUM // �V�[�������@�ʏ�͎g��Ȃ��@�͂�...
	};

	/// �V�[���̎擾���s���܂�.
	IScene* GetScene( EScene i_scene );

private:

	/// �V�[���̐������s���܂�.
	IScene* CreateScene( EScene i_scene );

	using MapSceneItr  = std::map< EScene, IScene* >::iterator;
	using MapScenePair = std::pair< EScene, IScene* >;

	std::map< EScene, IScene* > m_sceneMap;

};