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
    vector<int> coins(n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                if (dp[i-c] > 0)
                dp[i] += dp[i-c];
            }
            dp[i] %= 1000000007;
        }
    }
    cout << dp[x];
}