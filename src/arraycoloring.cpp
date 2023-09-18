#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n;
        cin>>n;
        int odd=0;
        bool val=false;
        vector<int> num(n);
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]%2!=0)odd++;
        }
        if(odd%2==0)val=true;
        if(val)ans.pb("YES");
        else ans.pb("NO");
    }
    for(auto i:ans)cout<<i<<endl;
    return 0;
}