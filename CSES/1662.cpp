#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std; 

#define ll long long

int main() {
  int n; cin >> n; 
  vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i]; 

  unordered_map<ll, ll> p; 
  p.reserve(n);

  ll sum = 0; 
  ll ans = 0; 
  p[0] = 1; 
  for(int i = 0; i < n; i++) {
    sum += v[i]; 
    ll rem = ((sum % n) + n) % n;

    ans += p[rem];
    p[rem]++;
  }

  cout << ans << endl;
  return 0; 
}
