#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int si, sj;
    cin >> si >> sj;
    vector < vector < char > > a(si, vector <char>(sj));
    for (int i = 0; i < si; i++) {
        char buff[1000 + 1];
        cin >> buff;
        for (int j = 0; j < sj; j++) {
            a[i][j] = buff[j];
        }
    }
    int mini = si;
    int maxi = -1;
    int minj = sj;
    int maxj = -1;
    for (int i = 0; i < si; i++) {
        for (int j = 0; j < sj; j++) {
            if (a[i][j] == '*') {
                mini = min(mini, i);
                maxi = max(maxi, i);
                minj = min(minj, j);
                maxj = max(maxj, j);
            }
        }
    }
    for (int rmini = mini - 1; rmini <= mini + 1; rmini++) {
        for (int rmaxi = maxi - 1; rmaxi <= maxi + 1; rmaxi++) {
            for (int rminj = minj - 1; rminj <= minj + 1; rminj++) {
                for (int rmaxj = maxj - 1; rmaxj <= maxj + 1; rmaxj++) {
                    if (rmaxi - rmini == rmaxj - rminj && rmaxi - rmini >= 2 && rmini >= 0 && rmaxi < si && 0 <= rminj && rmaxj < sj) {
                        bool good = true;
                        for (int i = rmini + 1; i <= rmaxi - 1 && good; i++) {
                            for (int j = rminj + 1; j <= rmaxj - 1 && good; j++) {
                                if (a[i][j] != '*') {
                                    good = false;
                                }
                            }
                        }
                        if (good) {
                            cout << "SQUARE" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "CIRCLE" << endl;
    return 0;
}
