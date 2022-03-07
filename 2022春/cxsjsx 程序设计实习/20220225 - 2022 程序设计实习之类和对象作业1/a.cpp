#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
////////////////////////////////////////
    char a[100];
    int b, c, d, e, f, g;
    double h;
public:
    void input() {
        scanf("%[^,],%d,%d,%d,%d,%d,%d", a, &b, &c, &d, &e, &f, &g);
    }
    void calculate() {
        h = (d + e + f + g) / 4.0;
    }
    void output() {
        printf("%s,%d,%d,", a, b, c);
        cout << h << endl;
    }
////////////////////////////////////////
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
