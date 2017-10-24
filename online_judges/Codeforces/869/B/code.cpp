#include <bits/stdc++.h>

using namespace std;

int main() {

  long long int a, b;
  scanf("%lld %lld", &a, &b);
  
  if(b - a >= 5) {
    printf("0\n");
  }
  else {
    long long int cont = 1;
    for(long long int i = a + 1; i <= b; i++) {
      cont = (cont * i) % 10;
    }
    
    printf("%lld\n", cont);
  }


  return 0;
}
