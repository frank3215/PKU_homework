// F:这个模板并不难 | 2022程序设计实习之输入输出与模板作业 | http://cxsjsx.openjudge.cn/hw202207/F/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass {
////////////////////////////////////////
private:
	T *p;
	int size;
public:
	myclass(T *q, int siz) {
		p = new T [siz];
		size = siz;
		for (int i = 0; i < siz; ++i) p[i] = q[i];
	}
////////////////////////////////////////
~myclass( ) {
		delete [] p;
	}
	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
int main() {
	char line[100];
	while( cin >> line ) {
		myclass<char> obj(line,strlen(line));;
		obj.Show();
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		myclass<int> obj2(a,n);
		obj2.Show();
	}
	return 0;
}
