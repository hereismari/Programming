#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define ll long long


ll cows[MAX], sorted_cows[MAX];
int n, q, sqrt_n;

void sort_cows() {
  for(int i = 0; i < n; i += qsrt_n)
      sort(sorted_cows + i, sorted_cows + min(i + root, n));
}

void update(int i, ll x) {
  cows[i] = x;
}

int bin_search(int b, int e, ll x) {
  int original_b = b;
  int a[e - b + 1];
  
  copy(cows + b, cows + e + 1, a);
  sort(a, a + e - b + 1);
  /*for(int i = 0; i < e - b + 1; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
 */
  int m;
  int s = 0, f = e - b;
  while(s <= f) {
    m = s + (f-s)/2;
    if (a[m] <= x) s = m + 1;
    else f = m - 1;
  }
  
  //printf("b: %d m: %d e: %d, original_b: %d\n", s, m, f, original_b);
  return f + 1;
}

int search_interval(int i, int j, ll x) {
  int ans = 0;
  for(int k = i; k <= j;) {
    if (k % sqrt_n == 0 && k + sqrt_n - 1 <= j) {
      ans += bin_search(k, k + sqrt_n - 1, x);
      k += sqrt_n;
    }
    else {
      ans += (cows[k] <= x);
      k++;
    }
  }
  
  return ans;
}

int main() {

  scanf("%d %d\n", &n, &q);

  sqrt_n = (int)sqrt(n) + 1;
  for (int i = 0; i < n; i++) scanf("%lld\n", &cows[i]);
  
  sort_cows();

  char c;
  int index1, index2;
  ll x;
  while (q--) {
    scanf("\n%c", &c);
  
    if (c == 'M') {
      scanf(" %d %lld", &index1, &x);
      update(index1-1, x);
    }
    else {
      scanf(" %d %d %lld", &index1, &index2, &x);
      printf("%d\n", search_interval(index1-1, index2-1, x));
    }
  
  }

  return 0;
}

