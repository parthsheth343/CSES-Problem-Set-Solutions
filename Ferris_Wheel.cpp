#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, x; //n = number of kids, x = max allowed weight
    
    int ans = 0;
    cin >> n >> x;
    int weights[1000000];
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    int j = 0;
    for (int i = n-1; i > j; i--) {

        if (weights[i] + weights[j] <= x) {
            j++;
            ans++;
        } else {ans++;}
    }
    cout << ans << endl;
    
}