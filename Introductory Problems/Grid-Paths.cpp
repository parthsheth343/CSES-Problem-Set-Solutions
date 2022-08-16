//Could use further optimization but passes all test cases (worst time 0.5 seconds)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"

bool isTaken[9][9]; //9x9 grid but all the walls are set to 1, so only a 7x7 grid is available
string directions = ""; //This will be used as the input in function main
char dir[48]; //Each spot in this array will be filled with a direction or '?'
int move = 0;
int currentrow = 1;
int currentcol = 1;
int paths = 0;

void tryPath(int move, int currentrow, int currentcol);
bool isLegal(int move, int currentrow, int currentcol, char direction);

int main() {
    for (int i = 0; i < 9; i++) { //Setting all the borders of the grid to true (taken)
        isTaken[i][0] = 1;
        isTaken[i][8] = 1;
        isTaken[0][i] = 1;
        isTaken[8][i] = 1;
    }
    isTaken[1][1] = 1; //The starting square is taken
    cin >> directions; //Inputting the directions/path. Has length of 48
    for (int i = 0; i <= 47; i++) {dir[i] = directions[i];}
    tryPath(0, 1, 1); //moves are indexed from 0-47 (48 moves total)
    cout << paths << endl;
}

bool isLegal(int nextmove, int tryrow, int trycol, char direction) {
    if (isTaken[tryrow][trycol] == 1) {return false;}
    if (tryrow == 7 && trycol == 1 && nextmove == 48) {return true;}
    if (tryrow == 7 && trycol == 1 && nextmove != 48) {return false;}
    if (tryrow < 1 || tryrow > 7 || trycol < 1 || trycol > 7) {return false;}
    switch (direction) {
        case 'L': {
            if (isTaken[tryrow][trycol-1]==1 && isTaken[tryrow+1][trycol]==0 && isTaken[tryrow-1][trycol]==0) {
                return false;
            }
            break;
        }
        case 'R': {
            if (isTaken[tryrow][trycol+1]==1 && isTaken[tryrow+1][trycol]==0 && isTaken[tryrow-1][trycol]==0) {
                return false;
            }
            break;
        }
        case 'U': {
            if (isTaken[tryrow-1][trycol]==1 && isTaken[tryrow][trycol+1]==0 && isTaken[tryrow][trycol-1]==0) {
                return false;
            }
            break;
        }
        case 'D': {
            if (isTaken[tryrow+1][trycol]==1 && isTaken[tryrow][trycol+1]==0 && isTaken[tryrow][trycol-1]==0) {
                return false;
            }
            break;
        }
    }
    switch (direction) {
        case 'L': {
            trycol++;
            if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow+1][trycol]==0) {
                if (direction != 'D') {return false;}
            } else if (isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow-1][trycol]==0) {
                if (direction != 'U') {return false;}
            } else if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow][trycol-1]==0) {
                if (direction != 'L') {return false;}
            } else if (isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow][trycol+1]==0) {
                if (direction != 'R') {return false;}
            } else {;}
            trycol--;
            break;
        }
        case 'R': {
            trycol--;
            if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow+1][trycol]==0) {
                if (direction != 'D') {return false;}
            } else if (isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow-1][trycol]==0) {
                if (direction != 'U') {return false;}
            } else if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow][trycol-1]==0) {
                if (direction != 'L') {return false;}
            } else if (isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow][trycol+1]==0) {
                if (direction != 'R') {return false;}
            } else {;}
            trycol++;
            break;
        }
        case 'U': {
            tryrow++;
            if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow+1][trycol]==0) {
                if (direction != 'D') {return false;}
            } else if (isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow-1][trycol]==0) {
                if (direction != 'U') {return false;}
            } else if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow][trycol-1]==0) {
                if (direction != 'L') {return false;}
            } else if (isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow][trycol+1]==0) {
                if (direction != 'R') {return false;}
            } else {;}
            tryrow--;
            break;
        }
        case 'D': {
            tryrow--;
            if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow+1][trycol]==0) {
                if (direction != 'D') {return false;}
            } else if (isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow-1][trycol]==0) {
                if (direction != 'U') {return false;}
            } else if (isTaken[tryrow+1][trycol-1]==1 && isTaken[tryrow-1][trycol-1]==1 && isTaken[tryrow][trycol-1]==0) {
                if (direction != 'L') {return false;}
            } else if (isTaken[tryrow+1][trycol+1]==1 && isTaken[tryrow-1][trycol+1]==1 && isTaken[tryrow][trycol+1]==0) {
                if (direction != 'R') {return false;}
            } else {;}
            tryrow++;
            break;
        }
    }
    return true;
}

void tryPath(int move, int currentrow, int currentcol) {
    if (move == 48) {
        paths++;
        return;
    }
    if (dir[move] != '?') {
        switch (dir[move]) {
            case 'L': {
                if (isLegal(move+1, currentrow, currentcol-1, 'L')) {
                    isTaken[currentrow][currentcol-1] = 1;
                    tryPath(move+1, currentrow, currentcol-1);
                    isTaken[currentrow][currentcol-1] = 0;
                } else {return;}
                break;
            }
            case 'R': {
                if (isLegal(move+1, currentrow, currentcol+1, 'R')) {
                    isTaken[currentrow][currentcol+1] = 1;
                    tryPath(move+1, currentrow, currentcol+1);
                    isTaken[currentrow][currentcol+1] = 0;   
                } else {return;}
                break;
            }
            case 'U': {
                if (isLegal(move+1, currentrow-1, currentcol, 'U')) {
                    isTaken[currentrow-1][currentcol] = 1;
                    tryPath(move+1, currentrow-1, currentcol);
                    isTaken[currentrow-1][currentcol] = 0;
                } else {return;}
                break;
            }
            case 'D': {
                if (isLegal(move+1, currentrow+1, currentcol, 'D')) {
                    isTaken[currentrow+1][currentcol] = 1;
                    tryPath(move+1, currentrow+1, currentcol);
                    isTaken[currentrow+1][currentcol] = 0;
                } else {return;}
                break;
            }
        }
    } 
    else {
        if (isLegal(move+1, currentrow, currentcol-1, 'L')) {
            isTaken[currentrow][currentcol-1] = 1;
            tryPath(move+1, currentrow, currentcol-1);
            isTaken[currentrow][currentcol-1] = 0;
        }
        if (isLegal(move+1, currentrow, currentcol+1, 'R')) {
            isTaken[currentrow][currentcol+1] = 1;
            tryPath(move+1, currentrow, currentcol+1);
            isTaken[currentrow][currentcol+1] = 0;   
        }
        if (isLegal(move+1, currentrow-1, currentcol, 'U')) {
            isTaken[currentrow-1][currentcol] = 1;
            tryPath(move+1, currentrow-1, currentcol);
            isTaken[currentrow-1][currentcol] = 0;
        }
        if (isLegal(move+1, currentrow+1, currentcol, 'D')) {
            isTaken[currentrow+1][currentcol] = 1;
            tryPath(move+1, currentrow+1, currentcol);
            isTaken[currentrow+1][currentcol] = 0;
        }
    }
}

