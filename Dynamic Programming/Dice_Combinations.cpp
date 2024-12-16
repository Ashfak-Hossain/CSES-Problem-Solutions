/**
 *    author:  _Berlin_
 *    created: 16.12.2024 08:21:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e6 + 9;
const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int dp[N];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int d = 1; d <= 6 && i - d >= 0; d++){
      (dp[i] += dp[i - d]) %= mod;
    }
  }
  cout << dp[n] << "\n";

  return 0;
}