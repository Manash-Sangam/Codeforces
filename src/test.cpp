#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> num={1,2,3,4,5,6};
    for(auto i: num)cout<<i<<" ";
    cout<<endl;
    rotate(num.begin(),num.begin()+6,num.end());
    for(auto i:num)cout<<i<<" ";
    cout<<endl;
}