#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long
 
ll arr[200001];
ll fenwick[200001];
ll n;
 
void modify(ll k, ll u) {
    ll change = u - arr[k];
    arr[k] = u;
 
    while (k <= n) {
        fenwick[k] += change;
        k += (k&-k);
    }
}
 
ll sum(ll x) {
    ll s = 0;
    while (x >= 1) {
        s += fenwick[x];
        x -= (x&-x);
    }
    return s;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> arr[i];
 
    //initializing the binary indexed tree
    for (ll i = 1; i <= n; i++) {
        fenwick[i] += arr[i];
        if (i + (i&-i) <= n) {
            fenwick[i + (i&-i)] += fenwick[i];
        }
    }
 
    ll a, b, c;
    for (ll i = 1; i <= q; i++) {
        cin >> a >> b >> c;
        if (a == 1) modify(b, c);
        else {
           ll z = sum(c) - sum(b-1);
           cout << z << endl;
        
        }
    }
}