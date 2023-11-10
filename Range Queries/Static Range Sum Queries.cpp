/**
 *        Bismillahir Rahmanir Rahim
 *        Author:  Ashfak Hossain Evan, American International University, Bangladesh
 *        Created: 28/09/2023 10:30:12
 **/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define char2Int(c) (c - '0')
#define lastEle(vec) vec[vec.size() - 1]
#define PI 3.1415926535897932384626433832795l
#define endl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll v[MAX_N], prefix_sum[MAX_N];

void solve()
{

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    debug(v);
    debug(prefix_sum);

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b] - prefix_sum[a - 1] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}