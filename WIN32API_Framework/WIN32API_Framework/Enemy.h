#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//** �ζ��� �Լ�
	virtual GameObject* Clone()override
	{
		return new Enemy(*this);
		// �⺻ ���� ������ ��
		// �� �ڽ��� �����ϴ� ���� �����ڰ� �ִ�.
		// ��ó�� �ϸ� �� �ڽ��� �����ϴ� ���� �����ڰ� �������
	}
public:
	Enemy();
	Enemy(Transform _transform) : GameObject(_transform) {};
	virtual ~Enemy();
};

