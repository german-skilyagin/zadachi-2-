#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;



int main()
{
    int n;
    cin >> n;
    vector < int> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    vector<vector<int>> minScore(n, vector<int>(n));
    for (int len = 2; len <= n; len++) {
        for (int left = 0; left + len - 1 < n; left++) {
            int right = left + len - 1;
            if (len == 2) { minScore[left][right] = 0; }
            else {
                minScore[left][right] = 2000 * 1000 + 1;
                for (int midd = left + 1; midd <= right - 1; midd++) {
                    minScore[left][right] = min(minScore[left][right], a[midd] * (a[left] + a[right]) + minScore[left][midd] + minScore[midd][right]);
                }
                assert(minScore[left][right] < 2000 * 1000 + 1);
            }
        }
    }
    cout << minScore[0][n - 1];
    return 0;
}