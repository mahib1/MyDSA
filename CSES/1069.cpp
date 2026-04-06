#include <iostream>
#include <string>

using namespace std; 

int main() {
  string s; cin >> s; 
  if(s.size() < 2) {
    cout << s.size() << endl; return 0; 
  }
  int n = s.size(); 
  int slow = 0;
  int i = 0; 
  int ans = 0; 
  for(i = 1; i < n; i++) {
    if(s[i] != s[i - 1]) {
      ans = max(i - slow, ans);
      slow = i; 
    } 
  }


  ans = max(i - slow, ans); 

  cout << ans << endl; 
  return 0; 
}
