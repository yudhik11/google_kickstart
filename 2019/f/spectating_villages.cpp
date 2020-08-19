#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define lsc(x)      scanf("%lld",&x)
#define sc(x)       scanf("%d",&x)
#define lpr(x)      printf("%lld ",x)
#define pr(x)       printf("%d ",x)
#define n_l         printf("\n")
#define VI          vector<int>
#define VII         vector<long long int>
#define MI          map<int, int>
#define PI          pair<int, int>
#define m_p         make_pair
#define pb          push_back
#define fi           first
#define se           second
#define mset(x,y)   memset(x,y,sizeof(x))
#define sz(v)       (int)v.size()
#define all(v)      v.begin(), v.end()
#define fr(i, a, n) for(int i=a;i<=n;i++)
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
const int N=(int)1e6+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
VI adj[N];
int a[N];
ll dp[N][3];
//dp[i][0] -> no illumination
//dp[i][1] -> illumination, not itself
//dp[i][2] -> illumination, on
void dfs(int u, int par=-1){
    dp[u][0] = dp[u][2] = 0;
    dp[u][1] = -1e18;
    for(auto v: adj[u]){
        if (v!=par){
            dfs(v, u);
            dp[u][2] = dp[u][2] + max(dp[v][0] + a[v], max(dp[v][1], dp[v][2]));
            dp[u][1] = max(dp[u][1] + max(dp[v][0], max(dp[v][1], dp[v][2])), //This takes any charc.of child
                    dp[u][0] + dp[v][2]);// This ensures atleast one glows and any one can glow.
            dp[u][0] = dp[u][0] + max(dp[v][0], dp[v][1]);

        }
    }
    dp[u][1] += a[u];
    dp[u][2] += a[u];
    // trace(u, dp[u][0], dp[u][1], dp[u][2]);
}
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        int n;sc(n);
        fr(i, 1, n) sc(a[i]), adj[i].clear();
        fr(i, 1, n-1){
            int u, v;
            sc(u);sc(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        cout<<"Case #"<<zz<<": "<<max(dp[1][0], max(dp[1][1], dp[1][2]))<<endl;
    }
    return 0;
}

