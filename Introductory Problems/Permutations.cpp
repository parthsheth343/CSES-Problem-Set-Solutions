#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; vector<int> permutation;
    cin >> n;
    if (n == 1) {cout << 1;}
    else if (n == 2 or n == 3) {cout << "NO SOLUTION";}
    else {
        if (n%2 == 0) {
            for (int i = 3; i < n; i=i+2) {permutation.push_back(i);}
            permutation.push_back(1);
            for (int i = n; i >=2; i=i-2) {permutation.push_back(i);}
        }
        else {
            for (int i = 2; i < n; i=i+2) {permutation.push_back(i);}
            permutation.push_back(1);
            for (int i = n; i >=3; i=i-2) {permutation.push_back(i);}
        }
        for (int i = 0; i < permutation.size(); i++) {cout << permutation[i] << " ";}
    }
}