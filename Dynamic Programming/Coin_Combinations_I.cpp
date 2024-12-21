/**
 *    author:  _Berlin_
 *    created: 19.12.2024 03:54:41 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 105;
const int mod = 1e9 + 7;
 
int n, x, coins[N], dp[1000005];
 
int fun(int x) {
  if (x == 0) return 1;
  if (x < 0) return 0;
  if(dp[x] != -1) return dp[x];
  int ways = 0;
  for(int i = 1; i <= n; i++){
    ways += fun(x - coins[i]);
    ways %= mod;
  }
  return dp[x] = ways;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n >> x;
  for(int i = 1; i <= n; i++) {
    cin >> coins[i];
  }
  memset(dp, -1, sizeof dp);
  cout << fun(x) << "\n";
 
  return 0;
}