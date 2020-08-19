#include<bits/stdc++.h>
using namespace std;
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
#define fr(zz, i, t) for(int zz=i;zz<=t;zz++)
int freq[100005];
int vis[100005];
int main(){
    int t;cin >>t;
    fr(zz, 1, t){
        int n, m, q;
        cin >>n>>m>>q;
        fr(i, 1, n) vis[i]=1, freq[i]=0;
        fr(i,1,m){
            int x;cin >>x;
            vis[x]=0;
        }
        fr(i, 1, q){
            int x;cin>>x;
            freq[x]++;
        }
        long long ans = 0;
        fr(i,1,n) {
        	for(int j=i;j<=n;j+=i){
        		ans += (long long)freq[i] * (long long)vis[j];
        	}
        }
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
}