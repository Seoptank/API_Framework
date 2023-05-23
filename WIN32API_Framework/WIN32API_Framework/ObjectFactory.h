#pragma once
#include "Player.h"
#include "Enemy.h"

template <typename T> // => ����� ���� �����Ÿ� ���� ���ƾ� �ϱ⿡ ��� ����

//ObjectPool���� �ϱ� ���� �� �۾�
class ObjectFactory
{
	// ����� �� �ִٶ�°��� ����Ұ��� �ƴ�
	// ex)����� ���� ������ �����ϴ� �Ѿ�
	//    Ƚ���� �ٸ� ������Ʈ�� ���� ����� �������� ������
	//    ȿ������ ������ ���� Prototype ������ ����Ѵ�.
public:

	static GameObject* CreateObject()
	{
		GameObject* Obj = new T();
		Obj->Start();

		return Obj;
	}

	static GameObject* CreateObject(const float& _x, const float& _y)
	{
		GameObject* Obj = new T();
		Obj->Start();
		Obj->SetPosition(Vector3(_x, _y));

		return Obj;
	}

	static GameObject* CreateObject(const Vector3& _position)
	{
		GameObject* Obj = new T();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}

	/*
	* �Ʒ�ó�� ����ϸ� ������Ʈ�� ���� ������� ��ȿ����
	//============================================
	// Player��
	//============================================

	static GameObject* CreatePlayer()
	{
		GameObject* Obj = new Player();
		Obj->Start();

		return Obj;
	}

	//���͸� �̿��� ������ġ ����
	static GameObject* CreatePlayer(float _x,float _y)
	{
		GameObject* Obj = new Player();
		Obj->Start();
		Obj->SetPosition(Vector3(_x,_y));

		return Obj;
	}

	//���͸� �̿��� ��ġ �ʱ�ȭ
	static GameObject* CreatePlayer(Vector3 _position)
	{
		GameObject* Obj = new Player();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}


	//============================================
	// Enemy��
	//============================================

	static GameObject* CreateEnemy()
	{
		GameObject* Obj = new Enemy();
		Obj->Start();

		return Obj;
	}

	//���͸� �̿��� ������ġ ����
	static GameObject* CreateEnemy(float _x, float _y)
	{
		GameObject* Obj = new Enemy();
		Obj->Start();
		Obj->SetPosition(Vector3(_x, _y));

		return Obj;
	}

	//���͸� �̿��� ��ġ �ʱ�ȭ
	static GameObject* CreateEnemy(Vector3 _position)
	{
		GameObject* Obj = new Enemy();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}
	*/

	//�����ε�: ���� �Լ��̸��� ���鼭 �Ű������� ������ ���¿� ���� 
	//          ����Ǵ� �Լ��� �޶����� ��

};
