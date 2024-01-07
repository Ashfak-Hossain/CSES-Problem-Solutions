#include <bits/stdc++.h>

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(x) ((long long)x.size())
#define char2Int(c) (c - '0')
#define lastEle(vec) vec[vec.size() - 1]
#define PI 3.1415926535897932384626433832795l
#define endl '\n'
#define startTime first
#define endTime second
#define pb push_back
#define range(i, v) for (auto &i : v)
#define fix(prec) cout << setprecision(prec) << fixed;
#define mem(arr, v) memset(arr, v, sizeof(arr))
#define getunique(v) \
    sort(all(v));    \
    v.erase(unique(all(v)), v.end());
#define Muichiro ios_base::sync_with_stdio(false);
#define Tokito cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int partition(vector<pair<long long, long long>> &movie, int left, int right)
{

    long long pivot = movie[right].first;

    int i = left - 1;

    for (int j = left; j < right; j++)
    {

        if (movie[j].first <= pivot)
        {

            i++;

            swap(movie[i], movie[j]);
        }
    }

    swap(movie[i + 1], movie[right]);

    return i + 1;
}

void quickSort(vector<pair<long long, long long>> &movie, int left, int right)
{

    if (left < right)
    {

        int pivotIndex = partition(movie, left, right);

        quickSort(movie, left, pivotIndex - 1);

        quickSort(movie, pivotIndex + 1, right);
    }
}

/*

End - Start

minimum EndTime is now 5

if any StartTime will grater or equal to 5 then new movie can watch or not...

And if any movie StartTime is less than previous Movie End Time ... then have skip the movie..

Sort the vector in EndTime

5   -   3
8   -   5
9   -   4

*/

void Free_Palestine()
{

    int totalMovies;
    cin >> totalMovies;

    vector<pair<long long, long long>> movie(totalMovies);

    for (int i = 0; i < totalMovies; ++i)
    {
        cin >> movie[i].endTime >> movie[i].startTime;
    }

    debug(movie.size());

    // quickSort(movie, 0, movie.size() - 1);

    sort(all(movie));

    int currentStartTime = movie[0].startTime;

    long long totalMovieCanWatch = 1;

    for (int i = 1; i < totalMovies; ++i)
    {
        if (movie[i].endTime >= currentStartTime)
        {
            currentStartTime = movie[i].startTime;

            totalMovieCanWatch++;
        }
    }

    debug(totalMovieCanWatch);

    cout << totalMovieCanWatch << endl;
}

int main()
{
    Muichiro Tokito

#ifdef BERLIN
        clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    Free_Palestine();

#ifdef BERLIN
    fprintf(stderr, "\nRuntime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif

    return 0;
}