#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "a";
    for (int i = 2; i <= 26; i++) {
        string t = s;
        char c = 'a' + i - 1;
        s = c + t + t;
    }
    cout << s[n - 1] << endl;
    return 0;
}