#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;
    sort(n.begin(), n.end());
    int final1 = 0;
    do {final1++;} while (next_permutation(n.begin(), n.end()));
    sort(n.begin(), n.end());
    cout<<final1<<endl;
    do {cout << n << endl;} while (next_permutation(n.begin(), n.end()));
}