#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, zeros, x=5;
    cin >> n;
    while (true) {
        zeros += floor(n/x);
        x*=5;
        if (floor(n/x)==0){break;}
    }
    cout << zeros;
}