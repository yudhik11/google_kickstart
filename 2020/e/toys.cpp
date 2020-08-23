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
int e[N], r[N], flag[N];
ll pref[N];
pair<ll, int> solve(){
    int n;sc(n);
    ll tot = 0;
    fr(i, 1, n) {
    	flag[i]=0;
        sc(e[i]);sc(r[i]);
        tot += e[i];
        pref[i] = pref[i-1] + e[i];
    }
    ll ans = tot;
    ll sub = 0;
    set<int>sidx;
    set<pair<ll, int> >s;
    map<int, ll> mp;
    int rem =0;
    fr(i, 1, n){
        mp[i] = tot - e[i] - r[i];
        s.insert({tot - e[i] - r[i], i});
        if (tot - e[i] - r[i] < 0){
        	sidx.insert(i);
        	flag[i] = 1;
        }
    }
    // for(auto u: mp) trace(u.fi, u.se);
    int remans = 0;
    while(sidx.size()){
        auto idx =  (*sidx.begin());
        // trace(idx, mp[idx], sub);
        if (mp[idx] - sub >= 0){
            break;
        }
        rem++;
        sidx.erase(idx);
        sub += e[idx];

        while(s.size()){
        	auto pp = *s.begin();
        	// trace(pp.fi, pp.se);
        	if (pp.fi - sub < 0){
        		s.erase(pp);
        		if (!flag[pp.se]){
        			sidx.insert(pp.se);
        			flag[pp.se]=1;
        		}
        	}
        	else break;
        }
        // trace(idx);
        ll subans = tot - sub - sub + (ll)e[idx] + pref[idx];
        if (subans > ans){
        	ans = subans;
	        // trace(ans, rem, idx);
			remans = rem-1;        	
        }
        //trace(s.size());
        //for(auto it: s) trace(it.fi, it.se);
    }
    // trace(s.size(), ans);
    if (s.size()) return m_p(1e18, rem);
    else return m_p(ans, remans);
}
int main(){
    int t;
    sc(t);
    fr(zz, 1, t){
        pair<ll, int> ans = solve();
        printf("Case #%d: ",zz);
        if (ans.fi == 1e18){
            printf("%d INDEFINITELY\n", ans.se);
        }else{
            pr(ans.se);lpr(ans.fi);n_l;
        }
        //cout<<"Case #"<<zz<<": "<<ans<<"\n";
    }
    return 0;
}
