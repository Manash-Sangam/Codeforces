#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s='0'+s;
        int pos=s.size();
        for(int i=s.size();i>=0;i--){
            if(s[i]>='5'){
                s[i-1]++;
                pos=i;
            }
        }
        for(int i=(s[0]=='0');i<s.size();i++){
            cout<<(i<pos?s[i]:'0');
        }
        cout<<endl;
        s.clear();
    }
    return 0;
}