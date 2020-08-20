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
const int N=(int)1e6+5;
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define pii pair<int, int>
map<pii, pii> go[4];
map<pii, int> vis;
pii find(int x, int y, int d) {
    pii tmp = m_p(x, y);
    if (vis.find(tmp) == vis.end()) {
        return tmp;
    }
    if (go[d].find(tmp) == go[d].end()) {
        go[d][tmp] = m_p(x + dx[d], y + dy[d]);
    }
    go[d][tmp] = find(go[d][tmp].first, go[d][tmp].second, d);
    return go[d][tmp];
}
int main() {
    map<char, int> mp1{{'N', 3}, {'W', 2}, {'S', 1}, {'E', 0}};
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        vis.clear();
        for (int j = 0; j < 4; ++j) go[j].clear();
        int k, n, m, sr, sc;
        cin >> k >> n >> m >> sr >> sc;
        vis[m_p(sr, sc)] = 1;
        string s;
        cin >> s;
        for (auto c : s) {
            int dir = mp1[c];
            auto res = find(sr, sc, dir);
            sr = res.first;
            sc = res.second;
            vis[m_p(sr, sc)] = 1;
            // for(int j=0;j<4;j++){
            //     cout<<j<<endl;
            //     for(auto it: go[j])
            //         cout<<it.fi.fi<<" "<<it.fi.se<<" "<<it.se.fi<<" "<<it.se.se<<endl;
            // }
        }
        cout << sr << ' ' << sc << '\n';
        
    }   
}