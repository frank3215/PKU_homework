// C:惊呆！Point竟然能这样输入输出
#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
////////////////////////////////////////
		friend istream& operator >>(istream &is, Point &p) {
			return is >> p.x >> p.y;
		}
		friend ostream& operator <<(ostream &os, const Point &p) {
			return os << p.x << ',' << p.y;
		}
////////////////////////////////////////
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
