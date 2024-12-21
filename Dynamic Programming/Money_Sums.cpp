/**
 *    author:  _Berlin_
 *    created: 20.12.2024 11:33:06 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 105;
const int MAX_SUM = 1e5 + 5;
 
bool dp[N][MAX_SUM];
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n;
  cin >> n;
  vector<int> coins(n);
  int totalSum = 0;
  for(auto &i : coins) {
    cin >> i;
    totalSum += i;
  }
 
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  
  for(int i = 1; i <= n; i++) {
    for(int currSum = 0; currSum <= totalSum; currSum++) {
      dp[i][currSum] = dp[i - 1][currSum];
      int prev_sum = currSum - coins[i - 1];
      if(prev_sum >= 0 && dp[i - 1][prev_sum]) {
        dp[i][currSum] = true;
      }
    }
  }
 
  vector<int> possible;
  for(int i = 1; i <= totalSum; i++) {
    if(dp[n][i]) {
      debug(i);
      possible.push_back(i);
    }
  }
 
  cout << (int)possible.size() << "\n";
  for(auto &i : possible)  cout << i << " ";
  cout << "\n";
 
  return 0;
}