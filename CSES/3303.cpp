#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  ll n, m, k;
  cin >> n >> m >> k;
 
  vector<ll> is_shop(n + 1, 0);
  vector<ll> shopList;
  for (ll i = 0; i < k; i++) {
    ll u;
    cin >> u;
    is_shop[u] = 1;
    shopList.push_back(u);
  }
 
  vector<vector<ll>> adl(n + 1);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    adl[u].push_back(v);
    adl[v].push_back(u);
  }
 
  vector<ll> dist(n + 1, -1);
  vector<ll> vis(n + 1, 0);
  queue<pair<ll, ll>> q;
 
  // Multi-source BFS from all shop nodes
  for (ll s : shopList) {
    vis[s] = 1;
    q.push({s, 0});
  }
 
  while (!q.empty()) {
    auto [c, d] = q.front(); q.pop();
 
    for (ll nei : adl[c]) {
      if (!vis[nei]) {
        vis[nei] = 1;
        dist[nei] = d + 1;
        q.push({nei, d + 1});
      }
    }
  }
 
  // Fix distances for shop nodes — find nearest *other* shop
  for (ll i = 1; i <= n; i++) {
    if (is_shop[i]) {
      ll minDist = LLONG_MAX;
      vector<ll> vis2(n + 1, 0);
      queue<pair<ll, ll>> q2;
      q2.push({i, 0});
      vis2[i] = 1;
 
      while (!q2.empty()) {
        auto [c, d] = q2.front(); q2.pop();
 
        if (d != 0 && is_shop[c]) {
          minDist = d;
          break;
        }
 
        for (ll nei : adl[c]) {
          if (!vis2[nei]) {
            vis2[nei] = 1;
            q2.push({nei, d + 1});
          }
        }
      }
 
      dist[i] = (minDist == LLONG_MAX ? -1 : minDist);
    }
  }
 
  for (ll i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
 
  return 0;
}
