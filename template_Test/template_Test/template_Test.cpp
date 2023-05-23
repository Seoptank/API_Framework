#include <iostream>

using namespace std;

template<typename T>
class Object
{
private:
	T Number;
public:
	template<typename U, typename V>
	U* Initialize()
	{
		U* u = new U;
		return u;
	}
};

int main(void)
{
	Object<int> O;
	//<>안에 내가 전달하는 값이 내가 지정한 형태가 된다.
	int* pi = O.Initialize<int>();

	cout << pi << endl;
	return 0;
}
