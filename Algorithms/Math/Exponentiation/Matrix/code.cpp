#include <bits/stdc++.h>
#define SIZE 10
#define ll long long int

using namespace std;

void one(long a[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = (i == j);
}

//Multiply matrix a to matrix b and print result into a
void mul(long a[SIZE][SIZE], long b[SIZE][SIZE]) {

    long res[SIZE][SIZE] = {{0}};

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = res[i][j];
}

void pow(long a[SIZE][SIZE], long n, long res[SIZE][SIZE]) {

    one(res);

    while (n > 0) {
        if (n % 2 == 0) { mul(a, a); n /= 2; }
        else { mul(res, a); n--; }
    }
}

int main() {


	return 0;
}
