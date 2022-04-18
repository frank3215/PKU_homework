// D:你真的搞清楚为啥 while(cin >> n) 能成立了吗？ | 2022程序设计实习之输入输出与模板作业 | http://cxsjsx.openjudge.cn/hw202207/D/
#include <iostream>
using namespace std;
class MyCin
{
////////////////////////////////////////
public:
	bool fail = false;
	MyCin& operator >>(int &n) {
		cin >> n;
		if (n == -1) fail = true;
		return *this;
	}
	operator bool() { return !fail && bool(cin); }
////////////////////////////////////////
};
int main()
{
	MyCin m;
	int n1,n2;
	while( m >> n1 >> n2) {
		cout  << n1 << " " << n2 << endl;
	}
	return 0;
}
