#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;

ll next(ll x, ll a, ll b, ll c) {
  return (a * x + b) % c;
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll x, a, b, c;
  cin >> x >> a >> b >> c;

  ll ans = 0;
  ll base = x;

  ll mini = LLONG_MAX;

  deque<pair<ll, ll>> dq;

  for(ll i = 0; i < n; i++) {
    while(!dq.empty() && dq.back().first >= x) {
      dq.pop_back();
    }

    dq.emplace_back(x, i);

    while(!dq.empty() && dq.front().second <= i - k) {
      dq.pop_front();
    }


    if(i >= k - 1) {
      ans ^= dq.front().first;
    }

    x = next(x, a, b, c);
  }

  cout << ans << endl;
  return 0;
}
