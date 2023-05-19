#include <iostream>
#include <map>
#include <list>

using namespace std;


typedef struct tagScore
{
	string Name;

	int Kor;
	int Eng;
	int Math;

	//** �����ڡ�: �����ڴ� �����ϰ��� �Ҷ��� ������ �����ž���.
	tagScore():Name(""), Kor(0), Eng(0), Math(0) {}

	//** ��������ڡ�

	tagScore(string _name) :
		Name(_name), Kor(0), Eng(0), Math(0) {}

	tagScore(int _kor, int _eng, int _math) :
		Name(""), Kor(_kor), Eng(_eng), Math(_math) {}
	
	tagScore(string _name, int _kor, int _eng, int _math) :
		Name(_name),Kor(_kor), Eng(_eng), Math(_math) {}

	//���� �����ڸ� ����Ϸ��� �⺻ �����ڰ� �� ���ǵž��Ѵ�.
}Score;

map<string, list<Score>> studentList;

list<Score> scoreList; 

// bool�� �� ������ ��������.
bool AddStudent(string _key, string _name,int _kor,int _eng,int _math )
{
	map<string, list<Score>>::iterator iter = studentList.find(_key);

	if (_name == "")
		return false;

	Score score = Score(_name,10, 20, 30);

	if (iter == studentList.end())
	{
		list<Score> tempList;
		tempList.push_back(score);
		studentList.insert(make_pair(_key, tempList));
	}
	else
		iter->second.push_back(score);

	return true;
}

int main(void)
{
	//�������� �����ڸ� ������ s������ ȣ���Ͽ� ����
	// ������ ȣ���� ���ٸ� ������ �ȵ�
	Score s = Score(10,20,30);
	// ��
	Score s1;//�����ڰ� ������ ����

	Score s2(s);
	// �⺻ �����ڿ� �⺻ ���� �����ڴ� ��ó�� ���� �������� �ʴ���
	// �⺻������ ���ǵǾ��ֱ⿡ ����� �� �ִ�.

	/*
	map<string, Score> mapList;

	string key = "ȫ";
	Score score = Score(10, 20, 30);

	//** map���� ���Ǵ� string�� pk(������)�� =>�ߺ��� �� X

	mapList.insert(make_pair(key, score));

	score = Score(100, 200, 300);
	score.name = "�浿";
	mapList[key] = score;

	cout << key + mapList[key].name << endl;
	cout << mapList[key].Kor << endl;
	cout << mapList[key].Eng << endl;
	cout << mapList[key].Math << endl;
	//** "AAA"��� �������� �ٲ�� �ȴ�.
	//������ ���� ��Ĵ�� �ϸ� �Ȱ��� �̸��� �����ڿ� ���ؼ��� ������ �ȵ� �� �ִ�.
	// ���ذ�

	multimap<string, Score> multiList;

	multiList.insert(make_pair(key, score));
	multiList.insert(make_pair(key, score));
	
	for (multimap<string, Score>::iterator iter = multiList.begin(); iter != multiList.end(); ++iter)
	{
		cout << "[" << iter->first << "]" << endl;
		cout << "��������" << ":" << iter->second.Kor << endl;
		cout << "��������" << ":" << iter->second.Eng << endl;
		cout << "��������" << ":" << iter->second.Math << endl;
	}
	//������, �̹���� �Ϻ��� �ذ�å�� �� �� ����.
	//** map      : Ʈ������,���� �ӵ��� ã��
	//				� ���� �־ �ڵ����� ������ ������ �� 
	//				����Ʈ ó�� data�� �ϳ��ϳ� �� ã�� �ʰ� level�� ���Ƽ� ã�⿡
	//              ��û �����ӵ��� ã�� �� �ִ�. 
	//              
	//** multimap : 
	*/


	string key = "ȫ";
	string name = "�浿";

	

	if (!AddStudent(key, name , 10, 20, 30))
		cout << "Log" << endl;
/*
	else
		cout << studentList[key].front().Name << endl;
*/


	for (map<string,list<Score>>::iterator iter = studentList.begin();
		iter != studentList.end();++iter)
	{
		cout << "[" << iter->first + name << "]" << endl;

		scoreList = iter->second; // scoreList�� iter->second�� ��

		for (list<Score>::iterator itera = scoreList.begin();
			itera != scoreList.end(); ++itera)
		{
			cout << "��������" << ":" << itera->Kor << endl;
			cout << "��������" << ":" << itera->Eng << endl;
			cout << "��������" << ":" << itera->Math << endl;
		}
		
	}



	return 0;
}



