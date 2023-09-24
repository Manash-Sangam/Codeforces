#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>> &ath){
    int n=ath.size();
    int pol_s=ath[0].first;
    int pol_e=ath[0].second;
    for(int i=1;i<n;i++){
        if(ath[i].first>=pol_s && ath[i].second >=pol_e)return -1;
    }
    return pol_s;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> ath(n);
        for(int i=0;i<n;i++)cin>>ath[i].first>>ath[i].second;
        cout<<solve(ath)<<endl;
        
    }
    return 0;
}