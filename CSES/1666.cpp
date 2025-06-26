#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
 
using namespace std;
 
vector<int> parent;
vector<int> r;
 
int find(int x) {
  if(parent[x] == x) return x; 
 
  return parent[x] = find(parent[x]);
}
 
void un(int a, int b) {
  a = find(a); 
  b = find(b);
 
  if(a == b) return;
 
  if(r[a] > r[b]) parent[b] = a;
  if(r[a] <= r[b]) parent[a] = b;
 
  if(r[a] == r[b]) r[a]++;
}
 
 
int main() {
  int n, m; 
  cin >> n >> m;
 
  parent.resize(n + 1);
  r.resize(n + 1, 0);
 
  for(int i = 1; i <= n; i++) parent[i] = i;
 
  for(int i = 0; i < m; i++) {
    int a, b; 
    cin >> a >> b;
    un(a, b);
  }
 
 
  vector<int> reps; 
  for(int i = 1; i <= n; i++) {
    if(find(i) == i) reps.push_back(i);
  }
 
  cout << reps.size() - 1 << endl;
  for(int i = 1; i < reps.size(); i++) {
    cout << reps[i] << " " << reps[i - 1] << endl;
  }
  return 0;
}
