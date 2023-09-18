//MY Wrong Solution
// #include<bits/stdc++.h>
// using namespace std;
// pair<int,int> recur(vector<vector<int>> &dp,vector<int> &num,int low, int high){
//     int maxindex,minindex;
//     if(high==low+1){
//         if(num[high]>=num[low]){
//             maxindex=high;
//             minindex=low;
//             dp[low][high]=1;

//         }
//         else{
//             maxindex=low;
//             minindex=high;
//             dp[low][high]=0;
//         }
//     }
//     else{
//         cout<<setw(4)<<low<<setw(4)<<high<<endl;
//         int mid=low+(high-low)/2;
//         pair<int,int>  p1=recur(dp,num,low,mid);
//         pair<int,int>  p2=recur(dp,num,mid,high);
//         if(num[p1.first]>num[p2.first])maxindex=p1.first;
//         else maxindex=p2.first;
//         if(num[p1.second]<num[p2.second])minindex=p1.second;
//         else minindex=p2.second;
//         if(maxindex>minindex && dp[low][high]==-1){
//             for(int i=low+1;i<high;i++){
//                 if(dp[low][i]==-1){
//                     pair<int,int> m=recur(dp,num,low,i);
//                 }
//                 if(dp[i][high]==-1){
//                     pair<int,int> m=recur(dp,num,i,high);
//                 }
//                 dp[low][high]=max(dp[low][high],dp[low][i]+dp[i][high])+1;
//             }
//         }
//         else{
//             if(dp[low][high]==-1)
//             {for(int i=low+1;i<high;i++){
//                 if(dp[low][i]==-1){
//                     pair<int,int> m=recur(dp,num,low,i);
//                 }
//                 if(dp[i][high]==-1){
//                     pair<int,int> m=recur(dp,num,i,high);
//                 }
//                 dp[low][high]=max(dp[low][high],dp[low][i]+dp[i][high]);
//             }}
//         }
//     }
//     return make_pair(maxindex,minindex);
// }

// int calc(vector<int> num,int n){
//     vector<vector<int>> dp(n,(vector<int> (n,-1)));
//     pair<int,int> p=recur(dp,num,0,n-1);
//     for(auto i:dp){
//         for(auto j:i){
//             cout<<setw(4)<<j;
//         }
//         cout<<endl;
//     }
//     return dp[0][n-1];
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>num(n);
//     for(int i=0;i<n;i++){
//         cin>>num[i];
//     }
//     cout<<calc(num,n)<<endl;
//     return 0;
// }
//


//Proper solution with monotonic stacks
#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> stmn, stmx;
    stmn.push_back({-1, -1});
    stmx.push_back({n, -1});
    long long ans = 0;
    int len = 0;
    set<pair<int, int>> cur;
    cur.insert({-1, 0});
    cur.insert({-1, 1});
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        --x;
        
        while (stmn.back().first > x){
            auto it = cur.lower_bound({stmn.back().second, 0});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            len -= me->first - prv->first;
            if (it != cur.end() && it->second == 0)
                len += it->first - prv->first;
            cur.erase(me);
            stmn.pop_back();
        }
        len += i - cur.rbegin()->first;
        cur.insert({i, 0});
        stmn.push_back({x, i});
        
        while (stmx.back().first < x){
            auto it = cur.lower_bound({stmx.back().second, 1});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            if (it != cur.end() && it->second == 0)
                len += me->first - prv->first;
            cur.erase(me);
            stmx.pop_back();
        }
        cur.insert({i, 1});
        stmx.push_back({x, i});
        
        ans += len;
    }
    printf("%lld\n", ans - n);
}