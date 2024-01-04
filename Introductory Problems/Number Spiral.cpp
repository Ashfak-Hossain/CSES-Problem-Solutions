/**
 *        Bismillahir Rahmanir Rahim
 *        Author:  Ashfak Hossain Evan, American International University, Bangladesh
 *        Created: 04/01/2024 13:21:58
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll x, y;

        cin >> y >> x;

        ll mx = max(x, y);

        ll square = (mx - 1) * (mx - 1);

        if (mx & 1)
        {
            if (x > y)
                cout << (mx * mx) - y + 1 << endl;
            else
                cout << square + x << endl;
        }
        else
        {
            if (x > y)
                cout << square + y << endl;
            else
                cout << (mx * mx) - x + 1 << endl;
        }
    }

    return 0;
}