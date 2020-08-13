#pragma once
/**
* @file  CSingleton.h
* @brief シングルトン定義.
* @author licrosea
* @date 20200513
* @details 当ファイルのクラスに関しては、次のURLを参考にしたものとなります（というかパクってます...）.
*          https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
*/

#include <cassert>
#include <mutex>

/**
* @class CSingletonFinalizer
* @brief シングルトンの破棄を担当します.
*/
class CSingletonFinalizer {
private:
    // 生成やコピーは行われない.
    CSingletonFinalizer();
    CSingletonFinalizer( CSingletonFinalizer& );
public:
    using FinalizerFunc = void(*)();
    /// 終了処理を追加します.
    static void AddFinalizer(FinalizerFunc func);
    /// 終了処理を行います.
    static void Finalize();
};

/**
* @class CSingleton
* @brief シングルトンのテンプレートクラスです　こちらを使うとシングルトン化することが可能です.
*/
template <typename T>
class CSingleton final {

public:
    /// インスタンスを取得します.
    static T* GetInstance() 
    {
        std::call_once(sm_initFlag, CSingleton<T>::Create);
        assert(sm_instance);
        return sm_instance;
    }

private:
    /// インスタンスを生成します.
    static void Create()
    {
        sm_instance = new T();
        CSingletonFinalizer::AddFinalizer(&CSingleton<T>::Destroy);
    }

    /// インスタンスを破棄します.
    static void Destroy()
    {
        delete sm_instance;
        sm_instance = nullptr;
    }

    static std::once_flag sm_initFlag; /// call_onceの呼び出し制限に使います.
    static T* sm_instance;             /// インスタンスのポインタです.
};

template <typename T> std::once_flag CSingleton<T>::sm_initFlag; 
template <typename T> T* CSingleton<T>::sm_instance = nullptr;  