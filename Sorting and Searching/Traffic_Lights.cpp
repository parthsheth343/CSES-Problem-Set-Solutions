#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n, p;
    cin >> x >> n;

    set<int> positions{0, x};
    multiset<int> distances{x};

    for (int i = 0; i < n; i++) {
        cin >> p;
        set<int>::iterator R = positions.upper_bound(p);
        set<int>::iterator L = R;
        --L;

        positions.insert(p);
        //  *R is the position of the light after p
        //  *L is the position of the light before p
        //  *R - *L is the distance between the light after p and the light before p
        //  We erase this distance from the distances multiset since it no longer exists as p is between these 2 lights
        //  Now that one distance (*R - *L) is split into two distances (*R - p) and (p - *L)
        distances.erase(distances.find(*R - *L));
        distances.insert(*R - p);
        distances.insert(p - *L);
        //  Our answer is the last number in the distances mutliset
        multiset<int>::iterator ans = distances.end();
        --ans;
        cout << *ans << " ";
    }
}