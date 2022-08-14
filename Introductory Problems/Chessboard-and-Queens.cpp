#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

//Simple solution using recursion
string chessboard[8]; //8 rows of strings are inputted and are stored here
int answer = 0; //This is the total number of valid positions
bool queencol[8] = {0}; //There are 8 columns a queen can be on hence the size of the array
bool ldiagnol[15] = {0}; //There are 15 diagnols going left and up. indexed by col - row + 7 (0 ... 14)
bool rdiagnol[15] = {0}; //There are diagnols going right and up. indexed by row + col (0 ... 14)

void solve(int r) { //Going through all the spots in the r'th row [starting from row 0 to 7]
    if (r == 8) {answer++; return;} //This means all the rows (0-7) are valid = +1 solution
    for (int c = 0; c < 8; c++) { //This iterates through all the columns in the row
        //The if statement checks for if this spot is valid
        if (chessboard[r][c]=='.' && !ldiagnol[c-r+7] && !rdiagnol[c+r] && !queencol[c]) {
            queencol[c] = 1; //We will set a queen on this spot (so its also in the column)
            rdiagnol[c+r] = 1; //This diagnol is taken now
            ldiagnol[c-r+7] = 1; //This diagnol is taken now
            solve(r+1); //Now we will recurse for the next row considering this spot to now be taken
            queencol[c] = 0; //Back to this row now, so we will remove the queen from this spot
            rdiagnol[c+r] = 0; //Clearing this diagnol as we are removing the queen
            ldiagnol[c-r+7] = 0; //Also clearing this diagnol as we are removing the queen
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; i++) {
        cin >> chessboard[i];
    }
    solve(0);
    cout << answer;
}