/**
* @file  CSingleton.cpp
* @brief �V���O���g������.
* @author licrosea
* @date 20200513
* @details ���t�@�C���̃N���X�Ɋւ��ẮA����URL���Q�l�ɂ������̂ƂȂ�܂��i�Ƃ������p�N���Ă܂�...�j.
*          https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
*/
#include "CSingleton.h"

namespace
{

    constexpr int K_MAX_FINALIZER_SIZE = 256; // constexpr���萔�̈��ł����A�v�Z���Ȃǂ��萔�ɂł���炵���ł��@���e�����^�ɂȂ�炵��.
    std::mutex gMutex; // �r������... �X���b�h�Ԃł̃f�[�^�����ŕs�s�����N���Ȃ��悤�ɂ��邽�߂̊Ǘ��ϐ��ł�.
    int gNumFinalizersSize = 0; // ���󂢂��o�^����Ă��邩.
    CSingletonFinalizer::FinalizerFunc gFinalizers[K_MAX_FINALIZER_SIZE] = {}; // �I�������̃��X�g.

}

void CSingletonFinalizer::AddFinalizer(FinalizerFunc func) 
{
    std::lock_guard<std::mutex> lock(gMutex);
    assert(gNumFinalizersSize < K_MAX_FINALIZER_SIZE);

    gFinalizers[gNumFinalizersSize] = func; // ����̍ő�l�i�������j�ɐݒ�.
    gNumFinalizersSize++;
}

void CSingletonFinalizer::Finalize() 
{
    std::lock_guard<std::mutex> lock(gMutex);
    // ���ׂĂ̏I���������s��...
    for (int i = gNumFinalizersSize - 1; i >= 0; --i) {
        (*gFinalizers[i])();
    }
    // ���Z�b�g.
    gNumFinalizersSize = 0;
}