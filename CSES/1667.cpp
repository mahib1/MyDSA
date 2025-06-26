#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
 
using namespace std;
 
// vector<int> parent, r; 
//
// int find(int x) {
//   if(parent[x] == x) return x; 
//
//   return parent[x] = find(parent[x]);
// }
//
// void un(int a, int b) {
//   a = find(a);
//   b = find(b);
//
//   if(r[a] > r[b]) parent[b] = a;
//   else parent[a] = b;
//
//   if(r[a] == r[b]) r[b]++;
// }
 
 
int main () {
  int n, m;
  cin >> n >> m;
 
  // parent.resize(n);
  // r.resize(n);
  //
  // for(int i = 0; i < n; i++) {
  //   parent[i] = i; 
  //   r[i] = 0;
  // }
  //
  // vector<vector<int>> edl;
  // for(int i = 0; i < m; i++) {
  //   int a, b; 
  //   cin >> a >> b;
  //   edl.push_back({a, b});
  // }
  //
  // for(int i = 0; i < m; i++) {
  //   un(edl[i][0], edl[i][1]);
  // }
  //
  // if(find(1) == find(n)) cout << "WOOOHOOOO\n";
  // else cout << "IMPOSSIBLE\n";
  
  vector<vector<int>> edl (m);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edl[i] = {a, b};
  }
 
  //do a bfs to find the shortest path from 1 to n
  queue<int> q; 
 
  vector<int> dist(n + 1, -1);
  dist[1] = 1;
 
  vector<int> par (n + 1, -1);
  
  unordered_map<int, vector<int>> adl; 
  for(auto edge : edl) {
    adl[edge[0]].push_back(edge[1]);
    adl[edge[1]].push_back(edge[0]);
  }// made the adj list;
  //
  q.push(1);
 
  while(!q.empty()) {
    int c = q.front(); q.pop();
 
    // process; 
    for(int nei : adl[c]) {
      if(dist[nei] != -1) continue;
      dist[nei] = dist[c] + 1;
      q.push(nei);
      par[nei] = c;
    }
  }
 
  vector<int> path;
 
  if(dist[n] == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  } else {
    cout << dist[n] << endl;
    path.push_back(n);
    int i = n;
    while(par[i] != -1) {
      path.push_back(par[i]);
      i = par[i];
    }
 
    for(int i = path.size() - 1; i >= 0; i--) {
      cout << path[i] << " ";
    }
 
    cout << endl;
  }
 
 
  return 0;
}
