// E:别叫，这个大整数已经很简化了!
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
////////////////////////////////////////
#define maxn 210
public:
	long long a[maxn], siz;
	static char s[maxn];
	CHugeInt(): siz() { memset(a, 0, sizeof(a)); }
	CHugeInt(int n) {
		siz = 0;
		memset(a, 0, sizeof(a));
		while (n) {
			a[siz++] = n%10;
			n /= 10;
		}
	}
	CHugeInt(char *s) {
		memset(a, 0, sizeof(a));
		siz = strlen(s);
		for (int i = 0; i < siz; ++i) {
			a[i] = s[siz-1-i]-'0';
		}
	}
	void norm() {
		int carry = 0;
		for (int i = 0; i < siz; ++i) {
			a[i] += carry;
			carry = a[i] / 10;
			a[i] %= 10;
		}
		while (carry) {
			a[siz++] = carry % 10;
			carry /= 10;
		}
	}
	CHugeInt operator +(const CHugeInt &b) const {
		CHugeInt c;
		c.siz = max(b.siz, siz);
		for (int i = 0; i < c.siz ; ++i) {
			c.a[i] = b.a[i] + a[i];
		}
		c.norm();
		return c;
	}
	friend CHugeInt operator +(int n, const CHugeInt &a) {
		return a + n;
	}
	CHugeInt& operator ++() {
		if (!siz) a[siz++] = 0;
		a[0]++;
		norm();
		return *this;
	}
	CHugeInt operator ++(int k) {
		cout << k << endl;
		CHugeInt c(*this);
		if (!siz) a[siz++] = 0;
		a[0]++;
		norm();
		return c;
	}
	CHugeInt& operator +=(int n) {
		return (*this) = (*this) + n;
	}
	CHugeInt operator +(const int &n) const {
		CHugeInt b(n), c = (*this) + b;
		return c;
	}
	friend istream& operator >>(istream &is, CHugeInt &chi) {
		is >> s;
		chi = CHugeInt(s);
		return is;
	}
	friend ostream& operator <<(ostream &os, const CHugeInt &chi) {
		for (int i = chi.siz-1; ~i; --i) {
			cout << chi.a[i];
		}
		return os;
	}
////////////////////////////////////////
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
