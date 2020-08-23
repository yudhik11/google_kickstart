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

// 12 10 8 16 15
// 15 16 8 10 12
// 13 18 17 19 18 16 21 20 22 24
int dp[305][305];
int a[305][305];
void solve(int I, int n, int k){
    set<pair<int, int> > s;
    int ptrl = 0;
    auto &ans = dp[I];
    fr(i,1,n){
        int x = a[I][i];
        while(s.size()){
            auto pp = *s.begin();
            if (abs(pp.fi - x) > k){
                ptrl = max(ptrl, pp.se);
                s.erase(s.begin());
            }
            else break;
        }
        while(s.size()){
            auto pp = *s.rbegin();
            if (abs(pp.fi - x) > k){
                ptrl = max(ptrl, pp.se);
                s.erase((--s.end()));
            }
            else break;
        }
        if (!ans[ptrl]) ans[ptrl] = i;
        s.insert({x, i});
    }
    int lst = n+1;
    for(int i=n;i;i--){
        if (ans[i]) lst = ans[i];
        ans[i] = lst-i;
    }
}
int max_area(int C, int n){
	VI l(n+1), r(n+1);
	int tmp[n+1] = {0};
	int ptrl = 0;
	fr(i, 1, n){
		while (ptrl and dp[tmp[ptrl]][C] >= dp[i][C]){
			ptrl--;
		}
		l[i] = tmp[ptrl];
		tmp[++ptrl] = i;
		// trace(i, ptrl, l[i]);
		// fr(j, 1, ptrl) pr(tmp[j]);n_l;
	}
	ptrl=0;
	tmp[0] = n+1;
	for(int i=n;i;i--){
		while (ptrl and dp[tmp[ptrl]][C] >= dp[i][C]){
			ptrl--;
		}
		r[i] = tmp[ptrl];
		tmp[++ptrl] = i;
	}
	int ans = 0;
	fr(i, 1, n){
		ans = max(ans, (r[i]- l[i]-1)*dp[i][C]);
	}
	return ans;
}
int main(){
	FIO;
    int t;cin >>t;
    fr(zz, 1, t){
        int r, c, k;
        cin>>r>>c>>k;
        fr(i, 1, r) fr(j, 1, c) {
        	cin>>a[i][j];
        	dp[i][j] = 0;
        }
        fr(i, 1, r) solve(i, c, k);
        // fr(i, 1, r){
        //     fr(j, 1, c) pr(dp[i][j]);n_l;
        // }
        int ans = 0;
        fr(i, 1, c){
        	ans = max(ans, max_area(i, r));
        	// trace(ans);
        }
        cout<<"Case #"<<zz<<": "<<ans<<"\n";
    }
}
