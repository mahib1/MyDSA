#include <iostream>

using namespace std; 
#define ll long long

void solve() {
  int n;
  cin >> n;
  for (long long k = 1; k <= n; k++) {
    if (k == 1) {
      cout << 0 << endl;
      continue;
    }
    long long total_positions = (k * k) * (k * k - 1) / 2;
    long long attacking_pairs = 4 * (k - 1) * (k - 2);
    cout << total_positions - attacking_pairs << endl;
  }
}


int main() {
  solve();

  return 0; 
}
