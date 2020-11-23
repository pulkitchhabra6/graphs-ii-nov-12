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
vector<vector<pii> > adj;

vi dijkstra(int src)
{
	vi d(n + 1, inf), par(n + 1);
	set<pii> s; //first->d, second->node

	d[src] = 0;
	s.insert({0, src});

	while (!s.empty())
	{
		auto it = s.begin();
		int u = it->ss;

		s.erase(it);

		for (pii e : adj[u])
		{
			int nb = e.ff, w = e.ss;

			if (d[u] + w < d[nb])
			{
				s.erase({d[nb], nb});
				d[nb] = d[u] + w;
				par[nb] = u;
				s.insert({d[nb], nb});
			}
		}
	}

	return d;
}

vi multi_dijkstra(vi sources)
{
	vi d(n + 1, inf), par(n + 1);
	set<pii> s; //first->d, second->node

	for (int src : sources)
	{
		d[src] = 0;
		s.insert({0, src});
	}

	while (!s.empty())
	{
		auto it = s.begin();
		int u = it->ss;

		s.erase(it);

		for (pii e : adj[u])
		{
			int nb = e.ff, w = e.ss;

			if (d[u] + w < d[nb])
			{
				s.erase({d[nb], nb});
				d[nb] = d[u] + w;
				par[nb] = u;
				s.insert({d[nb], nb});
			}
		}
	}

	return d;
}

int32_t main()
{
	FIO;
	cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j, w; cin >> i >> j >> w;
		adj[i].pb({j, w});
		adj[j].pb({i, w});
	}

	vi d = dijkstra(1);

	for (int i = 1; i <= n; ++i)
		cout << i << ' ' << d[i] << '\n';

	return 0;
}
