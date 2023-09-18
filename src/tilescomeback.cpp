#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> c(n);
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        pair<int,int>val={0,0};
        int m,l;
        // cout<<val.first<<val.second;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(c[i]==c[0]){val.first++;if(val.first==k)m=i;}
            if(c[j]==c[n-1]){val.second++;if(val.second==k)l=j;}
        }
        if(c[0]==c[n-1]&&val.first>=k)ans.push_back("YES");
        else{
            if(val.first>=k&& val.second>=k && m<l)ans.push_back("YES");
            else ans.push_back("NO");
        }


    }
    for(auto i:ans)cout<<i<<endl;
}