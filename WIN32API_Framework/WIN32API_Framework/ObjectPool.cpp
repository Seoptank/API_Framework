#include "ObjectPool.h"
#include "GameObject.h"

ObjectPool::ObjectPool()
{
}
ObjectPool::~ObjectPool()
{
}
void ObjectPool::ReturnObject(GameObject* _object)
{
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_object->GetKey());

	if (iter == PoolList.end())
	{
		// ** map�� ���Խ�ų list�� ��������...
		list<GameObject*> tempList;

		// ** ����Ʈ�� ������Ʈ�� �߰�.
		tempList.push_back(_object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �߰�.
		PoolList.insert(make_pair(_object->GetKey(), tempList));
	}
	// ** �̹� Ű�� ���� �Ѵٸ�....
	else
		// ** �ش� ����Ʈ�� ������Ʈ�� �߰�.
		iter->second.push_back(_object);
}


// Enemy�� �ҷ��� �浹 �Ǿ����� �浹�� Ȯ���ϰ� 
// �ҷ��� �ڱ� ��Ʈ����
// ���� ������Ʈ �Լ� ȣ��
// PoolList�� �߰��� �� �ְԲ�
