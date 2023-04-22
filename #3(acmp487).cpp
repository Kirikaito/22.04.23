#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,p,r;
    vector<char> answ;
    cin >> n >> k >> p;
    for(int i = 0;i<p;i++){
        cin >> r;
        if((r == (n % (k + 1))) || ((n % (k + 1)) == 0)){answ.push_back('T');}
        else{answ.push_back('F');}
        n -= r;
    }
    for(auto i : answ){cout << i << endl;}
}
