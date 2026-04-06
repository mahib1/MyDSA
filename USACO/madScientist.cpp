#include <iostream>
using namespace std; 


int main() {
  int n; cin >> n; 
  string s; cin >> s; 
  string a; cin >> a; 
  vector<int> walls;

  int start = 0; 
  int ans = 0; 
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == a[i]) {
      ans += start != i; 
      start = i + 1; 
    } 
  }

  cout << ans << endl; 
  return 0; 
}
