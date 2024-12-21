/**
 *    author:  _Berlin_
 *    created: 17.04.2024 12:01:13 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 105;
const int INF = 1e9, X = 1e6 + 9;
 
int n, x, a[N];
int dp[N][X];
 
// Recursive not working due to time limit -> Here we need iterative dp 
// int fun(int i, int sum) {
//   if(sum > x) return INF;
//   if(i == n + 1) {
//     if(sum == x) return 0;
//     return INF;
//   }
//   int &ans = dp[i][sum];
//   if(ans != -1) return ans;
//   ans = fun(i + 1, sum);
//   ans = min(ans, 1 + fun(i, sum + a[i]));
//   return ans;
// }
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n >> x;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  // memset(dp, -1, sizeof dp);
  // int ans = fun(1, 0);
  // cout << (ans >= INF ? -1 : ans) << endl;
 
  
  dp[0][0] = 0;
  for(int sum = 1; sum <= x; sum++){
    dp[0][sum] = INF;
  }
  for(int i = 1; i <= n; i++){
    for(int sum = 0; sum <= x; sum++){
      dp[i][sum] = dp[i - 1][sum];
      if(sum >= a[i]) dp[i][sum] = min(dp[i][sum], dp[i][sum - a[i]] + 1);
    }
  }
  cout << (dp[n][x] >= INF ? -1 : dp[n][x]) << "\n";
 
  return 0;
}