/**
 *    author:  _Berlin_
 *    created: 28.11.2024 03:53:03 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e5 + 9;

using i64 = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<i64> v(n);

  for(auto &i : v) {
    cin >> i;
  }

  i64 lo = *max_element(begin(v), end(v));
  i64 hi = accumulate(begin(v), end(v), 0LL);

  auto check = [&] (i64 mid) -> bool {
    i64 curr_sum = 0, sub_arr_count = 0;
    for(auto &i : v) {
      if(i > mid) return false;
      if(curr_sum + i > mid) {
        sub_arr_count++;
        curr_sum = 0;
      }
      curr_sum += i;
    }
    if(curr_sum > 0) {
      sub_arr_count++;
    }
    return sub_arr_count <= k;
  };

  while(lo < hi) {
    i64 mid = lo + ((hi - lo) >> 1);
    check(mid) ? (hi = mid) : (lo = mid + 1);
  }
  cout << lo << "\n";


  return 0;
}


/* Time Complexity:
    Binary Search: O(n * log(n))
    Space Complexity: O(n)
*/
