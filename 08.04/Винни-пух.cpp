#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mass(int m, int n) {
    vector<vector<int>> mass_1(m, vector<int>(n, 0));
    int count = 0;
    int i = 0, j = 0;
    int si = 0, sj = 1;

    for (int k = 0; k < m * n; k++)
    {
        count++;
        mass_1[i][j] = count;
        if (mass_1[(i + si + m) % m][(j + sj + n) % n] != 0 || (i + si < 0 || i + si >= m || j + sj < 0 || j + sj >= n)) {
            int temp = si;
            si = sj;
            sj = -temp;
        }
        i += si;
        j += sj;
    }
    return mass_1;
}

int main() {
    int m = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    cin >> m >> n >> y >> x;
    vector<vector<int>> mass_1 = mass(m, n);
    cout << mass_1[y - 1][x - 1] << endl;
    return 0;
}