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
int mp[N];
ll nc2(ll a){
    return (a*(a-1))/2;
}
int main(){
// 	FIO;
    int t;cin>>t;
    fr(zz, 1, t){
        int n;cin>>n;
        int f0=0, f1=0;
        VI v;
        v.clear();
        set<int> s;s.clear();
        fr(i, 1, n) {
            int x;cin>>x;
            mp[x]++;
            if (x==0) f0=1;
            else if (x==1) f1=1;
            else s.insert(x);
        }
        for(auto it: s) v.pb(it);
        // for(auto it: v) lpr(it);n_l;
        ll ans = 0;
        if(f0){
            ll cnt = mp[0];
            ans = ((cnt*(cnt-1)*(cnt-2))/6) + (cnt*(cnt-1)*((ll)n-cnt))/2;
        }
        //trace(ans);
        if (f1){
            ll cnt = mp[1];
            ans += ((cnt*(cnt-1)*(cnt-2))/6);
            //trace(ans, cnt);
            for(auto it: v) {
                //trace(ans, cnt, it, mp[it]);
                ans += cnt * nc2(mp[it]);
            }
        }
        for(int i=0;i<v.size();i++){
            int it = v[i];
            if (mp[it]>=2 and ((it*(ll)it)<N)){
                ans += nc2(mp[it]) * mp[it*it];
            }
            for(int j=i+1;j<v.size();j++){
            	if ((ll)it * (ll)v[j] < N)
                ans += mp[it] * (ll) mp[v[j]] * (ll) mp[it*v[j]];
            }
            //trace(it, ans);
        }
        mp[0] = mp[1] = 0;
        for(auto it: v) mp[it]=0;
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
    return 0;
}

