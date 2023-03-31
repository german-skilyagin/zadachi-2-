#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int m,n,sum = 0;
    set<int> NOD,tim;
    vector<pair<set<int>,int>> answ;
    pair<set<int>,int> cash;
    
    cin >> m >> n;
    
    for(int i = 2; i <= (float)n/2; i++){
        if(n%i == 0){NOD.insert(i);}
    }
    NOD.insert(n);
    
    for(auto i : NOD){sum += n/i;}
    if(sum < m){
        cout << "Can't be splitted acording to the rule";
        return 0;
    }
    
    for(auto i : NOD){
        cash.first.insert(i);
        cash.second = n/i;
        answ.push_back(cash);
        cash.first.erase(i);
    }
    
    for(auto p : NOD){
        for(auto q : answ){
            cash.first = q.first;
            cash.first.insert(p);
            if(q.first.size() != cash.first.size() and q.second + n/p <= m){
                cash.second = n/p + q.second;
                answ.push_back(cash);
            }
        }
    }
    sort(answ.begin(),answ.end());
    
    for(auto a : answ){
        if(a.second == m){
            for(auto b : a.first){
                cout << b << ' ';
            }
            break;
        }
    }
}