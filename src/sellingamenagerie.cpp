#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> afraid(n+1);
        vector<int> cost(n+1);
        vector<int> feared(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>afraid[i];
            feared[afraid[i]]++;
        }
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }
        queue<int> q;
        vector<int> order;
        vector<bool> added(n+1,false);
        for(int i=1;i<=n;i++){
            if(feared[i]==0)q.push(i);
        }
        while(!q.empty()){
            int animal=q.front();
            q.pop();
            order.push_back(animal);
            added[animal]=true;
            if(--feared[afraid[animal]]==0)q.push(afraid[animal]);
        }
        for(int i=1;i<=n;i++){
            if(!added[i]){
                vector<int> cycle;
                cycle.push_back(i);
                int animal=afraid[i];
                int mv=cost[i];
                while(i!=animal){
                    mv=min(mv,cost[animal]);
                    cycle.push_back(animal);
                    animal=afraid[animal];

                }
                // for(auto i: cycle)cout<<i<<" ";
                // cout<<endl;
                for(int i=0;i<cycle.size()-1;i++){
                    if(cost[cycle[i]]==mv){
                        rotate(cycle.begin(),cycle.begin()+i+1,cycle.end());
                        break;
                    }
                }
                // for(auto i: cycle)cout<<i<<" ";
                // cout<<endl;
                for(auto i:cycle){
                    order.push_back(i);
                    added[i]=true;
                }
            }
        }
        for(auto i:order)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}