#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int wey(int pos,int end,vector<vector<int>> roads,vector<int> costs,int steps,int max_steps){
    if(roads[pos][end] == 1){return costs[pos];}
    else{
        vector<int> answ;
        int a = 0,b = 0;
        for(int i = 0;i < end;i++){
            if(steps == max_steps){return -1;}
            if(roads[pos][i] == 1){
                b = wey(i,end,roads,costs,steps + 1,max_steps);
                if(b > 0){a = costs[pos] + b;}
                else{a = b;}
            }
            if(a > 0){answ.push_back(a);}
        }
        if(answ.size() == 0){return -1;}
        return *min_element(answ.begin(), answ.end());
    }
}
int main()
{
    int m,n,in,jn,pos,Min;
    vector<vector<int>> roads;
    vector<int> costs,city_roads;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> in;
        costs.push_back(in);
        city_roads.push_back(0);
    }
    for(int i = 0; i < n;i++){
        roads.push_back(city_roads);
    }
    cin >> m;
    for(int i = 0; i < m;i++){
        cin >> in;
        cin >> jn;
        roads[in - 1][jn - 1] = 1;
        roads[jn - 1][in - 1] = 1;
    }
    cout << wey(0,n - 1,roads,costs,0,m);

}
