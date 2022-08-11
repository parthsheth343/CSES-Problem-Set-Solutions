#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

void Hanoi(int n, int source, int destination, int space) {
    if (n == 0) {return;}
    Hanoi(n-1, source, space, destination);
    cout << source << " " << destination << endl;
    Hanoi(n-1, space, destination, source);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int disks;
    cin >> disks;
    cout << (ll) pow(2, disks)-1<<endl;
    Hanoi(disks, 1, 3, 2);
}