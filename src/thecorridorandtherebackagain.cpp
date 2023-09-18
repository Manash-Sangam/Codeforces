#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> trap(n);
        for(int i=0;i<n;i++){
            cin>>trap[i].first>>trap[i].second;
        }
        sort(trap.begin(),trap.end());
        int ans=INT_MAX;
        int temp;
        for(auto i:trap){
            if(ans<=i.first)break;
            temp=i.first+((i.second-1)/2);
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}