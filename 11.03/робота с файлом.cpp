#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName, str = "";
    char ch = '\n';
    cin >> fileName;
    ifstream myfile(fileName.c_str());
    if (myfile.is_open()) {
        while (myfile) {
            cout << str << endl;
            getline(myfile, str);
        }
    }
    ofstream out(fileName.c_str());
    return 0;
}