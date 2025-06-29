#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define ll long long

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  
  std::unordered_map<int , vector<pair<int, int>>> adl;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adl[u].push_back({v, w});
  }
  
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, 1});
  vector<int> cnt (n + 1, 0);
  vector<ll> res;

  while(!pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();

    if(cnt[u] >= k) continue;
    cnt[u] ++;
    
    if(u == n) {
      res.push_back(cost);
      if(res.size() == k) break;
    }

    for(auto [v, w] : adl[u]) {
      pq.push({cost + w, v});
    }
  }

  for(ll cost : res) {
    cout << cost << " ";
  } cout << endl;

  return 0;
}
