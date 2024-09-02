#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int ans=1,ind=0;
        vector<int>dp(n+1,1),hash(n);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
                if(dp[i]>ans){
                    ans=dp[i];
                    ind=i;
                }
            }
        }
        cout<<ans<<"\n";
        while(ans>0){
            cout<<ind<<" ";
            ind=hash[ind];
            ans--;
        }
    }
}




//