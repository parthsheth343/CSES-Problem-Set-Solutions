#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    unordered_set<int> data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        data.insert(x);
    }
    cout << data.size();
}

