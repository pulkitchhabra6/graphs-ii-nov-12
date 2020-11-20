#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)        substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)         cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vi> arr;
vector<set<vi> > rows, cols;
vector<vi> dp;

int sx, sy, ex, ey;

int get(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int &ans = dp[i][j];

    if (mp(i, j) == mp(ex, ey))
        return ans = 0;

    ans = -inf;

    auto it_row = rows[i].upper_bound(vi{arr[i][j], i, j});
    auto it_col = cols[j].upper_bound(vi{arr[i][j], i, j});

    if (it_row != rows[i].end())
    {
        vi v = (*it_row);

        if (get(v[1], v[2]) != -inf)
            ans = max(ans, get(v[1], v[2]) + 1);
    }

    if (it_col != cols[j].end())
    {
        vi v = (*it_col);

        if (get(v[1], v[2]) != -inf)
            ans = max(ans, get(v[1], v[2]) + 1);
    }

    return ans;
}

int32_t main()
{
    FIO;
    int n, m; cin >> n >> m;

    arr.assign(n, vi(m, 0));
    dp.assign(n, vi(m, -1));
    rows.resize(n), cols.resize(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];

            rows[i].insert({arr[i][j], i, j});
            cols[j].insert({arr[i][j], i, j});
        }

    cin >> sx >> sy >> ex >> ey;

    int ans = get(sx, sy) == -inf ? -1 : get(sx, sy);

    cout << ans << '\n';
    return 0;
}
