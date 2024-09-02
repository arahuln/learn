// class Solution{   
// public:
    // int f(int n,int sum,vector<int>&nums,vector<vector<int>>&dp){
    //     if(sum==0)return 1;
    //     if(n<0||sum<0)return 0;
    //     if(dp[n][sum]!=-1)return dp[n][sum];
    //     int ans,ans2;
    //      if(sum-nums[n]>=0){
    //         ans=f(n-1,sum-nums[n],nums,dp);
    //      }
    //     ans2=f(n-1,sum,nums,dp);
    //     return dp[n][sum]=(ans || ans2);
    // }
//     bool isSubsetSum(vector<int>nums, int sum){
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<sum+1;j++){
//                 if(j==0)dp[i][j]=1;
//                 if(i==0)dp[i][j]=0;
                
//             }
//         }
//         dp[0][0]=1;
//         for(int i=1;i<n+1;i++){
//             for(int j=0;j<sum+1;j++){
//                 int ans=0;
//                 if(j-nums[i-1]>=0){
//                     ans=dp[i-1][j-nums[i-1]];
//                 }
//                 int ans2=dp[i-1][j];
//                 dp[i][j]=(ans|ans2);
//             }
//         }
//         if(dp[n][sum]==1)return true;
//         return false;
//     }
// };