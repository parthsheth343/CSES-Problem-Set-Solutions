#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll arr[200001];
ll presum[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        presum[i] = arr[i] + presum[i-1];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << presum[b] - presum[a-1] << endl;
    }
}