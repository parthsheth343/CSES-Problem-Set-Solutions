#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

vector<string> getn(int q, vector<string> r) {
    if (q>=3) {
        vector<string> b = r;
        for (int i = 0; i < r.size(); i++) {
            b[i][q-3] = '1';
        }
        reverse(b.begin(), b.end());
        r.insert(r.end(), b.begin(), b.end());
        q--;
        return getn(q, r);
    } 
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    //Have to print all the numbers from 0 to 2^n -1 in binary
    if (n == 1) {cout << 0 << endl << 1 << endl;}
    else if (n == 2) {cout << "00" << endl << "01" << endl << 11 << endl << 10 << endl;}
    else {
        string c1 = "", c2 = "", c3 = "", c4 = ""; char replacement = '1';
        for (int i = 0; i < n; i++) {c1 += "0";}
        for (int i = 0; i < n; i++) {c2 += "0";} c2[n-1] = replacement;
        for (int i = 0; i < n; i++) {c3 += "0";} c3[n-1] = replacement; c3[n-2] = replacement;
        for (int i = 0; i < n; i++) {c4 += "0";} c4[n-2] = replacement;
        vector<string> ccode = {c1, c2, c3, c4}; 

        ccode = getn(n, ccode);
        for (int i = 0; i < ccode.size(); i++) {cout << ccode[i] << endl;}
        
    }
}