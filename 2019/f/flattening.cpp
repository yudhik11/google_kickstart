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
ll fmod(ll x){
	if (x<mod) return mod;
	return x%mod;
}
int modpow(ll a, ll b){
    ll ret=1;
    while(b){
        if (b%2) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return (int)ret;
}
inline int inv(int x){ return modpow(x, mod-2);}
int dp[101][101][1001], mn[1001][1001];
int a[N];
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        int n;sc(n);
        int k;sc(k);
        fr(i, 1, n) sc(a[i]);
        mset(dp, 0);
        mset(mn, 0);
        fr(i, 1, 1000) dp[1][0][i]=1;
        dp[1][0][a[1]]=0;
        //fr(i, 1, k)
            //fr(j, 1, 1000) dp[1][i][j] = -1;
        fr(i, 2, n) {
            fr(z, 0, min(k, i)){
                fr(j, 1, 1000){
                    //if (dp[i-1][z][j] !=-1)
                    dp[i][z][j] = dp[i-1][z][j] + (j!=a[i]);
                    //else dp[i][z][j] = dp[i-1][z][j] + (j!=a[i]);
                    if (z) dp[i][z][j] = min(dp[i][z][j], mn[i-1][z-1] + (j!=a[i]));
                }
            }
            fr(z, 0, min(k, i)){
                mn[i][z]=mod;
                fr(j, 1, 1000)
                    mn[i][z] = min(mn[i][z], dp[i][z][j]);
            }
        }
        int ans=mod;
        /*fr(i, 1, n)
            fr(z, 0, k){
                trace(i, z);
                fr(j, 1, 1000) trace(j, dp[i][z][j]);
            }
        */fr(i, 1, 1000) ans = min(ans, dp[n][k][i]);
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
    return 0;
}

