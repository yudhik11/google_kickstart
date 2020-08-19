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
map<string, int> mp;
int main(){
    int t;
    sc(t);
    fr(zz, 1, t){
        int n, s;sc(n);sc(s);
        mp.clear();
        fr(i, 1, n) adj[i].clear();
        fr(i, 1, n){
            int mx;sc(mx);
            fr(j, 1, mx){
                int x;sc(x);
                adj[i].pb(x);
            }
        }
        fr(i, 1, n) sort(all(adj[i]));
        fr(i, 1, n){
            int x = adj[i][0];
            string tmp = to_string(x);
            for(int j=1;j<adj[i].size();j++){
                int x = adj[i][j];
                tmp +='$' + to_string(x);
            }
            mp[tmp]++;
        }
        ll ans=0;
        fr(i, 1, n){
            int sz = adj[i].size();
            ll tot=0;
            fr(j, 1, ((1<<sz)-1)){
                string tmp="";
                int f=0;
                fr(k,0,sz-1){
                    if ((1<<k)&j){
                        if (f) tmp+='$';
                        tmp += to_string(adj[i][k]);
                        f=1;
                    }
                }
                //trace(j, tmp, mp[tmp]);
                tot += mp[tmp];
            }
            ans += (n-tot);
        }
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
    return 0;
}

