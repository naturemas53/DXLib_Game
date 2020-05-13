#pragma once
#include <Windows.h>
/**
* @file   CommonUtil.h
* @brief  共通で使える便利な定義とかを書いている　つもりです.
* @author licrosea
* @date 20200513
*/

/**
* @struct Vector2
* @brief  2次元ベクトルの構造体です.
*         ベクトルとしての使用にはもちろんのこと、サイズや位置指定にもどうぞ.
*/
struct Vector2
{
	float x;
	float y;

	// コンストラクタ.
	Vector2() : x( 0 ), y( 0 )
	{}
	Vector2( float i_x, float i_y ) : x( i_x ), y( i_y )
	{}

	// 演算子オーバーロード.
	Vector2& operator =(const Vector2 i_rhs )
	{
		this->x = i_rhs.x;
		this->y = i_rhs.y;
		return *this;
	}
	Vector2& operator +( const Vector2 i_rhs )
	{
		this->x += i_rhs.x;
		this->y += i_rhs.y;
		return *this;
	}
	Vector2& operator -( const Vector2 i_rhs )
	{
		this->x -= i_rhs.x;
		this->y -= i_rhs.y;
		return *this;
	}
	const bool operator ==( const Vector2 i_rhs )
	{
		return ( this->x == i_rhs.x ) && ( this->y == i_rhs.y );
	}
};

/**
* @fn void safeDelete(T** obj)
* @brief 多重開放（≒NULL状態での解放）を防ぐ解放関数です.
* @param[in] obj 解放するオブジェクトを入れてください.
*/
template <class T> inline void safeDelete(T** i_obj) {
	if( (*i_obj) == nullptr ) return;
	if( (*i_obj) == NULL    ) return; // 一応こっちの形式もチェック.

	delete (*i_obj);
	(*i_obj) = nullptr;
}