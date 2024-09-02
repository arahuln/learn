#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    vector<int> query(q);
    int max_query = 0;
    for (int i = 0; i < q; i++) {
        cin >> query[i];
        max_query = max(max_query, query[i]);
    }

    // DP table to store if a subset sum is possible
    vector<vector<int>> dp(n + 1, vector<int>(max_query + 1, 0));
    dp[0][0] = 1; // Sum 0 is always possible with an empty subset

    // Fill the DP table
    for (int level = 1; level <= n; level++) {
        for (int su = 0; su <= max_query; su++) {
            dp[level][su] = dp[level - 1][su]; // Exclude current element
            if (su >= nums[level - 1]) {
                dp[level][su] = dp[level][su] || dp[level - 1][su - nums[level - 1]]; // Include current element
            }
        }
    }

    // Answer the queries
    for (int i = 0; i < q; i++) {
        if (query[i] <= max_query && dp[n][query[i]] == 1) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
