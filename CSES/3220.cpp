#include <bits/stdc++.h>
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

  ll sum = 0;
  ll base = x;

  for (ll i = 0; i < k; i++) {
    sum += x;
    x = next(x, a, b, c);
  }

  ll l = 0;
  ll newSum = sum;

  while (l < n - k) {
    newSum -= base;
    newSum += x;

    x = next(x, a, b, c);
    base = next(base, a, b, c);

    sum ^= newSum;
    l++;
  }

  cout << sum << '\n';
  return 0;
}
