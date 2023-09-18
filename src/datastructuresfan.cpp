#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num(n+1);
        vector<int> pref(n+1);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            pref[i]=pref[i-1]^num[i];
        }
        int mass=0;
        pair<int,int> x={0,0};
        string s;
        cin>>s;
        s='0'+s;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                x.first^=num[i];
            }
            else{
                x.second^=num[i];
            }
        }
        int q;
        cin>>q;
        vector<vector<int>> queries(q);
        int a,b,c;
        for(int i=0;i<q;i++){
            cin>>a;
            if(a==1){
                cin>>b>>c;
                mass^=pref[c]^pref[b-1];
            }
            else{
                cin>>b;
                if(b==1)cout<<(mass^x.second)<<" ";
                else cout<<(mass^x.first)<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}