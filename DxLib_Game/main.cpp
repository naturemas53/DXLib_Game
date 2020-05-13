/**
* @file  main.cpp
* @brief �v���O�����G���g���|�C���g�ł�.
* @author licrosea
* @date 20200513
*/

#include <windows.h>
#include "DxLib.h"
#include "source/singleton/CSingleton.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode( true ); // �E�B���h�E���[�h�ɐݒ�.
	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	WaitKey();				// �L�[���͑҂�

	CSingletonFinalizer::Finalize(); // �V���O���g���I������.

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
