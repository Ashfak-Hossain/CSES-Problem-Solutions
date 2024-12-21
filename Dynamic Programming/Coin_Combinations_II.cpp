/**
 *    author:  _Berlin_
 *    created: 21.12.2024 10:52:26 AM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int MAX_N = 1e6 + 9;
const int mod = 1e9 + 7;
 
int dp[MAX_N];
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for(auto &i : coins) cin >> i;
 
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
 
  for(int i = 1; i <= n; i++){
    for(int w = 0; w <= x; w++) {
      if(w - coins[i - 1] >= 0) {
        dp[w] += dp[w - coins[i - 1]];
        dp[w] %= mod;
      }
    }
  }
  
  cout << dp[x] << "\n";
 
  return 0;
}