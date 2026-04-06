#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std; 
#define ll long long
const int MOD = 1e9 + 7;


ll solve(int n, vector<int>& p, vector<int>& dp) {
  if(n == 0) return 0; 
  
  //ans(n) = 1 + min(ans(n - p[i]))
  //
  if(dp[n] != INT_MAX) return dp[n];
  
  ll ans = INT_MAX;
  for(int i = 0; i < p.size(); i++) {
    if(n - p[i] < 0) continue;
    ans = min(ans, solve(n - p[i], p, dp));  
  }

  if(ans == INT_MAX) return dp[n] = -1; 
  ans = ans + 1;
  return dp[n] = ans;
}



int main() {
  int n, t; 
  cin >> n >> t; 

  vector<int> p (n, 0);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }

  vector<int> dp(t + 1, INT_MAX);
  cout << solve(t, p,  dp) << endl;

}
