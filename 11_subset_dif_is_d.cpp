// int countPartitions(int n, int d, vector<int>& nums) {
//         int sum,s=0;
//         for(int i=0;i<n;i++){
//             s+=nums[i];
//         }
//         if((d+s)%2==1)return 0;
//         sum=(d+s)/2;
//         const int MOD=1000000007;
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<=sum;j++){
//                 if(i==0)dp[i][j]=0;
//                 if(j==0)dp[i][j]=1;
//             }
//         }
//         for(int i=1;i<n+1;i++){
//             for(int j=0;j<=sum;j++){
//                 if(j-nums[i-1]>=0){
//                     dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%MOD;
//                 }else{
//                     dp[i][j]=dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][sum];
//     }