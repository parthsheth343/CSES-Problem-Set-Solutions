#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int dp[1001][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> books(n+1); //cost, value
    for (int i = 1; i <= n; i++) cin >> books[i].first;
    for (int i = 1; i <= n; i++) cin >> books[i].second;

    for (int i = 1; i <= n; i++) { //iterates through books
        for (int j = 1; j <= x; j++) { //iterates through max weights
            if (books[i].first > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], books[i].second + dp[i-1][j-books[i].first]);
        }
    }
    cout << dp[n][x];
}