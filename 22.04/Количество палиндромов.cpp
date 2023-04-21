#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<vector<long long>> F;
int n;
void in()
{
    cin >> str;
    n = str.size();
    F = vector<vector<long long>>(n, vector<long long>(n, 0));
}
void solve()
{
    int j;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            j = i + k;
            if (j == n) { break; }
            if (i == j) { F[i][j] = 1; }
            else
            {
                if (str[i] != str[j]) { F[i][j] = F[i + 1][j] + F[i][j - 1] - F[i + 1][j - 1]; }
                else { F[i][j] = F[i + 1][j] + F[i][j - 1] + 1; }
            }
        }
    }
    cout << F[0].back();
}
int main()
{
    in();
    solve();
    return 0;
}