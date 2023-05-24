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
	// ** �Ķ���Ͱ� ����Ű���ִ� Ű ���� ���� map�� ���ԵǾ��ִ��� Ȯ��.
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// ** ���� Ű�� ���ٸ�....
	if (iter == ObjectList.end())
	{
		// ** map�� ���Խ�ų list�� ��������...
		list<GameObject*> tempList;

		// ** ����Ʈ�� ������Ʈ�� �߰�.
		tempList.push_back(_Object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �߰�.
		ObjectList.insert(make_pair(_Object->GetKey(), tempList));
	}
	// ** �̹� Ű�� ���� �Ѵٸ�....
	else 
		// ** �ش� ����Ʈ�� ������Ʈ�� �߰�.
		iter->second.push_back(_Object);
}


list<GameObject*>* ObjectManager::GetObjectList(const string& key)
{
	// ** Ű ���� ���� map�� ���ԵǾ��ִ��� Ȯ��.
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(key);

	// ** ���� Ű�� ���ٸ�....
	if (iter == ObjectList.end())
		// ** nullptr �� ��ȯ.
		return nullptr;
	// ** �̹� Ű�� ���� �Ѵٸ�....
	else
		// ** second = value = list<GameObject*> �� ��ȯ.
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