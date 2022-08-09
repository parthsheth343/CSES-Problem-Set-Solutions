#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        if ((a+b)%3 != 0) {cout <<"NO" <<endl;}
        else {
            if (a>b) {if (b*2 >= a) {cout <<"YES" <<endl;} else {cout <<"NO" <<endl;}}
            else {if (a*2 >= b) {cout <<"YES" <<endl;} else {cout << "NO" << endl;}}
        }
    }
}