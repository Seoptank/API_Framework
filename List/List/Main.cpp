#include <iostream>

using namespace std;

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;


NODE* List;


void Push(int value);


int main(void)
{
	// ** ù��° ���
	// create
	List = new NODE; 

	// initialize
	List->next = nullptr;
	List->value = 0;

	//===========================================
	// ** �ι�° ���
	// create
	List->next = new NODE;

	// initialize
	List->next->next = nullptr;
	List->next->value = 10;
	
	//===========================================
	// ** ����° ���
	// create
	List->next->next = new NODE;

	// initialize
	List->next->next->next = nullptr;
	List->next->next->value = 20;

	//===========================================
	// ** �׹�° ���
	// create
	List->next->next->next = new NODE;

	// initialize
	List->next->next->next->next = nullptr;
	List->next->next->next->value = 30;



	// ** �ι�° ��带 nextNode �� �Ѱ��ش�.
	NODE* nextNode = List->next;


	// ** nextNode�� nullptr�� �ƴ϶�� �ݺ�.
	while (nextNode != nullptr)
	{
		// ** ���
		cout << nextNode->value << endl;

		// ** �������� �̵�
		nextNode = nextNode->next;
	}
	

	return 0;
}

void Push(int value)
{
	NODE* nextNode = List;

	while (nextNode)
		nextNode = nextNode->next;

	nextNode = new NODE;

	nextNode->value = value;
	nextNode->next = nullptr;
}
