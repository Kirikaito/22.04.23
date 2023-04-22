#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void recalc(int x, int y, vector <vector <int>> &a) {  
    if (a[x - 1][y] > a[x][y] + 1 && a[x - 1][y] !=1000) { 
        a[x - 1][y] = a[x][y] + 1;
    }

    if (a[x - 2][y] > a[x][y] + 2 && a[x - 1][y] != 1000) {
        a[x - 2][y] = a[x][y] + 2;
        recalc(x - 2, y, a);
    }
    
    if (a[x][y+1] > a[x][y] + 1 && a[x][y+1] != 1000) { 
        a[x][y+1] = a[x][y] + 1;
    }

    if (a[x][y+2] > a[x][y] + 2 && a[x][y+2] != 1000) {
        a[x][y+2] = a[x][y] + 2;
        recalc(x, y + 2, a);
    }

    if (a[x + 1][y] > a[x][y] + 1 && a[x + 1][y] != 1000) { 
        a[x + 1][y] = a[x][y] + 1;
    }

    if (a[x + 2][y] > a[x][y] + 2 && a[x + 1][y] != 1000) {
        a[x + 2][y] = a[x][y] + 2;
        recalc(x + 2, y, a);
    }

    if (a[x][y - 1] > a[x][y] + 1 && a[x][y - 1] != 1000) { 
        a[x][y - 1] = a[x][y] + 1;
    }

    if (a[x][y - 2] > a[x][y] + 2 && a[x][y - 1] != 1000) {
        a[x][y - 2] = a[x][y] + 2;
        recalc(x, y - 2, a);
    }
    return;
}

int main() {
    string s = "";
    cin >> s;
    int nN = 0, nE = 0, nS = 0, nW = 0;
    for (int z = 0; z < s.size(); z++) {
        switch (s[z]) {
            
        case 'N':
            nN++;
            break;

        case 'E':
            nE++;
            break;

        case 'S':
          nS++;
            break;

        case 'W':
            nW++;
            break;
        }

    }

    int sizeSN = (nN + nS) * 2 + 6;
    int sizeEW = (nW + nE) * 2 + 6;
    vector <vector<int>> a(sizeSN, vector<int>(sizeEW, 1000));
    int curX = nN*2+3, curY = nW*2+3;
    int len = 0;
    a[curX][curY] = len;            
    for (int z = 0; z < s.size(); z++) {
        switch (s[z]) {
            
        case 'N':
            curX--;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len; 
            }
            curX--;
            len++;
            
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            break;

        case 'E':
            curY++;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            curY++;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            break;

        case 'S':
            curX++;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            curX++;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            break;

        case 'W':
            curY--;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            curY--;
            len++;
            if (a[curX][curY] == 1000) {
                a[curX][curY] = len;
            }
            break;
        }
    }
    recalc(nN * 2 + 3, nW * 2 + 3, a);
    
    string sBack = "";
    while (a[curX][curY] > 0) {

        char step = 'N';
        int minL = a[curX][curY];
        if (minL > a[curX - 2][curY] && a[curX - 1][curY] != 1000) {
            step = 'N';
            minL = a[curX - 2][curY];
        }

        if (minL > a[curX][curY + 2] && a[curX][curY + 1] != 1000) {
            step = 'E';
            minL = a[curX][curY + 2];
        }

        if (minL > a[curX+2][curY] && a[curX + 1][curY] !=1000) {
            step = 'S';
            minL = a[curX+2][curY];

        }
        if (minL > a[curX][curY - 2] && a[curX][curY - 1] !=1000) {
            step = 'W';
            minL = a[curX][curY - 2];
        }

        sBack += step; 
        switch (step) { 

        case 'N':
            curX -= 2;
            break;

        case 'E':
            curY += 2;
            break;

        case 'S':
            curX += 2;
            break;

        case 'W':
            curY -= 2;
            break;
        }
    }
    cout << sBack;
    return 0;
}
