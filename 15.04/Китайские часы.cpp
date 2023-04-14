#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    char  c;
    vector<int> secs(n);

    for (int i = 0; i < n; i++) {
        int h, min, sec;
        cin >> h >> c >> min >> c >> sec;
        int timeInSeconds = h * 3600 + min * 60 + sec;
        secs[i] = timeInSeconds;
    }

    int bestTime = secs[0];
    int mtd = abs(secs[0] - (2 * 3600 * n));

    for (int i = 0; i < n; i++) {
        int timeDifference = abs((2 * 3600 * n) - 2 * secs[i]);
        if (timeDifference < mtd) {
            mtd = timeDifference;
            bestTime = secs[i];
        }
    }

    int hours = bestTime / 3600;
    int minutes = (bestTime % 3600) / 60;
    int seconds = bestTime % 60;
    if (hours == 0) { hours = 12; }
    if (hours > 12) { hours -= 12; }
    if (hours < 10) { cout << hours << ":" <<  minutes << ":" << seconds; }
    else { cout << hours << ":" << minutes << ":" << seconds; }
    return 0;
}