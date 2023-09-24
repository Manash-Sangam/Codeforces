#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int n;
    vector<vector<int>> E;
    vector<bool> vis;
    int point;
    Graph(int n):n(n){
        E=vector<vector<int>>(n+1);
        vis=vector<bool>(n+1,false);
        int u,v;   
        for(int i=0;i<n;i++){
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
    }
    int calc_entry(int b){
        entry(b,-1);
        return point;
    }
    bool entry(int u,int p){
        vis[u]=true;
        for(auto ngh:E[u]){
            if(ngh!=p && vis[ngh]){
                point=ngh;
                return true;
            }
            if(ngh!=p && !vis[ngh])
            if(entry(ngh,u))return true;;
        }
        return false;
    }
    int dfs(int u,int p,int point){
        vis[u]=true;
        int dist=n;
        for(auto ngh:E[u]){
            if(ngh!=p){
                if(ngh==point)return 1;
                dist=min(dfs(ngh,u,point)+1,dist);
            }
        }
        return dist;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        Graph g(n);
        int point=g.calc_entry(b);
        // cout<<point<<endl;
        g.vis.assign(n+1,false);
        int distM,distV;
        if(point==a)distM=0;
        else distM=g.dfs(a,-1,point);
        // cout<<distM<<endl;
        g.vis.assign(n+1,false);
        if(point==b)distV=0;
        else distV=g.dfs(b,-1,point);
        // cout<<distV<<endl;
        if(distV<distM)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}