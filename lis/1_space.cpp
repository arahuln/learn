#include<bits/stdc++.h>
using namespace std;

int f(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
    if(ind==nums.size())return 0;
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
    int len=f(ind+1,prev ,nums,dp);
    if(prev==-1 || nums[ind]>nums[prev]){
        len=max(1+f(ind+1,ind ,nums,dp),len);
    }
    return dp[ind][prev+1]=len;
}

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
        vector<int>next(n+1,0);
        vector<int>cur(n+1,0);
        //cout<<f(0,-1,nums,dp);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==n)cur[j]=0;
            }
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=n-1;prev>=-1;prev--){
                int len=next[prev+1];
                if(prev==-1 || nums[ind]>nums[prev]){
                    len=max(1+next[ind+1],len);
                }
                cur[prev+1]=len;
            }
            next=cur;
        }
        cout<<cur[0];
    }
}