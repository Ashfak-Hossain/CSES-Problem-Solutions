/**
 *        Bismillahir Rahmanir Rahim
 *        Author:  Ashfak Hossain Evan, American International University, Bangladesh
 *        Created: 28/12/2023 09:18:35
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll fib(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}