// A:简单的SumArray | 2022程序设计实习之输入输出与模板作业 | http://cxsjsx.openjudge.cn/hw202207/A/
#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
////////////////////////////////////////
	T *st, T *ed) {
	T res = T();
	for (T *i = st; i != ed; ++i) {
		res = res + *i;
	}
	return res;
////////////////////////////////////////
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}
