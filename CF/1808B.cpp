#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int solve(int i, int j, vector<vector<int>>& nm) {
  int ans = 0;
  for(int k = 0; k < nm[0].size(); k++) {
    ans += abs(nm[i][k] - nm[j][k]);
  }

  return ans;
} 

int main() {
  int t; 
  cin >> t; 
  while(t--) {
    int n, m; cin >> n >> m; 
    vector<vector<int>> nm (n, vector<int> (m, 0)); 
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> nm[i][j];
      }
    }
    
    int ans = 0; 
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        ans += solve(i, j, nm);
      }
    }

    cout << ans << endl;
  }

  return 0; 
}
