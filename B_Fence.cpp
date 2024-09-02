#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int i = 0, j = 0;
        int sum = 0, ans = INT_MAX, index = 0;

        for(j = 0; j < k; j++){
            sum += nums[j];
        }
        ans = sum;
        index = 1;

        while(j < n){
            sum = sum + nums[j] - nums[i];
            i++;
            if(sum < ans){
                ans = sum;
                index = i + 1;
            }
            j++;
        }
        cout << index << "\n";
    }
    return 0;
}
