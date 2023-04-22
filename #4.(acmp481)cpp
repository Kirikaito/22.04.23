#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int answ = 0,n,j;
    string str;
    cin >> str;
    n = str.size();
    vector<vector<long long>> F(n,vector<long long>(n,0));
    for (int k = 0; k < n; k++){
        for (int i=0; i<n; i++){
            j = i+k;
            if (j==n){break;}
            if (i == j){F[i][j] = 1;}
            else{
                if (str[i] != str[j]){F[i][j] = F[i+1][j] + F[i][j-1] - F[i+1][j-1];}
                else{F[i][j] = F[i+1][j] + F[i][j-1] + 1;}
            }
        }
    }
    cout<<F[0].back();
