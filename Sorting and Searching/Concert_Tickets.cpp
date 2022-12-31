#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h, t;
    multiset<int> tickets;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto price = tickets.upper_bound(t);
        if (price == tickets.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--price) << endl;
            tickets.erase(price);
        }
    }
}