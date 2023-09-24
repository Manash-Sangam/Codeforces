#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> fruits(n);
        vector<int> height(n);
        for(int i=0;i<n;i++)cin>>fruits[i];
        for(int i=0;i<n;i++)cin>>height[i];
        if(n==1){
            if(fruits[0]<=k)cout<<1<<endl;
            else cout<<0<<endl;
            continue;
        }
        int i=0,j=0;
        int fruits_collected=fruits[0];
        int ans=0;
        int _=0;
        while(i<n&&j<n){
            if(i==j){
                if(fruits[i]<=k){
                    _++;
                    j++;
                    fruits_collected=fruits[i];
                    continue;
                }
                else{
                    i++;
                    j++;

                }
            }
            else{
                if(height[j-1]%height[j]!=0){
                    ans=max(ans,_);
                    i=j;
                    _=0;
                    fruits_collected=0;
                }
                else if(fruits_collected+fruits[j]>k){
                    ans=max(ans,_);
                    _--;
                    fruits_collected-=fruits[i];
                    i++;
                }
                else{
                    fruits_collected+=fruits[j];
                    j++;
                    _++;
                }
            }
        }
        cout<<max(ans,_)<<endl;

    }
    return 0;
}