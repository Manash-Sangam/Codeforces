#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> prefix(n-1);
        vector<int> preor(n-1);
        for(int i=0;i<n-1;i++){
            cin>>prefix[i];
        }
        map<int,int> ori;
        preor[0]=prefix[0];
        ori[prefix[0]]++;
        for(int i=1;i<n-1;i++){
            preor[i]=prefix[i]-prefix[i-1];
            ori[preor[i]]++;
        }
        vector<int> rem;
        for(int i=1;i<=n;i++){
            if(!ori[i])rem.push_back(i);
            else ori[i]--;
        }
        if (rem.size()>2)ans.push_back("No");
        else{
            if(rem.size()==1)ans.push_back("YES");
            else if(ori[rem[0]+rem[1]])ans.push_back("YES");
            else ans.push_back("No");
        }


    }
    for(auto i:ans)cout<<i<<endl;

}