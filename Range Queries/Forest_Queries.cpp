#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    const int N = n;
    int forest[N+1][N+1];
    for (int i = 0; i < n+1; i++) { //rows , y
        for (int j = 0; j < n+1; j++) { //columns, x
            forest[i][j] = 0;
        }
    }
    char f;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> f;
            forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
            if (f == '*') forest[i][j]++;
        }
    }
    int a, b, c, d;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c >> d;
        cout << forest[c][d] - forest[a-1][d] - forest[c][b-1] + forest[a-1][b-1] << endl;
    }
}