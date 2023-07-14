#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll presum = 0;
    map<ll, ll> valfound;
    valfound[0] = 1;
    ll ans = 0;
    for (auto q : a) {
        presum+=q;
        ans += valfound[presum-x];
        valfound[presum]++;
    }
    cout << ans;
}