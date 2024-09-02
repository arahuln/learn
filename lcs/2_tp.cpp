#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    if(i==0||j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1])return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
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
        string s1,s2;
        cin>>s1>>s2;
        int n1=s1.size(),n2=s2.size();
        int ma=0;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i==0||j==0)dp[i][j]=0;
            }
        }
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ma=max(ma,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<ma;
    }
}