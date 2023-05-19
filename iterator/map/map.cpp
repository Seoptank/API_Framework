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

	//** 생성자↓: 생성자는 생성하고자 할때는 무조건 생성돼야함.
	tagScore():Name(""), Kor(0), Eng(0), Math(0) {}

	//** 복사생성자↓

	tagScore(string _name) :
		Name(_name), Kor(0), Eng(0), Math(0) {}

	tagScore(int _kor, int _eng, int _math) :
		Name(""), Kor(_kor), Eng(_eng), Math(_math) {}
	
	tagScore(string _name, int _kor, int _eng, int _math) :
		Name(_name),Kor(_kor), Eng(_eng), Math(_math) {}

	//복사 생성자를 사용하려면 기본 생성자가 꼭 정의돼야한다.
}Score;

map<string, list<Score>> studentList;

list<Score> scoreList; 

// bool로 쓴 이유를 생각하자.
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
	//오른쪽의 생성자를 왼쪽의 s변수에 호출하여 생성
	// 생성자 호출이 없다면 생성도 안됨
	Score s = Score(10,20,30);
	// ↓
	Score s1;//생성자가 생략된 형태

	Score s2(s);
	// 기본 생성자와 기본 복사 생성자는 위처럼 따로 정의하지 않더라도
	// 기본적으로 정의되어있기에 사용할 수 있다.

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


	string key = "홍";
	string name = "길동";

	

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

		scoreList = iter->second; // scoreList에 iter->second를 줌

		for (list<Score>::iterator itera = scoreList.begin();
			itera != scoreList.end(); ++itera)
		{
			cout << "국어점수" << ":" << itera->Kor << endl;
			cout << "영어점수" << ":" << itera->Eng << endl;
			cout << "수학점수" << ":" << itera->Math << endl;
		}
		
	}



	return 0;
}



