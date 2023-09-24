#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> row(n);
        vector<ll> col(n);
        for(ll i=0;i<n;i++){
            cin>>row[i];
        }
        for(ll i=0;i<n;i++){
            cin>>col[i];
            
        }
        vector<ll> temp1=row;
        vector<ll> temp2=col;
        sort(temp1.begin(),temp1.end());
        ll sum1=0;
        for(ll num:col)sum1+=(temp1[0]+num);
        sort(temp2.begin(),temp2.end());
        ll sum2=0;
        for(ll num:row)sum2+=(temp2[0]+num);
        cout<<min(sum1,sum2)<<endl;
    }
    return 0;
}