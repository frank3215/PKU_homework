// E:白给的list排序 | 2022 程序设计实习之STL1作业 | http://cxsjsx.openjudge.cn/hw202208/E/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{	
	double a[] = {1.2,3.4,9.8,7.3,2.6};
	list<double> lst(a,a+5);
	lst.sort(
////////////////////////////////////////
		greater<double>()
////////////////////////////////////////
);
	
	for(list<double>::iterator i  = lst.begin(); i != lst.end(); ++i) 
		cout << * i << "," ;
    return 0;
}
