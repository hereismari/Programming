#include <bits/stdc++.h>

using namespace std;

long power(long num, long pow)
{
    if (pow == 0) return 1;
    if (pow % 2 == 0)
        return power(num*num, pow / 2);
    else
        return power(num, pow - 1) * num;
}

int main() {




	return 0;
}
