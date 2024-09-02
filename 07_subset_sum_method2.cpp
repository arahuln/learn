// class Solution{   
// public:
//     int f(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
//         if(sum==0)return 1;
//         if(sum<0 || n<0)return 0;
//         if(dp[n][sum]!=-1)return dp[n][sum];
//         return dp[n][sum]=f(nums,sum-nums[n],n-1,dp)||f(nums,sum,n-1,dp);
//     }
//     bool isSubsetSum(vector<int>nums, int sum){
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
//         // return f(nums,sum,n-1,dp);
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<sum+1;j++){
//                 int a=0,a1=0;
//                 if(i==0)a=0;
//                 if(j==0)a1=1;
//                 dp[i][j]=(a | a1);
//             }
//         }
//         for(int i=1;i<n+1;i++){
//             for(int j=0;j<sum+1;j++){
//                 int ans=0;
//                 if(j-nums[i-1]>=0)ans=dp[i-1][j-nums[i-1]];
//                 int ans2=dp[i-1][j];
//                 dp[i][j]=(ans | ans2);
//             }
//         }
//         if(dp[n][sum]==1)return true;
//         return false;
//     }
// };