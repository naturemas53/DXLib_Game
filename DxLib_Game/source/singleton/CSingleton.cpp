/**
* @file  CSingleton.cpp
* @brief シングルトン実装.
* @author licrosea
* @date 20200513
* @details 当ファイルのクラスに関しては、次のURLを参考にしたものとなります（というかパクってます...）.
*          https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc
*/
#include "CSingleton.h"

namespace
{

    constexpr int K_MAX_FINALIZER_SIZE = 256; // constexprも定数の一種ですが、計算式なども定数にできるらしいです　リテラル型になるらしい.
    std::mutex gMutex; // 排他処理... スレッド間でのデータやり取りで不都合が起きないようにするための管理変数です.
    int gNumFinalizersSize = 0; // 現状いくつ登録されているか.
    CSingletonFinalizer::FinalizerFunc gFinalizers[K_MAX_FINALIZER_SIZE] = {}; // 終了処理のリスト.

}

void CSingletonFinalizer::AddFinalizer(FinalizerFunc func) 
{
    std::lock_guard<std::mutex> lock(gMutex);
    assert(gNumFinalizersSize < K_MAX_FINALIZER_SIZE);

    gFinalizers[gNumFinalizersSize] = func; // 現状の最大値（≒末尾）に設定.
    gNumFinalizersSize++;
}

void CSingletonFinalizer::Finalize() 
{
    std::lock_guard<std::mutex> lock(gMutex);
    // すべての終了処理を行い...
    for (int i = gNumFinalizersSize - 1; i >= 0; --i) {
        (*gFinalizers[i])();
    }
    // リセット.
    gNumFinalizersSize = 0;
}