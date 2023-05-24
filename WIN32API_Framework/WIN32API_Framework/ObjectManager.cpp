#include "ObjectManager.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "ObjectPool.h"

ObjectManager* ObjectManager::Instance = nullptr;


ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}


void ObjectManager::AddObject(GameObject* _Object)
{
	// ** 파라메터가 가르키고있는 키 값이 현재 map에 포함되어있는지 확인.
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// ** 만약 키가 없다면....
	if (iter == ObjectList.end())
	{
		// ** map에 포함시킬 list를 생성한후...
		list<GameObject*> tempList;

		// ** 리스트에 오브젝트를 추가.
		tempList.push_back(_Object);

		// ** 오브젝트가 추가된 리스트를 map에 추가.
		ObjectList.insert(make_pair(_Object->GetKey(), tempList));
	}
	// ** 이미 키가 존재 한다면....
	else 
		// ** 해당 리스트에 오브젝트를 추가.
		iter->second.push_back(_Object);
}


list<GameObject*>* ObjectManager::GetObjectList(const string& key)
{
	// ** 키 값이 현재 map에 포함되어있는지 확인.
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(key);

	// ** 만약 키가 없다면....
	if (iter == ObjectList.end())
		// ** nullptr 을 반환.
		return nullptr;
	// ** 이미 키가 존재 한다면....
	else
		// ** second = value = list<GameObject*> 를 반환.
		return &iter->second;
}



void ObjectManager::Update()
{
	list<GameObject*>* enemyList = &ObjectList.find("Enemy")->second;
	list<GameObject*>* bulletList = &ObjectList.find("Bullet")->second;

	list<GameObject*>::iterator iter1 = enemyList->begin();
	list<GameObject*>::iterator iter2 = bulletList->begin();



	for (; iter1 != enemyList->end(); ++iter1)
	{
		for (; iter2 != bulletList->end(); ++iter2)
		{
			if (GetSingle(CollisionManager)->CircleCollision(*iter2, *iter1))
			{
				(*iter1)->Destroy();
				(*iter2)->Destroy();
			}
			
			

		}
	}


}

void ObjectManager::Render(HDC _hdc)
{
	for (map<string, list<GameObject*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		for (list<GameObject*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render(_hdc);
		}

	}
}