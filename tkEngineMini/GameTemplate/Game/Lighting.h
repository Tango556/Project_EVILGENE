#pragma once
#include "stdafx.h"
#include <math.h>


struct DirectionLight
{
	Vector3 ligDirection;
	float pad0;
	Vector3 DirColor;
	float pad1;
	Vector3 eyePos;
	/// <summary>
	/// �f�B���N�V�����Z�b�^�[
	/// </summary>
	/// <param name="Dir"></param>
	inline void SetDirection(const Vector3 Dir)
	{
		ligDirection = Dir;
	}

	/// <summary>
	/// �J���[�Z�b�^�[
	/// </summary>
	/// <param name="Cor">�J���[</param>
	inline void SetColor(const Vector3 Cor)
	{
		DirColor = Cor;
	}
};

class Lighting : public IGameObject
{

};