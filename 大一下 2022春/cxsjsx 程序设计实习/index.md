<!-- 提示：以下代码是可以运行的。（Credit: zyc）

```cpp
#include <cstdio>
#include <iostream>

struct a{
	a(int i = (printf("123\n"),fflush(stdout),exit(0),1)) {}
};

int main() {
	a b;
}
```
-->
