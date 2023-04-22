#include <iostream>
#include <vector>
#include <limits.h>
 
using namespace std;

int main()
{
    int n,E,F;
    cin >> E >> F >> n;
    vector<int> P(n),W(n),MAX(F - E + 1,INT_MIN),MIN(F - E + 1,INT_MAX);
    for (int i=0;i<n;i++){cin >> P[i] >> W[i];}
    MIN[0] = 0;
    MAX[0] = 0;
    for (int i = 0;i<MIN.size();i++){
        for (int j=0;j<W.size();j++){
            if (i - W[j]>=0 && MIN[i-W[j]]!=INT_MAX){
                MIN[i] = min(MIN[i],MIN[i-W[j]] + P[j]);
                MAX[i] = max(MAX[i],MAX[i-W[j]] + P[j]);
            }
        }
    }
    if (MIN.back()==INT_MAX){cout<<"This is impossible.";}
    else{cout<<MIN.back()<<' '<<MAX.back();}
    return 0;
}
