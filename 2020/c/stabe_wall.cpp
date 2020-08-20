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
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
set<int> adj[N];
int a[N], in[N], vis[N];
string s[N];
int main(){
    //FIO;
    int t;cin >>t;
    fr(zz, 1, t){
        int r, c; cin>>r>>c;
        set<int> tot;
        fr(i, 0, r-1) {
            cin >>s[i];
            for(auto u: s[i]) tot.insert(u);
        }
        fr(i, 65, 65+25) {
            adj[i].clear();
            in[i]=0;
            vis[i]=0;
        }
        fr(i, 1, r-1){
            fr(j, 0, c-1){
                if (s[i][j] != s[i-1][j]){
                    if (adj[s[i][j]].find(s[i-1][j])==adj[s[i][j]].end()){
                        adj[s[i][j]].insert(s[i-1][j]);
                        in[s[i-1][j]]++;
                    }
                }
                tot.insert(s[i][j]);
                tot.insert(s[i-1][j]);
            }
        }
        queue<int> q;
        string ans="";
        for(auto i: tot){
            if (!in[i]) {
                q.push(i);
            }
        }
        while(q.size()){
            int u = q.front();
            ans += (char) u;
            q.pop();
            vis[u]=1;
            for(auto v: adj[u]) if (!vis[v]){
                in[v]--;
                if (!in[v]) q.push(v);
            }
        }
        int flag=0;
        for(auto i: tot) if (in[i]) flag=1;
        cout<<"Case #"<<zz<<": ";
        if (flag){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}

