#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int mod = 1000000007;

int dp[2001][2001];

int solve(int n, int k, int m) {
    if (n == 1) {
        return k == 0 ? m : 0; 
    }
    if (dp[n][k] != -1) return dp[n][k];
    
    int ans = solve(n - 1, k, m);
    if (k > 0) {
        ans = (ans + (solve(n - 1, k - 1, m) * (m - 1)) % mod) % mod;
    }
    return dp[n][k] = ans;
}

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(n, k, m) << "\n";
    }
    return 0;
}
