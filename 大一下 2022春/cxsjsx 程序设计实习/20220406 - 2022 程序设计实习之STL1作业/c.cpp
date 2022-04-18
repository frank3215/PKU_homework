// C:很难蒙混过关的CArray3d三维数组模板类 | 2022 程序设计实习之STL1作业 | http://cxsjsx.openjudge.cn/hw202208/C/
#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
/*
	CArray3D(int _n, int _m, int _o): n(_n), m(_m), o(_o) {
		a = new T ** [_n];
		for (int i = 0; i < _n; ++i) {
			a[i] = new T * [_m];
			for (int j = 0; j < _m; ++j) {
				a[i][j] = new T [_o];
				for (int k = 0; k < _o; ++k) {
					a[i][j][k] = 0;
				}
			}
		}
	}
*/
////////////////////////////////////////
public:
	T *a;
	int n, m, o;
	struct CArray2D {
		T *a;
		int m, o;
		CArray2D(int _m, int _o, T *_a): m(_m), o(_o), a(_a) {}
		operator T*() {
			return a;
		}
		T* operator [](int j) {
			return a + j * o;
		}
	};
	CArray3D(int _n, int _m, int _o): n(_n), m(_m), o(_o) {
		a = new T [n * m * o];
		memset(a, 0, n*m*o*sizeof(T));
	}
	operator T*() {
		return a;
	}
	CArray2D operator [](int i) {
		return CArray2D(m, o, a + i * m * o);
	}
////////////////////////////////////////
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k) 
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) 
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];	
		}
	}
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));	
	memset(a[1],-1 ,20*sizeof(int));
	PrintA(); 
	memset(a[1][1],0 ,5*sizeof(int));	
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
		
	return 0;
}
