#include<bits/stdc++.h>
using namespace std;
// long long bisearch(long long val,long long k,long long m){
//     long long L=0;
//     long long R=m;
//     long long M;
//     while(R-L>1){
//         M=L+((R-L)/2);
//         // cout<<L<<" "<<M<<" "<<R<<endl;
//         if(M*k>val)R=M-1;
//         else L=M;
        
//     }
//     if(R*k<=val)return R;
//     return L;
// }
// long long minFancy(long long m, long long k, long long a1,long long ak){
//     long long val;
//     long long r1=m/k;
//     r1=min(r1,ak);
//     // cout<<r1<<endl;
//     val=m-r1*k;
//     val-=a1;
//     // cout<<val;
    
//     if(val<=0)return 0;
//     else if (val<=k && m>=k)return 1;
//     else if(val<k)return val;
//     else{
//         long long ans=bisearch(val,k,m);
//         // cout<<ans<<endl;
//         if(val>ans)ans+=val-ans*k;
//         return ans; 
//     }
    
// }

// int main()
// {
//     int t;
//     cin>>t;
//     vector<int> ans;
//     while(t--){
//         long long m,k,a1,ak;
//         cin>>m>>k>>a1>>ak;
//         ans.push_back(minFancy(m,k,a1,ak));
//     }
//     for(auto i:ans)cout<<i<<endl;
//     return 0;
// }
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int m, k, a1, ak;
		cin >> m >> k >> a1 >> ak;
		int taken_k = m / k;
		int taken_1 = m % k;
		int taken_fancy_1 = max(0, taken_1 - a1);
		int left_regular_1 = max(0, a1 - taken_1);
		int taken_fancy_k = max(0, taken_k - ak);
		int to_replace = min(left_regular_1 / k, taken_fancy_k);
		int ans = taken_fancy_1 + taken_fancy_k - to_replace;
		cout << ans << endl;
	}
}