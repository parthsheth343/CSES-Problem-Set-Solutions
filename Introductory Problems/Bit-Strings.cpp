#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, final = pow(2, 29);
    cin >> n;
    if (n < 30){cout << (ll) pow(2, n);}
    else {
        ll mod = pow(10, 9) + 7;
        for (int i = 30; i <= n; i++) {
            final = ((ll) final*2)%(mod);
        }
        cout << final;
    }
}