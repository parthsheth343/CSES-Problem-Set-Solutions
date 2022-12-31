#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arrival, departure;
    int ans[200000];
    int rooms = 0;
    vector<pair<pair<ll, ll>, int>> dates; //((arrival, end), i'th customer)
    multiset<pair<ll, int>> s; // (end date, i'th room)

    pair<ll, int> pairI =  make_pair(10e9+1, 0);
    s.insert(pairI);

    for (int i = 0; i < n; i++) {
        cin >> arrival >> departure;
        dates.push_back(make_pair(make_pair(arrival, departure), i));
    }
    sort(dates.begin(), dates.end());

    for (int i = 0; i < n; i++) {
        if (dates[i].first.first <= (*s.begin()).first) {
            rooms++;
            pairI.first = dates[i].first.second;
            pairI.second = rooms;
            s.insert(pairI);
            ans[dates[i].second] = rooms;
        } else {
            pairI.first = dates[i].first.second;
            pairI.second = (*s.begin()).second;
            ans[dates[i].second] = (*s.begin()).second;
            s.erase(s.find(*s.begin()));
            s.insert(pairI);
        }
    }

    cout << rooms << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}