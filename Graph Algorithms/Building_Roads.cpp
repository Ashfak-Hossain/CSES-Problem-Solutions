/**
 *    author:  _Berlin_
 *    created: 15.12.2024 02:42:01 PM
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 1e5 + 9;
 
vector<int> g[N];
bool vis[N];
auto dfs = [] (auto& self, int u) -> void {
  vis[u] = true;
  for(auto v : g[u]) {
    if(!vis[v]) {
      self(self,v);
    }
  }
};
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> components; 
  for(int u = 1; u <= n; u++) {
    if(!vis[u]) {
      components.push_back(u);
      dfs(dfs, u);
    }
  }
  cout << components.size() - 1 << "\n";
  for(int i = 0; i + 1 < (int)components.size(); i++) {
    cout << components[i] << " " << components[i + 1] << "\n";
  }
 
  return 0;
}