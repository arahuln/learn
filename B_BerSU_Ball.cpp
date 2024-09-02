#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int>&s1,vector<int>&s2,vector<vector<int>>&dp){
    if(i==0||j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(abs(s1[i-1]-s2[j-1])<=1)return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
    else{
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n1;
        cin>>n1;
        vector<int>s1(n1);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        int n2;
        cin>>n2;
        vector<int>s2(n2);
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        sort(s1.begin(),s1.end(),greater<int>());
        sort(s2.begin(),s2.end(),greater<int>());
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int ans=f(n1,n2,s1,s2,dp);
        cout<<ans<<"\n";
    }
}