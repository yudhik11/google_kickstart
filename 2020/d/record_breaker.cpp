#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int t;cin >>t;
    for(int zz=1;zz<=t;zz++){
        int n;cin >>n;
        for(int i=1;i<=n;i++){
            cin >>a[i];
        }
        int prev = -1, ans=0;
        for(int i=1;i<=n;i++){
            if (a[i] > prev){
                if (i==n or ((i<n) and (a[i] > a[i+1])))
                    ans++;
            }
            prev = max(prev, a[i]);
        }
        cout<<"Case #"<<zz<<": "<<ans<<endl;
    }
}