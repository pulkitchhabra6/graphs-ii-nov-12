//https://www.codechef.com/ICL2016/problems/ICL16A

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
#define inf             1e9
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

int prim()
{
	int ans = 0;

	vi minEdge(n + 1, inf), inc(n + 1);

	set<pii> s; //{min_w,u}
	s.insert({0, 1});
	minEdge[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (s.empty())
			return -1;

		auto it = s.begin();
		int u = it->second;

		s.erase(it);

		inc[u] = 1;
		ans = max(ans, minEdge[u]);

		for (auto &e : adj[u])
		{
			int v = e.first, w = e.second;

			if (inc[v])
				continue;

			if (w < minEdge[v])
			{
				s.erase({minEdge[v], v});
				minEdge[v] = w;
				s.insert({minEdge[v], v});
			}
		}
	}

	return ans;
}

int32_t main()
{
	FIO;
	cin >> n >> m;
	adj.resize(n + 1);
	vector<string> arr(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;

			int mx = 0;
			for (int k = 0; k < m; ++k)
				mx = max(mx, (int)abs(arr[i][k] - arr[j][k]));

			adj[i].pb({j, mx});
		}

	cout << prim() << '\n';
	return 0;
}
