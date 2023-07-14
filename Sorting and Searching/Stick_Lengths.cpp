#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll p;
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i] - arr[n/2]);
    }
    cout << ans;
}