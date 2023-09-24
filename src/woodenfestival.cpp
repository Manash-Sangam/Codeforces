#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &pattern, int m){
    int n=pattern.size();
    int i=0,j=n-1;
    while(i+1<n && pattern[i+1]-pattern[0]<=2*m)i++;
    while(j-1>0 && pattern[n-1]-pattern[j-1]<=2*m)j--;
    ++i;--j;
    if(i>j || pattern[j]-pattern[i]<=2*m)return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> pattern(n);
        for(int i=0;i<n;i++)cin>>pattern[i];
        sort(pattern.begin(),pattern.end());
        int l=-1,r=1e9;
        int m;
        while(r-l>1){
            m=(l+r)>>1;
            if(!check(pattern,m))l=m;
            else r=m;
        }
        cout<<r<<endl;
    }
    return 0;
}