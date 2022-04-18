// F:我自己的 ostream_iterator | 2022 程序设计实习之STL1作业 | http://cxsjsx.openjudge.cn/hw202208/F/
#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
	for(; s != e; ++s,++x)
		*x = *s;
}

 
template<class T>
class myostream_iteraotr
{
////////////////////////////////////////
public:
	ostream *out;
	string sep;
	myostream_iteraotr(ostream &_out, string _sep): out(&_out), sep(_sep) {}
	void operator ++() { cout << sep; }
	myostream_iteraotr<T> operator *() { return *this; }
	void operator =(const T& t) { (*out) << t; }
////////////////////////////////////////
};


int main()
{	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
	list<int> lst(a,a+SIZE);
	myostream_iteraotr<int> output(cout,",");
	Copy( lst.begin(),lst.end(),output); 
	cout << endl;
	myostream_iteraotr<double> output2(cout,"--");
	Copy(b,b+SIZE,output2);
	return 0;
}
