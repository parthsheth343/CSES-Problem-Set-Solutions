#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    vector<pair<ll, ll>> movies;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies.push_back({b, a}); 
    }
    sort(movies.begin(), movies.end()); //sorted by end times
    int lastmovie = 0;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (movies[i].second >= movies[lastmovie].first) {
            lastmovie = i;
            ans++;
        }
    }
    cout << ans;
}