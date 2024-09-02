#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(100,vector<int>(1000,-1));

int f(vector<int>&wt,vector<int>&val,int n,int w){
    if(n==0 || w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];

    if(wt[n]<=w){
        return dp[n][w]=max(val[n]+f(wt,val,n-1,w-wt[n]),f(wt,val,n-1,w));
    }else if(wt[n]>w){
        return dp[n][w]=f(wt,val,n-1,w);
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int>wt(n+1);
        vector<int>val(n+1);
        //f(wt,val,n-1,w);

        for(int i=0;i<n+1;i++){//initialization
            for(int j=0;j<w+1;j++){
                if(i==0 || j==0){dp[i][j]=0;}
            }
        }

        for(int i=1;i<n+1;i++){//index 0 taken as 1 here because considering i=0 as n<0 case
            for(int j=0;j<w+1;j++){
                if(wt[i-1]<=j){//wt is i-1 remember
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }else if(wt[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
}