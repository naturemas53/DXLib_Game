#pragma once
/**
* @file  CSingleton.h
* @brief �V���O���g����`.
* @author licrosea
* @date 20200513
* @details ���t�@�C���̃N���X�Ɋւ��ẮA����URL���Q�l�ɂ������̂ƂȂ�܂��i�Ƃ������p�N���Ă܂�...�j.
*          https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
*/

#include <cassert>
#include <mutex>

/**
* @class CSingletonFinalizer
* @brief �V���O���g���̔j����S�����܂�.
*/
class CSingletonFinalizer {
private:
    // ������R�s�[�͍s���Ȃ�.
    CSingletonFinalizer();
    CSingletonFinalizer( CSingletonFinalizer& );
public:
    using FinalizerFunc = void(*)();
    /// �I��������ǉ����܂�.
    static void AddFinalizer(FinalizerFunc func);
    /// �I���������s���܂�.
    static void Finalize();
};

/**
* @class CSingleton
* @brief �V���O���g���̃e���v���[�g�N���X�ł��@��������g���ƃV���O���g�������邱�Ƃ��\�ł�.
*/
template <typename T>
class CSingleton final {

public:
    /// �C���X�^���X���擾���܂�.
    static T& GetInstance() 
    {
        std::call_once(sm_initFlag, CSingleton<T>::Create);
        assert(sm_instance);
        return *sm_instance;
    }

private:
    /// �C���X�^���X�𐶐����܂�.
    static void Create()
    {
        sm_instance = new T();
        CSingletonFinalizer::AddFinalizer(&CSingleton<T>::Destroy);
    }

    /// �C���X�^���X��j�����܂�.
    static void Destroy()
    {
        delete sm_instance;
        sm_instance = nullptr;
    }

    static std::once_flag sm_initFlag; /// call_once�̌Ăяo�������Ɏg���܂�.
    static T* sm_instance;             /// �C���X�^���X�̃|�C���^�ł�.
};

template <typename T> std::once_flag CSingleton<T>::sm_initFlag; 
template <typename T> T* CSingleton<T>::sm_instance = nullptr;  