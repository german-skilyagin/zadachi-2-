#include <iostream>
#include <fstream>
#include<vector>


using namespace std;

const int NEW = 0;
const int DURING = 1;
const int VISITED = 2;


void Paint(int cur, const vector<vector<int>>& less, vector<int>& state, bool good)
{
    if (state[cur] == DURING)
    {
        good = false;
        return;
    }
    if (state[cur] == VISITED)
    {
        return;
    }
    else
    {
        state[cur] = DURING;
        for (int next : less[cur])
        {
            Paint(next, less, state, good);
        }
        state[cur] = VISITED;
    }
}

int main()
{

    int nV, nE;
    cin >> nV >> nE;

    vector<vector<int>> less(1 + nV);

    for (int i = 0; i < nE; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        less[v1].push_back(v2);
    }
    vector<int> state(1 + nV, NEW);

    bool good = true;

    for (int i = 1; i < nV; i++)
    {
        if (state[i] == NEW)
        {
            Paint(i, less, state, good);
        }
    }
    if (good)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}