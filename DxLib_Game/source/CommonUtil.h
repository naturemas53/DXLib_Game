#pragma once
#include <Windows.h>
/**
* @file   CommonUtil.h
* @brief  ���ʂŎg����֗��Ȓ�`�Ƃ��������Ă���@����ł�.
* @author licrosea
* @date 20200513
*/

/**
* @struct Vector2
* @brief  2�����x�N�g���̍\���̂ł�.
*         �x�N�g���Ƃ��Ă̎g�p�ɂ͂������̂��ƁA�T�C�Y��ʒu�w��ɂ��ǂ���.
*/
struct Vector2
{
	float x;
	float y;

	// �R���X�g���N�^.
	Vector2() : x( 0 ), y( 0 )
	{}
	Vector2( float i_x, float i_y ) : x( i_x ), y( i_y )
	{}

	// ���Z�q�I�[�o�[���[�h.
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
* @brief ���d�J���i��NULL��Ԃł̉���j��h������֐��ł�.
* @param[in] obj �������I�u�W�F�N�g�����Ă�������.
*/
template <class T> inline void safeDelete(T** i_obj) {
	if( (*i_obj) == nullptr ) return;
	if( (*i_obj) == NULL    ) return; // �ꉞ�������̌`�����`�F�b�N.

	delete (*i_obj);
	(*i_obj) = nullptr;
}