#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
    string a;
    string b;
    string c;
    int num, res[5];
    float mid_s;
public:
    Student(string a_1, string a_2, string a_3, int n, float result[5])
    {
        a = a_1;
        b = a_2;
        c = a_3;
        num = n;
        float summa = 0;
        for (int i = 0; i < 5; ++i) {
            res[i] = result[i];
            sum += result[i];
        }
        mid_s = summa / 5.0;
    }
    bool prt() { return (mid_s > 4.2); }
    void Print() { cout << b << ' ' << a << ' ' << c << ' ' << numb << endl; }
};
int main()
{
    vector <Student> Group;

    string a_0, b_0, c_0;
    int numer, fl = 0;
    float k[5];
    for (int i = 0; i < 10; ++i) {
        cin >> a_0 >> b_0 >> c_0 >> numer;
        for (int j = 0; j < 5; ++j) {
            cin >> lis[j];
        }
        Group.push_back(Student(b_0, a_0, c_0, numer, k));
    }
    for (auto& i : Group) {
        if ((i).prt()) {
            fl = 1;
            (i).Print();
        }
    }
    if (fl == 0) { cout << "NOT THEIR STUDENT"; }
}