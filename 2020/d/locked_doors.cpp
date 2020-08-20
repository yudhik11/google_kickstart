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
int a[N];
int st[4*N];
int n;
void build(int* a, int idx, int l, int r){
    if (l == r){
        st[idx] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(a, idx*2, l, mid);
    build(a, idx*2 + 1, mid+1, r);
    st[idx] = max(st[idx + idx], st[idx + idx + 1]);
    return;
}
int query(int idx, int p, int q, int l, int r){
    if (p > r || q < l) return 0;
    if (p>=l  and q<=r) return st[idx];
    int mid = (p+q)/2;
    int lans = 0;
    int rans = 0;
    if (l<=mid) lans = query(idx + idx, p, mid, l, r);
    if (mid < r) rans = query(idx + idx + 1, mid+1, q, l, r);
    return max(lans, rans);
}
int find(int l, int r, int z){
    
    while(l<=r){
        int mid = (l+r)/2;
        int mx = query(1, 1, n-1, l, mid);
        if (mx <= z) l = mid+1;
        else r = mid-1;
    }
    // trace(l, r);
    return l-1;
}
int findGt(int i,int s,int e,int l,int r,int x)
{
    if(s>r || l>e)
        return -1;
    int m = (s+e)/2;
    if(s>=l && e<=r)
    {
        if(st[i]<=x)
            return -1;
        if(s==e)
        {
            return s;
        }
        if(st[2*i]>x)
        {
            return findGt(2*i,s,m,l,r,x);
        }
        else
        {
            return findGt(2*i+1,m+1,e,l,r,x);
        }
    }
    int z = findGt(2*i,s,m,l,r,x);
    if(z!=-1)
        return z;
    return findGt(2*i+1,m+1,e,l,r,x);
}

int solve(int s, int k){
    int l = 1;
    int r = s;
    // int x;
    int gate_left;
    while(l<=r){
        int mid = (l+r)/2;
        int z = query(1, 1, n-1, mid, s-1);
        // trace(mid, s-1, z);
        // x = find(s, n-1, z);
        int tmp = findGt(1, 1, n-1, s, n-1, z);
        if (tmp == -1) tmp = n;
        tmp--;
        // trace(x, tmp);
        // trace(l, r, mid, x, x-mid+2, a[x]);
        gate_left =mid;
        if (tmp-mid+2 == k) break;
        if (tmp-mid+2 >= k) l = mid+1;
        else r = mid-1;
    }
    // trace(l, r);
    int z = query(1, 1, n-1, gate_left, s-1);
    int tmp = findGt(1, 1, n-1, s, n-1, z);
    if (tmp == -1) tmp = n;
    tmp--;
        
    // x = find(s, n-1, z);
    // trace(x - gate_left + 2);
    int flag = 0;
    if (tmp - gate_left + 2 > k) flag=1, gate_left ++;        
    int gate_right = tmp;
    // trace(gate_left, gate_right);
    int access = gate_right - gate_left + 2;
    if (access == k) {
        if (!flag) return gate_left;
        else return gate_right+1;
    }
    gate_right = k + gate_left - 2;
    // trace(access, gate_right);
    return gate_right+1;

}
int main(){
    int t;sc(t);
    fr(zz, 1, t){
        int q;sc(n);sc(q);
        fr(i, 1, n-1){
            sc(a[i]);
        }
        build(a, 1, 1, n-1);
        // int cnt =3;
        // while(cnt--){
        //     int l, r;sc(l);sc(r);
        //     trace(l, r, query(1, 1, n-1, l, r));
        // }
        printf("Case #%d: ", zz);
        while(q--){
            int s, k;
            sc(s);sc(k);
            if (k==1) pr(s);
            else if (s==1) pr(k);
            else{
                pr(solve(s, k));
            }
        }
        n_l;
        // lpr(fans);n_l;
    }
    return 0;
}

