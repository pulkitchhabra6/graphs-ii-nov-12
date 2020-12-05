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

int n, m, k;
vector<vi> edges;
mii nodes;

int32_t main()
{
	FIO;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		edges.pb({w, u, v});
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < min(m, k); ++i)
	{
		nodes[edges[i][1]] = 1;
		nodes[edges[i][2]] = 1;
	}

	//nodes.size() <= 800
	int new_val = 1;

	for (auto &p : nodes)
		p.ss = (new_val++);
	
	n = nodes.size();

	vector<vi> d(n + 1, vi(n + 1, inf));

	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;

	for (int i = 0; i < min(m, k); ++i)
	{
		int u = nodes[edges[i][1]], v = nodes[edges[i][2]], w = edges[i][0];
		d[u][v] = d[v][u] = w;
	}

	//Normal Floyd Warshall
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	vector<int> paths;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			paths.pb(d[i][j]);

	sort(paths.begin(), paths.end());

	cout << paths[k - 1] << '\n';

	return 0;
}
