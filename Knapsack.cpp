#include<bits/stdc++.h>
using namespace std;

int f(int level,int cost,vector<int>&w,vector<int>&v,vector<vector<int>>&dp){
    if(level<0||cost==0)return 0;
    if(dp[level][cost]!=-1)return dp[level][cost];
    int nt=f(level-1,cost,w,v,dp);
    int t=0;
    if(cost-w[level]>=0){
        t=v[level]+f(level-1,cost-w[level],w,v,dp);
    }
    return dp[level][cost]=max(nt,t);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,cost;
        cin>>n>>cost;
        vector<int>w(n),v(n);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            w[i]=a;v[i]=b;
        }
        vector<vector<int>>dp(n+1,vector<int>(cost+1,-1));
        cout<<f(n-1,cost,w,v,dp)<<"\n";
    }
}