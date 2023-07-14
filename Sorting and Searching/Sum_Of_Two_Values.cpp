#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> arr; //number, pos
    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    while (right > left) {
        if (arr[right].first+arr[left].first == target) {
            cout << arr[left].second << ' ' << arr[right].second;
            return 0;
        } else if (arr[left].first+arr[right].first > target) {
            right--;
        } else {
            left++;
        }
    }
    cout << "IMPOSSIBLE";
}