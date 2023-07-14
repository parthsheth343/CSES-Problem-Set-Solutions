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
    ll x;
    ll maxsum = -1000000001;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cur = max(x, cur + x);
        maxsum = max(maxsum, cur);
    }
    cout << maxsum;
}