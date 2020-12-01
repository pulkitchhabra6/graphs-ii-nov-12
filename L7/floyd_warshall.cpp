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
#define inf             1e15
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n;
vector<vector<pii> > adj;

vector<vi> floyd_warshall()
{
	vector<vi> d(n + 1, vi(n + 1, inf));

	for (int i = 1; i <= n; ++i)
	{
		d[i][i] = 0;

		for (auto e : adj[i])
		{
			int j = e.ff, w = e.ss;

			d[i][j] = min(d[i][j], w);
		}
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (d[i][k] < inf and d[k][j] < inf)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	return d;
}

int32_t main()
{
	FIO;
	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j, w; cin >> i >> j >> w;
		adj[i].pb({j, w});

		//For undirected
		//adj[j].pb({i,w})
	}

	vector<vi> d = floyd_warshall();

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cout << i << ' ' << j << '\t' << d[i][j] << '\n';

	return 0;
}
