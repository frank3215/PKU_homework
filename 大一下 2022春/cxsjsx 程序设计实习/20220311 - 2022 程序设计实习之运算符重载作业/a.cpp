// A:MyString
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
////////////////////////////////////////
	void Copy(const MyString &ms) {
		// if (p) delete [] p;
		p = new char[strlen(ms.p) + 1];
		strcpy(p,ms.p);
	}
	friend ostream & operator<<(ostream & os, const MyString & ms) {
		return os << ms.p;
	}
	void operator =(const MyString &ms) {
		this->Copy(ms);
	}
	void operator =(const char *s) {
		*this = MyString(s);
	}
////////////////////////////////////////
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
