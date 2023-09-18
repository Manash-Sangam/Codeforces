#include<bits/stdc++.h>
using namespace std;
int bs(int t,vector<int> &arr){
    if(t<arr[0])return 0;
    int L=0;
    int R=arr.size()-1;
    int mid;
    while(R-L>=2){
        mid=L+((R-L)/2);
        if(arr[mid]>t)R=mid;
        else if(arr[mid]<=t)L=mid;
    }
    // cout<<L<<" "<<R<<endl;
    if(arr[R]<=t)return R+1;
    return L+1;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int q;
    cin>>q;
    vector<int> days(q);
    for(int i=0;i<q;i++){
        cin>>days[i];
    }
    vector<int> ans(q);
    sort(price.begin(),price.end());
    for(int i=0;i<q;i++){
        ans[i]=bs(days[i],price);
        cout<<ans[i]<<endl;
    }
}