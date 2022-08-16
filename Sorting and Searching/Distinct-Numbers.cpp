#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    vector<int> data;
    cin >> n;;
    for (int i = 0; i < n; i++) {
        cin >> x;
        data.push_back(x);
    }
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    cout << data.size() << endl;
}