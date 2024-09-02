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
void back_track(int i,int j,vector<vector<int>>&dp,string &s,string s1,string s2){
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
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
        f(n1,n2,s1,s2,dp);
        string s;
        back_track(n1,n2,dp,s,s1,s2);
        reverse(s.begin(),s.end());
        cout<<s;
    }
}