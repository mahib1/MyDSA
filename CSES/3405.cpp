#include <bits/stdc++.h>
using namespace std;

int64_t next(int64_t x, int64_t a, int64_t b, int64_t c) {
  return (x * a + b) % c;
}

int main() {
  int64_t n, k; 
  cin >> n >> k;
  
  int64_t x, a, b, c;
  cin >> x >> a >> b >> c;

  int64_t xo = 0;
  int64_t base = x;
  for(int64_t i = 0; i < k; i++) {
    xo |= x;
    x = next(x, a, b, c);
  }

  int64_t winxo = xo;
  int64_t l = 0;
  while(l < n - k) {
    winxo |= base;

    x = next(x, a, b, c); 
    base = next(base, a, b, c);

    xo ^= winxo;
    l++;
  }

  cout << xo << endl;
  return 0;
}
