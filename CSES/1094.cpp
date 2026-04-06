#include <iostream>
#include <vector>

using namespace std; 
#define ll long long


int main() {
  int n; cin >> n; 

  vector<ll> v (n, 0); for(int i = 0; i < n; i++) cin >> v[i];

  ll ans = 0; 
  for(ll i = 1; i < n; i++) {
    if(v[i] < v[i - 1]) {
      ans += v[i - 1] - v[i];
      v[i] = v[i - 1];
    }
  }

  cout << ans << endl;
  return 0; 
}
