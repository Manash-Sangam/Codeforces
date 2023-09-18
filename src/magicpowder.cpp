#include<bits/stdc++.h>
using namespace std;
bool check(long long M,long long k,vector<long long>&a, vector<long long>&b){
    long long n=a.size();
    for(long long i=0;i<n;i++){
        long long val=b[i]-a[i]*M;
        if(val<0 && abs(val)>k){
            return false;
        }
        else if(val<0 && abs(val)<=k)k+=val;
    }
    return true;
}
long long bs(vector<long long>&a,vector<long long>&b,long long k){
    long long L=0;
    long long R=2000000001;
    long long mid;
    while(R-L>1){
        mid=L+((R-L)/2);
        if(!check(mid,k,a,b))R=mid-1;
        else L=mid;
    }
    if(check(R,k,a,b))return R;
    else return L;
}
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long> b(n);
    for(long long i=0;i<n;i++){
        cin>>b[i];
    }
    long long maxcookie=bs(a,b,k);
    cout<<maxcookie<<endl;
}