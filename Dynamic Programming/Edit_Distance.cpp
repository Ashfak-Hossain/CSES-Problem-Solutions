/**
 *    author:  _Berlin_
 *    created: 07.04.2024 04:19:35 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 5e3 + 9, inf = 1e9;
 
string n, m;
int length1, length2;
int dp[N][N];
 
int distance(int i, int j) {
  if(i >= length1) {
    if(j >= length2) {
      return 0;
    }
    return length2 - j;
  }
  if(j == length2) {
    return length1 - i;
  }
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = inf;
  if(n[i] == m[j]) {
    ans = min(ans, distance(i + 1, j + 1));
  }
  ans = min(ans, 1 + distance(i + 1, j + 1));
  ans = min(ans, 1 + distance(i, j + 1));
  ans = min(ans, 1 + distance(i + 1, j));
  return ans;
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n >> m; 
  length1 = n.size();
  length2 = m.size();
  memset(dp, -1, sizeof dp);
  cout << distance(0, 0) << "\n";
 
  return 0;
}