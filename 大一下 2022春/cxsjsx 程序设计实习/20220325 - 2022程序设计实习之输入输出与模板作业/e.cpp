// E:山寨版istream_iterator | 2022程序设计实习之输入输出与模板作业 | http://cxsjsx.openjudge.cn/hw202207/E/
#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
/* 另一种解法
};
#include <iterator>
#define CMyistream_iterator istream_iterator
struct AAAA{
*/
////////////////////////////////////////
private:
	istream& mis;
	T tmp;
public:
	CMyistream_iterator(istream &is): mis(is) { mis >> tmp; }
	T operator *() {
		return tmp;
	}
	void operator ++(int k) {
		mis >> tmp;
	}
////////////////////////////////////////
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //读入 n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //读入 n2
		 inputInt ++;
		 n3 = * inputInt; //读入 n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}
