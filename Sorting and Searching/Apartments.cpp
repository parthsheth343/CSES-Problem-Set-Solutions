#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, ans=0;
    cin >> n >> m >> k;

    const int N = n;
    int desired[N];

    for (int i = 0; i < N; i++) {
        cin >> desired[i];
    }

    const int M = m;
    int apartments[M];

    for (int i = 0; i < M; i++) {
        cin >> apartments[i];
    }
    
    sort(desired, desired + N);
    sort(apartments, apartments + M);

    int i = 0, j = 0;
    while (i < N && j < M) {
        if (abs(desired[i] - apartments[j]) <= k) {
            i++;
            j++;
            ans++;
        } else if (desired[i] - apartments[j] > k) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans;
}
