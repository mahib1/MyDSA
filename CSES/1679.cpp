#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<int, vector<int>> adl;
  vector<int> inDeg (n + 1, 0);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adl[u].push_back(v);

    inDeg[v]++;
  }

  vector<int> vis (n + 1, 0);
  queue<int> q;

  vector<int> toporder;

  for(int i = 1; i <= n; i++) {
    if(inDeg[i] == 0) q.push(i);
  }

  while(!q.empty()) {
    int c = q.front(); q.pop();
    toporder.push_back(c);

    for(int i : adl[c]) {
      inDeg[i]--; //decrease indeg of all neighbours
      if(inDeg[i] == 0) q.push(i);
    }
  }

  if(toporder.size() != n) {
    cout << "IMPOSSIBLE\n" << endl;
    return 0;
  }
  
  for(int i = 0; i < toporder.size(); i++) {
    cout << toporder[i] << " ";
  } cout << endl;

  return 0;
}
