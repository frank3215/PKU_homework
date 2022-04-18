// A:goodcopy | 2022 程序设计实习之STL1作业 | http://cxsjsx.openjudge.cn/hw202208/A/
#include <iostream>
using namespace std;


template <class T>
struct GoodCopy {
////////////////////////////////////////
	void operator ()(T* s, T* e, T* u) {
		int siz = e-s;
		T* t = new T [siz];
		for (int i = 0; i < siz; ++i) t[i] = s[i];
		for (int i = 0; i < siz; ++i) u[i] = t[i];
		delete [] t;
	}
////////////////////////////////////////
};

int a[200];
int b[200];
string c[200];
string d[200];

template <class T>
void Print(T s,T e) {
	T t = s;
	for(; s != e; ++s)
		cout << * s << ",";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while( t -- ) {
		int m ;
		cin >> m;
		for(int i = 0;i < m; ++i)
			cin >> a[i];
		GoodCopy<int>()(a,a+m,b);
		Print(b,b+m);
		GoodCopy<int>()(a,a+m,a+m/2);
		Print(a+m/2,a+m/2 + m);

		for(int i = 0;i < m; ++i)
			cin >> c[i];
		GoodCopy<string>()(c,c+m,d);
		Print(c,c+m);
		GoodCopy<string>()(c,c+m,c+m/2);
		Print(c+m/2,c+m/2 + m);
	}
	return 0;
}
