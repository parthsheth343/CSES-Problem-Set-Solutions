#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    dp[0] = 0;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 1; i <= x; i++) {
        dp[i] = 10000000;
        for (auto c : coins) {
            if (i - c >= 0) dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    if (dp[x] == 10000000) cout << -1;
    else cout << dp[x];
}