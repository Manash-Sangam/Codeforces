#include<bits/stdc++.h>
using namespace std;
int calculatearea(vector<long long>s,long w,long long k){
    long long sum=0;
    for(auto i:s){
        sum+=(2*w+i)*(2*w+i);
        if(sum>k)return 1;
    }
    if(sum==k)return 0;
    else if(sum>k)return 1;
    else return -1;
}
int binarysearch(long long n,long long k,vector<long long>s){
    long long l=0;
    long long r=(long long)sqrtl(k);
    while(l<=r){
        long long m=l+((r-l)/2);
        int ch=calculatearea(s,m,k);
        if(ch==0)return m;
        else if(ch==1)r=m-1;
        else l=m+1;
    }
}
int main()
{
    int t;
    cin>>t;
    vector<long> ans;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> s(n);
        for(long i=0;i<n;i++)cin>>s[i];
        long a=binarysearch(n,k,s);
        ans.push_back(a);
    }
    for(auto i:ans)cout<<i<<endl;
    return 0;
}