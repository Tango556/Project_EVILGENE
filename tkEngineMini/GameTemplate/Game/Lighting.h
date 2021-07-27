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
	/// ディレクションセッター
	/// </summary>
	/// <param name="Dir"></param>
	inline void SetDirection(const Vector3 Dir)
	{
		ligDirection = Dir;
	}

	/// <summary>
	/// カラーセッター
	/// </summary>
	/// <param name="Cor">カラー</param>
	inline void SetColor(const Vector3 Cor)
	{
		DirColor = Cor;
	}
};

class Lighting : public IGameObject
{

};