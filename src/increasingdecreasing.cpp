#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        vector<int> ans(n);
        ans[0]=x;
        ans[n-1]=y;
        int j=1;
        int i=n-2;
        while(i>0){
            ans[i]=ans[i+1]-j;
            j++;
            i--;
        }
        if(!(ans[1]-ans[0]>=n-1)){
            cout<<-1<<endl;
        }
        else{
            for(auto i:ans)cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}