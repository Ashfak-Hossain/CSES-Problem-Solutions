/**
 *    author:  _Berlin_
 *    created: 21.12.2024 12:43:22 PM
**/

/*
 Bottom Up Approach
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
using i64 = long long;
 
const int MAX_N = 1e6 + 9;
const int mod = 1e9 + 7;
 
i64 dp[MAX_N][2];
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  // dp[i][p] = Number of ways to fill from 0th position till the ith position.
 
  dp[1][0] = 1;
  dp[1][1] = 1;
 
  for(int i = 2; i < MAX_N; i++) {
    dp[i][1] = (2 * dp[i - 1][1] % mod + dp[i - 1][0]) % mod;
    dp[i][0] = (4 * dp[i - 1][0] % mod + dp[i - 1][1]) % mod;
  }
  
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << ((dp[n][0] % mod) + (dp[n][1] % mod)) % mod << "\n";
  }
 
  return 0;
}

/*
 Top Down Approach:
*/

i64 solve(int n, int p) {
  if (n == 1) return p == 1 ? 1 : 1;
  i64 &ans = dp[n][p];
  if (ans != -1) return ans;
  if (p & 1) {
    ans = (2 * solve(n - 1, 1) + solve(n - 1, 0)) % mod;
  } else {
    ans = (4 * solve(n - 1, 0) + solve(n - 1, 1)) % mod;
  }
  return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    memset(dp, -1, sizeof(dp));
 
    int t;
    cin >> t;    
    while (t--) {
      int n;
      cin >> n;
      i64 result = (solve(n, 0) + solve(n, 1)) % mod;
      cout << result << "\n";
    }
 
    return 0;
}