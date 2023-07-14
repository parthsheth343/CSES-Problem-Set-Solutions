#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    if (coins[0]!= 1) {
        cout << 1;
        return 0;
    }
    ll sum = 1; 
    for (int i = 1; i < n; i++) {
        if (coins[i] > sum+1) {
            cout << sum+1;
            return 0;
        }
        sum += coins[i];
    }
    cout << sum+1;
}