#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<long long>ans;
    while(t--){
        int n;
        cin>>n;
        vector<long long> in(n);
        for(int i=0;i<n;i++){
            cin>>in[i];
        }
        long long val=INT_MAX;
        bool p=true;
        for(int i=1;i<n;i++){
            if(in[i]<in[i-1]){
                val=0;
                p=false;
                break;
            }
            val=min(val,(in[i]-in[i-1])/2);
        }
        if(p)ans.push_back(val+1);
        else ans.push_back(val);
    }
    for(auto i:ans)cout<<i<<endl;
}