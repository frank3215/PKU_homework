#include <iostream>
using namespace std;
class Sample {
public:
	int v;
////////////////////////////////////////
	Sample() {}
	Sample(int n): v(n) {}
	Sample(const Sample &s): v(s.v+2) {}
	void operator =(const Sample &s) {
		v = s.v;
	}
////////////////////////////////////////
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
