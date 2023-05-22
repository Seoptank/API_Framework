#include "Prototype.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"



Prototype::Prototype()
{

}
Prototype::~Prototype()
{

}


//** 상수
//   1. 리터럴 상수
//   1. 심볼릭 상수 ->전체 대문자 표기

void Prototype::Start()
{
	Transform transform;

	transform.position = Vector3(0.f, 0.f, 0.f);
	transform.direction = Vector3(0.f, 0.f, 0.f);
	transform.scale = Vector3(0.f, 0.f, 0.f);
	
	//오브젝트 생성을 위한 객체화
	string key = "Player";
	PrototypeObject.insert(make_pair(key,(new Player(transform))->Start()->SetKey(key)));

	key = "Enemy";
	PrototypeObject.insert(make_pair(key, (new Enemy(transform))->Start()->SetKey(key)));

	key = "Bullet";
	PrototypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));
	// SetKey 사용해서 key 바꾸게 되면 위험한 상황이 발생할 수 있기때문에
	// 나중에 바꾸자
	

}

GameObject* Prototype::GetGameObject(string _key)
{
	map<string, GameObject*>::iterator iter = PrototypeObject.find(_key);

	if (iter == PrototypeObject.end())
		return nullptr;
	else
		return iter->second;
}

