/*
 *	测试析构函数不是virtual的情况和是virtual的情况
 *
 *
 */

#include <iostream>

using namespace std;

class person
{
public:
	person(){
		cout << "I am person struct" << endl;
	}

/*virtual*/ ~person(){
		cout << "I am person destruct" << endl;
	}
};


class man:public person
{
public:
	man(){
		cout << "I am a man struct" << endl;
	}

	~man(){
		cout << "I am a man destruct" << endl;
	}
};


int main()
{

//man zhang;
/*
 正常的构造和析构顺序
I am person struct
I am a man struct
I am a man destruct
I am person destruct
*/

	person *base = new man;
	delete base;
/*
这种基类指针指向派生类的情况的析构,会发现只析构了父类,这会导致内存泄漏
I am person struct
I am a man struct
I am person destruc
 */

/*
带上virtual关键字后的析构
I am person struct
I am a man struct
I am a man destruct
I am person destruct
*/


}	


