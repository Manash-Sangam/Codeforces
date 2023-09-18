#include<bits/stdc++.h>
using namespace std;
int min_divisor(int i){
    int sqr=sqrt(i)+1;
    for(int n=2;n<=sqr;n++){
        if(i%n==0)return n;
    }
    return i;
}
void split(int l,int r){
    for(int i=l;i<=r;i++){
        int md=min_divisor(i);
        if(md!=i){
            cout<<md<<" "<<i-md<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        split(l,r);
    }
    return 0;
}