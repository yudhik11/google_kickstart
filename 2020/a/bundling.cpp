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
int cnt=0;
int tot[N*2];
int to[2*N][26];
set<int> s[2*N];
void inserts(string S){
    int node = 0;
    tot[node]++;
    for(auto c: S){
        // trace(c);
        if (to[node][c+1-'A']){
            node = to[node][c+1-'A'];
            tot[node]++;
        }
        else{
            cnt++;
            to[node][c+1-'A'] = cnt;
            s[node].insert(c+1-'A');
            node = to[node][c+1-'A'];
            tot[node]++;
        }
    }
}
int ans, k;
int dfs(int u, int el=0, int p=0, int d=0){
    int sub =0;
    for(auto el: s[u]){
        int pre = to[u][el];
        to[u][el] = 0;
        sub += dfs(pre, el, u, d+1);
    }
    tot[u] -= sub;
    ans += d*(tot[u]/k);
    sub += (tot[u]/k)*k;
    // trace(ans, d, tot[u], tot[p], (char)(el-1+'A'));
    return sub;
}
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        int n;sc(n);sc(k);
        ans = 0;
        fr(i, 1, n){
            string s;cin >>s;
            inserts(s);
        }
        dfs(0);
        printf("Case #%d: ", zz);
        pr(ans);n_l;
        fr(i, 0, cnt) {
            s[i].clear();
            tot[i]=0;
        }
    }
    return 0;
}

