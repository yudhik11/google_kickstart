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
const int mod = (int)1e9;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
pair<ll, ll> solve(string s){
    // trace(s);
    ll x=0, y=0;
    ll rep=1;
    string tmp = "";
    int flag=0;
    for(int i=0;i<s.size();i++){
        if (!flag){
            if (s[i] >= '0' and s[i] <= '9'){
                rep = (int)(s[i]-48);
            }
            if (s[i] == 'N') y-=rep;
            if (s[i] == 'S') y+=rep;
            if (s[i] == 'E') x+=rep;
            if (s[i] == 'W') x-=rep;
            // trace(s[i], rep, flag, x, y);
        }
        if (s[i] == '('){
            flag=1;
            i++;
            while(flag){
                if (s[i] == ')') flag--;
                if (s[i] == '(') flag++;
                if (flag) {
                    tmp += s[i];
                    i++;
                }
            }
            auto pp = solve(tmp);
            x += rep*pp.fi;
            y += rep*pp.se + mod;
            x = (x+mod)%mod;
            y = (y+mod)%mod;
            // trace(pp.fi, pp.se, rep, tmp, x, y);
            rep = 1;
            tmp = "";
        }
    }
    x = (x+mod)%mod;
    y = (y+mod)%mod;
    // trace(x, y, s);
    return m_p(x, y);
}
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        string s;cin >>s;
        auto pp = solve(s);
        int x = pp.fi;
        int y = pp.se;
        x++;y++;
        printf("Case #%d: %lld %lld\n", zz, x, y);
    }
    return 0;
}

