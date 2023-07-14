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

    int a, b;

    vector<pair<ll, ll>> arr;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());

    int customers = 0; 
    int ans = -1;

    for (auto i : arr) {
        customers+=i.second;
        ans = max(ans, customers);
    }

    cout << ans;

}