#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll c = n;
    cout << c << " ";

    while (c != 1) {
        if (c%2 == 0) {c/=2; cout << c << " ";}
        else {c = 3*c + 1; cout << c << " ";}
    }

}