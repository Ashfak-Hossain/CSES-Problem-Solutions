/**
 *        Bismillahir Rahmanir Rahim
 *        Author:  Ashfak Hossain Evan, American International University, Bangladesh
 *        Created: 27/12/2023 13:31:59
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (auto &&i : v)
        cin >> i;

    map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        if (mp.find(x - v[i]) != mp.end())
        {
            cout << i + 1 << " " << mp[x - v[i]] << endl;
            return 0;
        }
        mp[v[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}