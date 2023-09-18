#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=INT_MAX;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(abs(num[i])<ans)ans=abs(num[i]);
    }
    cout<<ans;
}