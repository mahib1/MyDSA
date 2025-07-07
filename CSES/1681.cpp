// #include <bits/stdc++.h>
//
// using namespace std;
//
// int mawd = 1e9 + 7;
// int paths = 0;
//
// void dfs(vector<int>& vis, unordered_map<int , vector<int>>& adl, int node, int end) {
//   if(vis[node]) return;
//   if(node == end) paths = (paths+1) % mawd;
//
//   vis[node] = 1;
//
//   for(int nei : adl[node]) {
//     dfs(vis, adl, nei, end);
//   }
//
//   vis[node] = 0;
//   return;
// }
//
//
// int main() {
//   int n, m;
//   cin >> n >> m;
//
//   unordered_map <int, vector<int>> adl;
//   for(int i = 0; i < m; i++) {
//     int u , v; 
//     cin >> u >> v;
//
//     adl[u].push_back(v);
//   }
//
//   vector<int> vis (n + 1, 0);
//   dfs(vis, adl, 1, n);
//   cout << paths << endl;
//   
//   return 0;
// }
//

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  const int MOD = 1e9 + 7;
  vector<vector<int>> adl(n + 1);
  vector<int> indeg(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adl[u].push_back(v);
    indeg[v]++;
  }

  vector<long long> dp(n + 1, 0);
  dp[1] = 1; // start at node 1

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int nei : adl[node]) {
      dp[nei] = (dp[nei] + dp[node]) % MOD;
      if (--indeg[nei] == 0) q.push(nei);
    }
  }

  cout << dp[n] << endl;
  return 0;
}
