/**
 *    author:  _Berlin_
 *    created: 21.12.2024 02:52:13 AM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, x;
  cin >> n >> x;
  
  vector<int> price(n), pages(n);
  for(int i = 0; i < n; i++) cin >> price[i];
  for(int i = 0; i < n; i++) cin >> pages[i];
 
  int dp[x + 5];
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; i++){
    for(int j = x; j >= price[i]; j--){
      dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    }
  }
 
  cout << dp[x] << "\n";
 
  return 0;
}