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

class union_find
{
public:
	int *pr;
	int *sz;

	union_find(int n)
	{
		pr = new int[n + 1];
		sz = new int[n + 1];

		for (int i = 1; i <= n; ++i)
			pr[i] = i, sz[i] = 1;
	}

	int root(int i)
	{
		if (pr[i] == i)
			return i;

		return pr[i] = root(pr[pr[i]]);
	}

	int find(int i, int j)
	{
		return (root(i) == root(j));
	}

	int un(int i, int j)
	{
		int u = root(i);
		int v = root(j);

		if (u == v)
			return 0;

		if (sz[u] < sz[v])
			swap(u, v);

		pr[v] = u;
		sz[u] += sz[v];

		return 1;
	}
}; //default indexing is 1-based


int32_t main()
{
	FIO;
	int n, m; cin >> n >> m; // m >= n-1

	vector<vi> edges(m);

	for (int i = 0; i < m; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		edges[i] = {w, u, v};
	}

	sort(edges.begin(), edges.end());
	set<vi> mst;
	int min_cost = 0;

	union_find dsu(n); // everyone is in a different component of its own

	for (auto &e : edges)
	{
		if (mst.size() == n - 1)
			break;

		int u = e[1], v = e[2];

		if (!dsu.find(u, v))
		{
			mst.insert(e);
			dsu.un(u, v);
			min_cost += e[0];
		}
	}

	cout << min_cost << '\n';

	for (auto e : mst)
	{
		cout << e[1] << ' ' << e[2] << '\n';
	}
	return 0;
}
