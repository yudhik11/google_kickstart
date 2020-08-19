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
const int N=(int)2e6+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll a[N], b[N], dp[N];
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        int n;
        ll h;
        sc(n);lsc(h);
        fr(i, 1, n) lsc(a[i]);
        fr(i, 1, n) lsc(b[i]);

        fr(i, 0, (1<<n)) dp[i] = 0;
        fr(i, 0, (1<<n) -1){
            ll tot = 0;
            fr(j, 0, n-1){
                if (!((1<<j) & i)) tot += a[j+1];
            }
            if (tot>=h) {
                dp[i]=1;
            }
        }

        fr(i, 0, n-1){
            fr(j, 0, (1<<n)-1){
                if ((1<<i) &j){
                    dp[j] += dp[j^(1<<i)];
                }
            }
        }
        ll ans =0;
        ll mask = (1<<n) -1;
        fr(i, 0, (1<<n) -1){
            ll tot = 0;
            fr(j, 0, n-1){
                if ((1<<j) & i) tot += b[j+1];
            }
            if (tot>=h) ans += dp[i];
        }

        printf("Case #%d: %lld\n", zz, ans);
    }
    return 0;
}