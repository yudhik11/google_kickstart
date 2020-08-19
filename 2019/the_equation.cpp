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
#define lpr(x)      printf("%lld ",x)
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
const int N=(int)1e2+5;
const int mod = 1000000007;
typedef unsigned long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll ones[55];
ll flag[55];
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        ll n;lsc(n);
        long long m;lsc(m);
        ll sum=0;
        mset(ones, 0);
        mset(flag, 0);
        fr(i, 1, n){
        	ll x;lsc(x);
        	int cnt = 0;
        	sum +=x;
        	while(x){
        		if (x%2) ones[cnt]++;
        		cnt++;
        		x/=2;
        	}
        }
        m-=sum;
        ll k = 0;
        for(ll i=0;i<51;i++) {
        	if (2*ones[i] >= n) {
        		k += 1LL<<i;
        		m += (2LL* ones[i] - n) * (1LL << i);
        		ones[i] = n-ones[i];
        		// trace(i, ones[i], m, k);
        		flag[i]=1;
        	}
        }
        // trace(m, k);
        if (m<0)
        	k = -1;
        else{
	        for(long long i=51;i>=0;i--){
	        	ll add = (1LL<<i) * (ll)(n-2LL*ones[i]);
	        	if (!flag[i] and add <= m){
	        		m-=add;
	        		k+=(1LL<<i);
	        		// trace(i, add, m, k);
	        	}
	        }
	    }
        printf("Case #%d: %lld\n", zz, k);
    }
    return 0;
}