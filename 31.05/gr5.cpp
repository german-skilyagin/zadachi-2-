#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tasks[i] = make_pair(t, i + 1);
    }
    sort(tasks.begin(), tasks.end()); 
    vector<int> solution;
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += tasks[i].first; 
        solution.push_back(tasks[i].second);
    }
    cout << "Solution order: ";
    for (int i = 0; i < n; i++) {
        cout << solution[i] << " ";
    }
    cout << endl;
    return 0;
}