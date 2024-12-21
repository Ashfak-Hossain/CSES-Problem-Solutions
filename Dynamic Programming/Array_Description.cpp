/**
 *    author:  _Berlin_
 *    created: 21.12.2024 11:21:30 AM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int MAX_N = 1e5 + 9;
const int MAX_M = 105;
const int mod = 1e9 + 7;
 
int n, m, a[MAX_N], dp[MAX_N][MAX_M];
 
int fun(int i, int last) {
  if(i == n + 1) return 1;
  int &ans = dp[i][last];
  if(ans != -1) return ans;
  ans = 0;
  int l, r;
  if(a[i] > 0) {
    l = r = a[i];
  } else {
    if(i == 1) {
      l = 1, r = m;
    } else {
      l = max(1, last - 1);
      r = min(m, last + 1);
    }
  }
  for(int cur = l; cur <= r; cur++){
    if(i == 1 || abs(last - cur) <= 1) {
      ans += fun(i + 1, cur);
      ans %= mod;
    }
  }
  return ans;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  cout << fun(1, 0) << "\n";
 
  return 0;
}