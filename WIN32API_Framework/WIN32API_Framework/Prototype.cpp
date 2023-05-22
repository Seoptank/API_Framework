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


//** ���
//   1. ���ͷ� ���
//   1. �ɺ��� ��� ->��ü �빮�� ǥ��

void Prototype::Start()
{
	Transform transform;

	transform.position = Vector3(0.f, 0.f, 0.f);
	transform.direction = Vector3(0.f, 0.f, 0.f);
	transform.scale = Vector3(0.f, 0.f, 0.f);
	
	//������Ʈ ������ ���� ��üȭ
	string key = "Player";
	PrototypeObject.insert(make_pair(key,(new Player(transform))->Start()->SetKey(key)));

	key = "Enemy";
	PrototypeObject.insert(make_pair(key, (new Enemy(transform))->Start()->SetKey(key)));

	key = "Bullet";
	PrototypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));
	// SetKey ����ؼ� key �ٲٰ� �Ǹ� ������ ��Ȳ�� �߻��� �� �ֱ⶧����
	// ���߿� �ٲ���
	

}

GameObject* Prototype::GetGameObject(string _key)
{
	map<string, GameObject*>::iterator iter = PrototypeObject.find(_key);

	if (iter == PrototypeObject.end())
		return nullptr;
	else
		return iter->second;
}

