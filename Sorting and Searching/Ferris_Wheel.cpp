#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;

    cin >> n >> x;
    const int N = n;
    int weights[N];

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    sort(weights, weights+N);

    int j = N-1;
    int i = 0;

    while (i < j) {
        if (weights[i] + weights[j] <= x) {
            if (i == j-2) {
                ans+=2;
                break;
            }
            ans++;
            i++;
            j--;
        } else {
            if (i == j-1) {
                ans+=2;
                break;
            }
            ans++;
            j--;
        }
    }
    cout << ans;
}