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
vector<vi> adj, rev, edges;
vi a, old_to_new;

void dfs(int i, vi &vis, vi &vals)
{
	vis[i] = 1;

	for (int j : adj[i])
		if (!vis[j])
			dfs(j, vis, vals);

	vals.pb(i);
}

void dfs_rev(int i, vi &vis, vi &vals)
{
	vis[i] = 1;

	for (int j : rev[i])
		if (!vis[j])
			dfs_rev(j, vis, vals);

	vals.pb(i);
}

int condensation()
{
	vi vis(n + 1), vals;

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs(i, vis, vals);

	reverse(vals.begin(), vals.end());
	vis.assign(n + 1, 0);
	int scc = 1;

	old_to_new.resize(n + 1);

	for (int i : vals)
	{
		if (vis[i])
			continue;

		vi tmp;
		dfs_rev(i, vis, tmp);
		for (int j : tmp)
			old_to_new[j] = scc;
		scc++;
	}

	adj.clear();
	adj.resize(scc);

	for (vi e : edges)
	{
		if (old_to_new[e[0]] != old_to_new[e[1]])
			adj[old_to_new[e[0]]].pb(old_to_new[e[1]]);
	}

	return scc - 1;
}

mii dp;
vi arr;

int dfs_dag(int i)
{
	if (dp.count(i))
		return dp[i];

	for (int j : adj[i])
		dp[i] = max(dp[i], dfs_dag(j));

	return dp[i] += arr[i];
}

int32_t main()
{
	FIO;
	cin >> n >> m;
	a.resize(n + 1), adj.resize(n + 1), rev.resize(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].pb(j);
		edges.pb({i, j});
		rev[j].pb(i);
	}

	int n2 = condensation();
	arr.resize(n2 + 1);

	for (int i = 1; i <= n; ++i)
		arr[old_to_new[i]] += a[i];

	for (int i = 1; i <= n; ++i)
		cout << dfs_dag(old_to_new[i]) << ' ';
	return 0;
}
