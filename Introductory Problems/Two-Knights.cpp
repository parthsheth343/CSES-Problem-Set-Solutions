#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<ll> ways = {0}; 
    cin >> n;
    if (n==1){cout << 0;} 
    else {
        cout << 0 << endl;
        for (int i = 1; i < n; i++) {
            ways[i] = ways[i-1] + (ll) 2*i*i*i + (ll) 3*i*i - (ll) 7*i + 8;
            cout << ways[i] << endl;
        }
    }
}