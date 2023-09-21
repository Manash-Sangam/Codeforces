#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--){
        char c;
        int ans=0;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++){
                cin>>c;
                if(c=='X'){
                    // int minValue = min(min(i%5, j%5),min((10 - i + 1)%5, (10 - j + 1)%5));
                    // cout<<minValue<<endl;
                    // ans+=minValue+1;
                    // if(min(i%5, j%5)==0)
                    int r=i;
                    int c=j;
                    if(r>5)r=10-r+1;
                    if(c>5)c=10-c+1;
                    int minv=min(r,c);
                    ans+=minv;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}