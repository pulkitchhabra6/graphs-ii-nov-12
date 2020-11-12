#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MX              200005
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vi adj[5001];
pii edg[5001];
int visit[5001];

int n,m;

bool checkCycle(int i)
{
  visit[i]=1;

  for(auto el : adj[i])
    if(visit[el]==1)
      return 1;
    else if(visit[el]==0 && checkCycle(el))
      return 1;

  visit[i]=2;
  
  return 0;
}

int32_t main()
{
    c_p_c();
    cin>>n>>m;

    for(int i=0;i<m;++i)
    {
      cin>>edg[i].ff>>edg[i].ss;

      adj[edg[i].ff].pb(edg[i].ss);
    }

    bool cycle=0;

    for(int i=1;i<=n;++i)
      if(!visit[i])
        cycle |= checkCycle(i);

    if(!cycle)
    {
      cout<<1<<'\n';
      for(int i=1;i<=m;++i)
        cout<<1<<' ';
      cout<<'\n';
    }
    else
    {
      cout<<2<<'\n';
      for(int i=0;i<m;++i)
      {
        if(edg[i].ff<edg[i].ss)
          cout<<1<<' ';
        else
          cout<<2<<' ';
      }
      cout<<'\n';
    }

    return 0;
}
