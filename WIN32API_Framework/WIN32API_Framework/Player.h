#pragma once
#include "GameObject.h"

class Player : public GameObject
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
		return new Player(*this);
		// �⺻ ���� ������ ��
		// �� �ڽ��� �����ϴ� ���� �����ڰ� �ִ�.
		// ��ó�� �ϸ� �� �ڽ��� �����ϴ� ���� �����ڰ� �������
	}
public:
	GameObject* CreateBullet();
public:
	Player();
	//�������� �ʱ�ȭ������ class���ο� �ִ� ��ҵ�θ� �ʱ�ȭ ����
	// ���� �����ڸ� ���� ����ȭ
	Player(Transform _transform) : GameObject(_transform) {};
	virtual ~Player();
};

