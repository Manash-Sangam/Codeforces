#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll check(vector<int> &coral,int h){
    ll sum=0;
    // cout<<"For "<<h<<":"<<endl;
    for(auto i:coral){
        // cout<<sum<<endl;
        sum+=((i>h)?0:(h-i));
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> coral(n);
        for(int i=0;i<n;i++){
            cin>>coral[i];
        }
        int l=1;
        int r=2e9;
        int mid;
        while(r-l>1){
            mid=l+(r-l)/2;
            ll sum=check(coral,mid);
            // cout<<sum<<" ";
            if(sum>x)r=mid-1;
            else l=mid;
        }
        if(check(coral,r)<=x){
            // cout<<"For right:"<<endl;
            cout<<r<<endl;
        }
        else cout<<l<<endl;
    }
    return 0;
}