#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; //n = number of kids, x = max allowed weight
    int ans = 0;
    cin >> n >> x;
    int weights[200010];
    bool breaker = false;
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    int j = 0;
    for (int i = n-1; i > j; i--) {
        if (i-j<3) {
            if (i-j == 2){
                if (weights[i]+weights[j] <=x) {ans+=2;} 
                else if (weights[i-1]+weights[j] <= x) {ans+=2;} 
                else {ans+=3;} 
                breaker= true;
            }
            else if (i-j==1){
                if (weights[i] + weights[j] <=x){ans++;} else {ans+=2;} 
                breaker = true;
            } else {ans++; breaker = true;}
        }
        if (breaker) {break;}
        if (weights[i] + weights[j] <= x) {
            j++;
            ans++;
        } else {ans++;}
    }
    cout << ans << endl;   
}