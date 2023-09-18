#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> u(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        u=v;
        sort(u.begin(),u.end());
        bool flag=false;
        for(int i=0;i<n;i++){
            if(u[i]%2!=v[i]%2){
                ans.push_back("NO");
                flag=true;
                break;
            }
        }
        if(!flag)ans.push_back("YES");
    }
    for(auto i:ans)cout<<i<<endl;
}