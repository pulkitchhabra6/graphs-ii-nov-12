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

int n;
int d[505][505];

int32_t main()
{
	FIO;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> d[i][j];

	vi x(n);

	for (int i = 0; i < n; ++i)
		cin >> x[i];

	reverse(x.begin(), x.end()); //x[n-1], x[n-2] .... x[0]

	vector<int> answers;

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				int node = x[k - 1];
				d[i][j] = min(d[i][j], d[i][node] + d[node][j]);
			}

		int ans = 0;

		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				ans += d[x[i]][x[j]];

		answers.pb(ans);
	}

	reverse(answers.begin(), answers.end());

	for (int i : answers)
		cout << i << ' ';

	return 0;
}
