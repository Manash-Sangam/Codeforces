#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ans;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        vector<int> num(n);
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]==i+1)count++;
        } 
        ans.push_back((count+1)/2);   
    }
    for(auto i:ans)cout<<i<<endl;
    return 0;
}