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

	string key = "홍";
	Score score = Score(10, 20, 30);

	//** map에서 사용되는 string은 pk(고유값)임 =>중복될 수 X

	mapList.insert(make_pair(key, score));

	score = Score(100, 200, 300);
	score.name = "길동";
	mapList[key] = score;

	cout << key + mapList[key].name << endl;
	cout << mapList[key].Kor << endl;
	cout << mapList[key].Eng << endl;
	cout << mapList[key].Math << endl;
	//** "AAA"라는 고유값이 바뀌게 된다.
	//원래는 위의 방식대로 하면 똑같은 이름을 가진자에 대해서는 적용이 안될 수 있다.
	// ▼해결

	multimap<string, Score> multiList;

	multiList.insert(make_pair(key, score));
	multiList.insert(make_pair(key, score));

	for (multimap<string, Score>::iterator iter = multiList.begin(); iter != multiList.end(); ++iter)
	{
		cout << "[" << iter->first << "]" << endl;
		cout << "국어점수" << ":" << iter->second.Kor << endl;
		cout << "영어점수" << ":" << iter->second.Eng << endl;
		cout << "수학점수" << ":" << iter->second.Math << endl;
	}
	//하지만, 이방법도 완변한 해결책이 될 수 없다.
	//** map      : 트리구조,빠른 속도로 찾음
	//				어떤 값을 넣어도 자동으로 층층히 정렬이 됨 
	//				리스트 처럼 data를 하나하나 다 찾지 않고 level만 돌아서 찾기에
	//              엄청 빠른속도로 찾을 수 있다. 
	//              
	//** multimap : 
	*/

	map<string, list<Score>> studentList;

	string key = "홍";
	Score score = Score(10, 20, 30);
	score.name = "길동";


	return 0;
}