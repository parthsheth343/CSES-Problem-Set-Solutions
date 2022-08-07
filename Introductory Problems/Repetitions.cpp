#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string dna; ll count = 1; ll maxcount = 1;
    cin >> dna;

    for (int i = 1; i <= (ll) dna.size(); i++) {
        if (dna[i] == dna[i-1]) {
            count ++;
        } else {
            maxcount = max(maxcount, count);
            count = 1;
        }
    }
    maxcount = max(maxcount, count);
    cout << maxcount;

}