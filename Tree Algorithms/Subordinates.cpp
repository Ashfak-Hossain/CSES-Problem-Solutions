/**
 *    author:  _Berlin_
 *    created: 15.12.2024 02:59:38 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 2e5 + 9;

vector<int> g[N];
int sub[N];
int dfs(int u) {
  int count = 0;
  for(auto &v : g[u]) {
    count += dfs(v) + 1;
  }
  sub[u] = count;
  return count;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int i = 2; i <= n; i++){
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  for(int i = 1; i <= n; i++) {
    cout << sub[i] << " \n"[i == n];
  }

  return 0;
}
