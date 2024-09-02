#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());

    int q;
    cin >> q;
    while(q--) {
        int mi;
        cin >> mi;

        int ans = upper_bound(prices.begin(), prices.end(), mi) - prices.begin();
        
        cout << ans << "\n";
    }

    return 0;
}
