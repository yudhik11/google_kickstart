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
const int N=(int)1e6+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll a[N];
ll BIT[2][N];
void insert(int idx, ll val, int flag=0){
    while(idx < N){
        BIT[flag][idx] += val;
        idx += ((idx)&(-idx));
    }
}
ll query(int idx, int flag = 0){
    ll ret = 0;
    while(idx){
        ret += BIT[flag][idx];
        idx -= ((idx)&(-idx));
    }
    return ret;
}
int main(){
    int t;cin>>t;
    fr(zz, 1, t){
        int n, q;
        sc(n);sc(q);
        fr(i, 1, 2*n) BIT[0][i] = BIT[1][i] = 0;
        fr(i, 1, n){
            lsc(a[i]);
            ll x = a[i];
            if (i%2 == 0) x = -x;
            insert(i, x, 1);
            insert(i, i*x);
        }
        ll fans = 0;
        while(q--){
            char c;scanf("\n%c",&c);
            int l, r;sc(l);sc(r);
            if (c == 'Q'){
                ll ans = (query(r) - query(l-1)) \
                        - (l-1)*(query(r, 1) - query(l-1, 1));
                // trace(ans);
                if (l%2) fans += ans;
                else fans -= ans;
            }
            else{
                ll x = r - a[l];
                if (l%2 == 0) x = -x;
                insert(l, x, 1);
                insert(l, l*x);
                a[l] = r;
            }
            // trace(fans);
        }

        printf("Case #%d: ", zz);
        lpr(fans);n_l;
    }
    return 0;
}

