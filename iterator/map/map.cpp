#include <iostream>
#include <map>
#include <list>

using namespace std;


typedef struct Score
{
	string name;

	int Kor;
	int Eng;
	int Math;

	Score():Kor(0),Eng(0),Math(0){}

	Score(int _kor, int _eng, int _math) :
		Kor(_kor), Eng(_eng), Math(_math) {}
	
};

int main(void)
{
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

	map<string, list<Score>> studentList;

	string key = "ȫ";
	Score score = Score(10, 20, 30);
	score.name = "�浿";


	return 0;
}