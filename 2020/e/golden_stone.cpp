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
const int N= 305;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll fmod(ll x){if (x<mod) return x;return x%mod;}
ll mul(ll a, ll b, ll c){
    ll ret=0;while(b){if (b%2) ret=(ret+a)%c;a=(a*2)%c;b>>=1;}
    return ret;
}
int modpow(ll a, ll b){
    ll ret=1;while(b){if (b%2) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;}
    return (int)ret;
}
inline int inv(int x){ return modpow(x, mod-2);}
int isprime[N];
void calc_prime(){
    isprime[1]=1;for(ll i=2;i<N;i++) if (!isprime[i]) for(ll j=i*i;j<N;j+=i) isprime[j]=1;
}
#define pii pair<int, int>
set<pair<ll, pii> >s;
VI adj[N], rec[N];
ll dis[N][N];
int ot[N];
ll solve(){
    int n, m, S, r;
    sc(n);sc(m);sc(S);sc(r);
    ////////////////clear/////////////
    fr(i, 1, n){
        adj[i].clear();
        fr(j, 1, S) dis[i][j] = 1e12;
    }
    fr(i, 1, r) rec[i].clear();
    s.clear();
    /////////////
    fr(i, 1, m){
        int u, v;sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fr(i, 1, n){
        int k;sc(k);
        while(k--){
            int c;sc(c);
            dis[i][c] = 0;
            s.insert({0, {i, c}});
        }
    }
    fr(i, 1, r){
        int k;sc(k);
        while(k--){
            int c;sc(c);
            rec[i].pb(c);
        }
        sc(ot[i]);
    }
    while(s.size()){
        auto ppp = *s.begin();
        int stone = ppp.se.se;
        int u = ppp.se.fi;
        s.erase(ppp);
        //trace(ppp.fi, u, stone, dis[u][stone]);
        if (ppp.fi > dis[u][stone]) continue;
        for(auto v: adj[u]){
            if (ppp.fi+1LL<dis[v][stone]){
                dis[v][stone] = 1LL+ppp.fi;
                s.insert({dis[v][stone], {v, stone}});
            }
        }
        fr(i, 1, r){
            int fl=0;
            for(auto c: rec[i]) if (c==stone) fl=1;
            if (!fl) continue;
            ll tmp=0;
            for(auto c: rec[i]) tmp += dis[u][c];
            //trace(ot[i], tmp);
            if (tmp<dis[u][ot[i]]){
                dis[u][ot[i]] = tmp;
                s.insert({tmp, {u, ot[i]}});
            }
        }
    }
    ll ans = 1e12;
    fr(i, 1, n) ans = min(ans, dis[i][1]);
    return ans;
}
int main(){
    int t;
    sc(t);
    fr(zz, 1, t){
        ll ans = solve();
        printf("Case #%d: %lld\n",zz, ans==1e12?-1:ans);
    }
    return 0;
}
