
/**
 *    author:  _Berlin_
 *    created: 19.12.2024 10:45:27 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 1e6 + 9;
constexpr int inf = 0x3f3f3f3f;
 
int dp[N];
 
int fun(int n) {
  if (n == 0) return 0;
  if(dp[n] != -1) return dp[n];
  int ans = inf;
  int num = n;
  while(num > 0) {
    int digit = num % 10;
    if(digit > 0) {
      ans = min(ans, fun(n - digit) + 1);
    }
    num /= 10;
  }
  return dp[n] = ans;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << fun(n) << "\n";
 
  return 0;
}