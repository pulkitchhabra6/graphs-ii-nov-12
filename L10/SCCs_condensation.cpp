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
vector<vi> adj, rev, cg_adj;
vi scc_no;

void dfs(int i, vi &vis, vi &vals)
{
	vis[i] = 1;

	for (int j : adj[i])
		if (!vis[j])
			dfs(j, vis, vals);

	vals.pb(i); //nodes in increasing order of out time
}

void rev_dfs(int i, int num)
{
	scc_no[i] = num;

	for (int j : rev[i])
	{
		if (!scc_no[j])
			rev_dfs(j, num);
	}
}


int condensation_graph()
{
	vi vis(n + 1), vals;

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs(i, vis, vals);

	reverse(vals.begin(), vals.end());

	int num = 1;
	scc_no.assign(n + 1, 0);

	for (int i : vals)
	{
		if (!scc_no[i])
		{
			rev_dfs(i, num);
			num++;
		}
	}

	cg_adj.resize(num); //num = no_of_sccs + 1

	for (int i = 1; i <= n; ++i)
		for (int j : adj[i])
			if (scc_no[i] != scc_no[j])
				cg_adj[scc_no[i]].pb(scc_no[j]);

	return num - 1;
}

int32_t main()
{
	FIO;
	cin >> n >> m;
	adj.resize(n + 1), rev.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].pb(j);
		rev[j].pb(i);
	}

	int sccs = condensation_graph();

	for (int i = 1; i <= n; ++i)
		cout << i << ' ' << scc_no[i] << '\n';
	cout << '\n';

	for (int i = 1; i <= sccs; ++i)
		for (int j : cg_adj[i])
			cout << i << ' ' << j << '\n';

	return 0;
}
