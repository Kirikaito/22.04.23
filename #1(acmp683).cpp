#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,in,answ = 0, Min,next,pos;
    cin >> n;
    vector<int> origin;
    for(int i = 0; i<n;i++){
        cin >> in;
        origin.push_back(in);
    }
    while(n > 2){
        Min = origin[0] + origin[2];
        for(int i = 1; i < n - 1;i++){
            next = origin[i - 1] + origin[i + 1];
            Min = min(Min,next);
            if(Min == next){
                pos = i;
            }
        }
        n--;
        answ += Min*origin[pos];
        origin.erase(origin.begin() + pos);
        cout << answ << endl;
        
    }
    cout << answ;
    return 0;
}
