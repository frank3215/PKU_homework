// B:简单的foreach | 2022程序设计实习之输入输出与模板作业 | http://cxsjsx.openjudge.cn/hw202207/B/
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////
template<typename T> void MyForeach(T *op, T *ed, void(*fun)(T &)) {
	for (T *i = op; i != ed; ++i) {
		fun(*i);
	}
}
template<typename T> void MyForeach(T *op, T *ed, void(*fun)(T)) {
	for (T *i = op; i != ed; ++i) {
		fun(*i);
	}
}
////////////////////////////////////////
void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++ n;
}
string array[100];
int a[100];
int main() {
	int m,n;
	while(cin >> m >> n) {
		for(int i = 0;i < m; ++i)
			cin >> array[i];
		for(int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(array,array+m,Print);		 
		cout << endl;
		MyForeach(a,a+n,Inc);		 
		for(int i = 0;i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}
