
//#2 Строительство
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int sizeI, sizeJ;
    cin >> sizeI >> sizeJ;
    vector < vector < int >> a(sizeI, vector <int>(sizeJ));
    for (int i = 0; i < sizeI; i++){
        for (int j = 0; j < sizeJ; j++) {
            cin >> a[i][j];
        }
    }
    int Npillars = 0;
    for (int i = 0; i+1 < sizeI; i++) {
        for (int j = 0; j+1 < sizeJ; j++) {
            if (!(a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1])) {
                Npillars++;

            }
        }
    }
    int Nwalls = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j + 1 < sizeJ; j++) {
            if (!(a[i][j] == a[i][j + 1])) {
                Nwalls++;

            }
        }
    }
    for (int i = 0; i + 1 < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (!(a[i][j] == a[i + 1][j])) {
                Nwalls++;

            }
        }
    }
    cout << 0.2 * 0.2 * 3 * Npillars + 0.2 * 0.8 * 3 * Nwalls;
    return 0;
}













