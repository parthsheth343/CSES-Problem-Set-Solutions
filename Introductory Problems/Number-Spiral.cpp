#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, x, y;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> y >> x;
        if (y == x) {cout << (ll) x*x - (ll) x + 1<<endl;}
        else if (y > x) {
            if (y%2 == 0) {cout << (ll) y*y + 1 - x<<endl;}
            else {cout << (ll) y*y - (ll) 2*y + 1 + x<<endl;}
        }
        else {
            if (x%2 == 0) {cout << (ll) x*x - (ll) 2*x + 1 + y<<endl;}
            else {cout << (ll) x*x + 1 - y<<endl;}
        }
    }
}