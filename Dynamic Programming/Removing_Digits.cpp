#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1000000;
        string q = to_string(i);
        for (int j = 0; j < q.size(); j++) {
            if (i - (q[j]-'0') >= 0) {
                dp[i] = min(dp[i], dp[i-(q[j]-'0')]+1);
            }
        }
    }
    cout << dp[n];
}