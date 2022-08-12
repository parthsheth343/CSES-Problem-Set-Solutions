#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

ll apples[50];
ll n, d;

ll md(ll i, ll s1, ll s2) { // md = minimum difference
    if (i == n) {return abs(s1 - s2);} // s1 = sum 1. s2 = sum2.

    return min(md(i+1, s1 + apples[i], s2), md(i+1, s1, s2 + apples[i]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) {cin >> d; apples[i] = d;}
    cout << md(0,0,0);
}