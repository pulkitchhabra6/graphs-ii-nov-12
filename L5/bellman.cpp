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
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, m;
vector<vi> edges;

vi bellman_ford(int src)
{
	vi d(n + 1, inf);
	d[src] = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		//vi old_d = d;
		for (vi edg : edges)
		{
			int u = edg[0], v = edg[1], w = edg[2];
			d[v] = min(d[v], d[u] + w);
		}

		/*if(old_d == d)
			break;*/
	}

	return d;
}

bool detect_neg_cycle_affecting_dist_from_src(int src)
{
	vi d(n + 1, inf);
	d[src] = 0;

	for (int i = 0; i < n; ++i)
	{
		//vi old_d = d;
		for (vi edg : edges)
		{
			int u = edg[0], v = edg[1], w = edg[2];

			if (i < n - 1)
				d[v] = min(d[v], d[u] + w);

			else if (d[u] + w < d[v])
				return true;

		}

		/*if(old_d == d)
			break;*/
	}

	return false;
}

int32_t main()
{
	FIO;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		edges.pb({u, v, w});

		//if undirected
		//edges.pb({v,u,w});
	}

	vi d = bellman_ford(1);
	return 0;
}
