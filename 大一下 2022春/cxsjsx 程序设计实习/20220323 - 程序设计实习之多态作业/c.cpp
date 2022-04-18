// C:这是什么鬼delete | 2022 程序设计实习之多态作业 | http://cxsjsx.openjudge.cn/hw202206/C/
#include <iostream> 
using namespace std;
class A 
{ 
public:
	A() { }
////////////////////////////////////////
	virtual ~A() { cout << "destructor A" << endl; } 
////////////////////////////////////////
}; 
class B:public A { 
	public: 
	~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
	A * pa; 
	pa = new B; 
	delete pa; 
	return 0;
}
