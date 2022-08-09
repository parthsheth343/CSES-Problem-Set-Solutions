#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 3) {cout << "YES" << endl << 2 << endl << "1 2" << endl << 1 << endl << "3";}
    else if (n%4 == 0) {
        cout << "YES" << endl;
        cout << n/2 << endl;
        for (int i = 1; i <= n/4; i++){
            cout << i << " " << n+1-i << " ";
        }
        cout << endl << n/2 << endl;
        for (int i = n/4 + 1; i <= n/2; i++){
            cout << i << " " << n+1-i << " ";
        }
    }
    else if (n%4 == 3) {
        cout << "YES" << endl;
        cout << (n-3)/2 + 2 << endl << "1 2 ";
        for (int i = 4; i <= (n+9)/4; i++){
            cout << i << " " << n+4-i << " ";
        }
        cout << endl << (n-3)/2 + 1 << endl << "3 ";
        for (int i = (n+13)/4; i <= (n+3)/2; i++) {
            cout << i << " " << n+4-i << " ";
        }
    }
    else {cout << "NO";}
}