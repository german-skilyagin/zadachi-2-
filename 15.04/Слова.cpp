#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    char buff[50000 + 1];
    cin >> buff;
    string src(buff);
    cin >> buff;
    string dst(buff);
    if (src.size() != dst.size()) { cout << "NO"<< endl; return 0; }
    string s = dst + "#" + src;
    vector <int> prefix(1 + s.size(), 0);
    int len = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (1) {
            if (s[i] == s[len]) { len++; break; }
            if (len == 0) { break; }
            len = prefix[len];
        }
        prefix[i + 1] = len;
    }
    for (int i = 0; i < (int)src.size() - len; i++) {
        if (src[i] != dst[(int)dst.size() - 1 - i]) { cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl << (int)src.size() - len << endl;
    return 0;
}