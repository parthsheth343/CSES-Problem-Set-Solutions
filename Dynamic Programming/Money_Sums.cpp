#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

bool dp[101][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> coins(n+1);
    int totalsum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
        totalsum += coins[i];
    }
    dp[0][0]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalsum; j++) {
            if (dp[i-1][j] == 1) {
                dp[i][j] = 1;
                continue;
            }
            if (coins[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j-coins[i]];
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= totalsum; i++) {
        if (dp[n][i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';

}