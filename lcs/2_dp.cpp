#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s1,string s2,vector<vector<int>>&dp,int &ma){
    if(i==0||j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        dp[i][j]=1+f(i-1,j-1,s1,s2,dp,ma);
        ma=max(ma,dp[i][j]);
        return dp[i][j];
    }
    else{
        f(i-1,j,s1,s2,dp,ma);
        f(i,j-1,s1,s2,dp,ma);
        return 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int ma=0;
        f(n1,n2,s1,s2,dp,ma);
        cout<<ma;
    }
}