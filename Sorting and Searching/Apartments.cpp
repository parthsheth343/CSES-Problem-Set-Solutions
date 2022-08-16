#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; //n = # of applicants, m = # of apartments, k = max allowed difference
    vector<int> das; //das = desired apartment sizes
    vector<int> soa; //soa = size of apartments;
    int a, b;
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        das.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        soa.push_back(b);
    }
    sort(das.begin(), das.end());
    sort(soa.begin(), soa.end());
    while (das.size()>0 && soa.size()>0) {
        if (soa[soa.size()-1] >= das[das.size()-1] - k && soa[soa.size()-1] <= das[das.size()-1] + k) {
            ans++;
            soa.pop_back();
            das.pop_back();
        } else {
            soa[soa.size()-1] > das[das.size()-1] ? soa.pop_back() : das.pop_back();
        }
    }
    cout << ans << endl;
}