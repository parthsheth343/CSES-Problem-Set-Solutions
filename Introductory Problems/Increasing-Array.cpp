#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll numberofelements = 0; ll x = 0; ll count = 0;
    vector<ll> elements;
    cin  >> numberofelements;
    if (numberofelements == 1) {cout << 0;} else {
        for (ll i = 0; i < (ll) numberofelements; i++) {cin >> x; elements.push_back(x);}
        for (ll i = 0; i < (ll) elements.size()-1; i++) {
            if (elements[i+1] < elements[i]) {
                count = count + elements[i] - elements[i+1];
                elements[i+1] = elements[i];
            }
        }
        cout << count;
    }
}