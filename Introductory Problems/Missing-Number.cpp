#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, x;
    cin >>t;
    bool lastno = true;
    vector<int> numbers;
    for (ll i = 0; i < t-1; i++) {cin >> x; numbers.push_back(x);}
    sort(numbers.begin(), numbers.end());
    for (ll i = 0; i < (ll) numbers.size(); i++) {
        if (numbers[i] != i+1) {cout << i+1; lastno = false; break;}
    }
    if (lastno) {cout <<t;}
    
}