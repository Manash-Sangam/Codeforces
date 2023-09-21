#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num(n);
        long long product=1;
        int z=0;
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]==0){z++;continue;}
            product*=num[i];
        }
        if(z>0)
        {
            if(z>1)
            cout<<0<<endl;
            else cout<<product<<endl;
            continue;
        }
        long long ans,final=0;
        for(int i=0;i<n;i++){
            ans=product/num[i];
            ans*=(num[i]+1);
            final=max(ans,final);
        }
        cout<<final<<endl;
    }
    return 0;
}