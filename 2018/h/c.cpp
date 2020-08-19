#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

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

#define lsc(x)      scanf("%lld",&x)
#define sc(x)       scanf("%d",&x)
#define lpr(x)      printf("%lld ",(long long)x)
#define pr(x)       printf("%d ",x)
#define n_l         printf("\n")
#define VI          vector<int>
#define VII         vector<long long int>
#define m_p         make_pair
#define pb          push_back
#define fi           first
#define se           second
#define mset(x,y)   memset(x,y,sizeof(x))
#define sz(v)       (int)v.size()
#define all(v)      v.begin(), v.end()
#define fr(i, a, n) for(int i=a;i<=n;i++)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
const int N=(int)2e5+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll fmod(ll x){if (abs(x)<mod) return x;return x%mod;}
ll mul(ll a, ll b, ll c){
	ll ret=0;while(b){if (b%2) ret=(ret+a)%c;a=(a*2)%c;b>>=1;}
    return ret;
}
int modpow(ll a, ll b){
    ll ret=1;while(b){if (b%2) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;}
    return (int)ret;
}
inline int inv(int x){ return modpow(x, mod-2);}
ll fact[N], ifact[N], pw[N];
ll ncr(ll n, ll k){
    return fmod(fact[n] * fmod(ifact[k] * ifact[n-k]));
}
int main(){
    int t;sc(t);
    fact[0] = 1LL;
    fr(i, 1, N-1) fact[i] = fmod(fact[i-1]*(ll)i);
    fr(i, 0, N-1) ifact[i] = inv(fact[i]);
    pw[0]=1LL;
    fr(i, 1, N-1) pw[i] = fmod(pw[i-1]*2LL);
    fr(zz, 1, t){
        ll ans =0;
        ll n, m;lsc(n);lsc(m);
        ll flag = 1;
        fr(i, 0, m){
            ll g = fmod(fmod(ncr(n+n-i, i) * fact[i]) * fmod(pw[i] * fact[2*(n-i)]));
            ll tmp = fmod(fmod(flag * g * ncr(m, i)) + mod);
            //trace(g, tmp);
            flag-=2*flag;
            ans = fmod(ans + tmp);
        }
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
    return 0;
}

