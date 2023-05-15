#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

int twoTen(string binStr) {
    int a = 0;
    for (int i = binStr.size() - 1; i >= 0; i--) {
        a = a * 10 + (binStr[i] - '0');
    }
    cout << a;
    return 0;
}

int main() {
    int n;
    cin >> n;
    if (n > 1) {
        string ans = "1";
        bitset<100000> testAns;
        testAns.set(0);
        for (int k = 2; k <= n; k++) {
            bitset<100000> testPow(pow(k, 2));
            if ((testAns & testPow).any()) {
                ans = "1" + ans;
                testAns |= testPow;//|=	Побитовое включающее ИЛИ/назначение
            }
            else {
                ans = "2" + ans;
            }
            testAns.set(0);
        }
        twoTen(ans);
    }
    else {
        string ans = "2";
        bitset<100000> testAns;
        testAns.set(0);
        for (int k = 2; k <= n; k++) {
            bitset<100000> testPow(pow(k, 2));
            if ((testAns & testPow).any()) {
                ans = "1" + ans;
                testAns |= testPow;//|=	Побитовое включающее ИЛИ/назначение
            }
            else {
                ans = "2" + ans;
            }
            testAns.set(0);
        }
        twoTen(ans);
    }
}
