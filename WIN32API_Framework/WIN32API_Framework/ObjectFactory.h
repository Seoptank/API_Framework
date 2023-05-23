#pragma once
#include "Player.h"
#include "Enemy.h"

template <typename T> // => 제대로 쓰지 않을거면 쓰지 말아야 하기에 깊게 공부

//ObjectPool패턴 하기 전에 전 작업
class ObjectFactory
{
	// 사용할 수 있다라는거지 사용할것은 아님
	// ex)비행기 게임 보스가 생성하는 총알
	//    횟수가 다른 오브젝트에 비해 빈번한 생성률을 가질때
	//    효율적인 생성을 위해 Prototype 패턴을 사용한다.
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
	* 아래처럼 사용하면 오브젝트의 수가 많을경우 비효율적
	//============================================
	// Player↓
	//============================================

	static GameObject* CreatePlayer()
	{
		GameObject* Obj = new Player();
		Obj->Start();

		return Obj;
	}

	//백터를 이용한 시작위치 선정
	static GameObject* CreatePlayer(float _x,float _y)
	{
		GameObject* Obj = new Player();
		Obj->Start();
		Obj->SetPosition(Vector3(_x,_y));

		return Obj;
	}

	//백터를 이용한 위치 초기화
	static GameObject* CreatePlayer(Vector3 _position)
	{
		GameObject* Obj = new Player();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}


	//============================================
	// Enemy↓
	//============================================

	static GameObject* CreateEnemy()
	{
		GameObject* Obj = new Enemy();
		Obj->Start();

		return Obj;
	}

	//백터를 이용한 시작위치 선정
	static GameObject* CreateEnemy(float _x, float _y)
	{
		GameObject* Obj = new Enemy();
		Obj->Start();
		Obj->SetPosition(Vector3(_x, _y));

		return Obj;
	}

	//백터를 이용한 위치 초기화
	static GameObject* CreateEnemy(Vector3 _position)
	{
		GameObject* Obj = new Enemy();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}
	*/

	//오버로딩: 같은 함수이름을 쓰면서 매개변수의 갯수나 형태에 따라서 
	//          실행되는 함수가 달라지는 것

};
