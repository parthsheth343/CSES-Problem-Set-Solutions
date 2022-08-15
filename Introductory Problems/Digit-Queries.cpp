#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"


char solve(ll query) {
    if (query < 10) {return to_string(query)[0];} else {
        ll counter = 0;
        ll base = 0;
        while (query > counter) {
            query -= counter;
            counter = 9*(base+1)*pow(10, base);
            base++;
        }
        base--;
        ll starter = pow(10, base);
        starter += query/(base+1);
        if (query%(base+1) == 0) {
            return to_string(starter-1)[base];
        } else {
            return to_string(starter)[query%(base+1)-1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll q, query;
    cin >> q;
    for (int querynumber = 0; querynumber < q; querynumber++) {
        cin >> query;
        cout << solve(query) << endl;
    }
}