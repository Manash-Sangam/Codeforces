#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    int n,m,k,H;
    while(t--){
        cin>>n>>m>>k>>H;
        vector<int> h(n+1);
        for(int i=1;i<=n;i++){
            cin>>h[i];
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if((abs(H-h[i]))%k==0){
                int R=abs((H-h[i]))/k;
                // cout<<R<<" "<<i<<endl;

                if(R<=m-1 && R>0)count++;
            }
        }
        ans.push_back(count);
    }
    for(auto i:ans)cout<<i<<endl;
}