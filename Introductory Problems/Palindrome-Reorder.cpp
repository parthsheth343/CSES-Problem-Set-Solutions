//Inefficient Solution but works

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n; int equal=1; bool solution= true; string final = ""; int l=0;
    int odds=0; string odd="";int f; int g; bool detectedodd = false; string k;
    cin >> n;
    sort(n.begin(), n.end());
    if (n.size()==1) {cout << n << endl;}
    else if ((int)n.size() %2 == 0) {
        for (int i = 1; i < (int) n.size(); i++) {
            if (n[i] == n[i-1]) {
                equal++;
            }
            else {
                if ((int) equal%2 == 0) {equal = 1;}
                else {cout << "NO SOLUTION"<<endl; solution = false;}
            }
            if (!solution) {break;}
        }
        if (solution) {
            for (int i = 0; i < (int) n.size(); i+=2) {
                cout << n[i];
            }
            for (int i =  n.size()-1; i >0; i-=2){
                cout << n[i];
            }

        }
    }
    else {
        k=n;
        for (int i = 1; i < (int) n.size(); i++) {
            if (n[i] == n[i-1]) {
                equal++;
            }
            else {
                if ((int) equal%2 == 0) {equal = 1;}
                else {
                    odds++;
                    detectedodd = true;
                    if (odds == 2) {
                        cout << "NO SOLUTION"<<endl; solution = false;  
                    }
                    if (solution) {odd = k.substr(i-equal, equal);
                    f = (int) i - (int) equal; g = (int) equal; l = (int) equal;
                    k.erase((int)i-equal, (int)equal); equal = 1;}
                }
            }
            if (!solution) {break;}
        }
        if (l == 0) {l = equal;}
        if (!detectedodd){odd = k.substr((int) n.size() -(int) l, (int) equal);k.erase((int) n.size()-(int) l, (int) equal);} 
        if (solution) {
            n=k;
            final = odd;
            for (int i = 0; i < n.size(); i+=2) {cout << n[i];}
            for (int i = 0; i < odd.size(); i++) {cout << odd[i];}
            for (int i = n.size()-1; i>0; i-=2) {cout << n[i];}
        }
    }
}