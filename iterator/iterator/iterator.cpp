﻿#include <iostream>
#include <list>
#include <map>

using namespace std;

//** iterator = 반복자("위치 지정자","참조자"가 더 맞는 표현) 
//            = pointer -> 주소를 가리킴
//            = 위치를 가리키는 화살표와 같다.

int main(void)
{
	list<int> Numbers;
	Numbers.push_back(100);
	Numbers.push_back(200);

	Numbers.begin(); // 첫번째 노드를 가리키는 반복자
	Numbers.end();   // 마지막 노드를 가리키는 반복자

	Numbers.insert(Numbers.begin(), 50);
	Numbers.insert(Numbers.end(), 300);

	list<int>::iterator iter = Numbers.begin();

	Numbers.insert(iter, 25);

	++iter;
	++iter;
	++iter;

	Numbers.insert(iter, 250);

	for (list<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
		cout << (*iter) << endl;


	//=========================================================================
	cout << "=========================================================================" << endl;
	//=========================================================================


	map<string, int> List;

	List["AAA"] = 10;
	List["BBB"] = 20;
	List["CCC"] = 30;

	/*
	for (int i = 0; i < List.size(); ++i)
		cout << List[i] << endl;
	*/
	for (map<string, int>::iterator iter = List.begin(); iter != List.end(); ++iter)
		cout << iter->first << ":" << (*iter).second << endl;

	//=========================================================================
	cout << "=========================================================================" << endl;
	//=========================================================================


	const int size = 16;

	int Array[size] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	
	for (int i = 0; i < size; ++i)
		cout << Array[i] << endl;
	
	{
		cout << (*iter) << endl;
	}

	//=========================================================================
	cout << "=========================================================================" << endl;
	//=========================================================================

	{
		int* iter = Array;
		cout << (*iter) << endl;
		cout << *(++iter) << endl;
		cout << *(iter+5) << endl;
		cout << *(iter) << endl;
	}


	return 0;
}