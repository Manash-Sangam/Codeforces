#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        double ans;
        ans=(abs((double)a-(double)b)/2)/c;
        ans=ceil(ans);
        cout<<ans<<endl;
    }
    return 0;
}