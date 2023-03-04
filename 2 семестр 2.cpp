#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
    string a;
    string a_2;
    string a_3;
    int num, resul[5];
    float midd_s;
public:
    Student(string b, string b_2, string b_3, int n, float res[5])
    {
        a = b;
        a_2 = b_2;
        a_3 = b_3;
        num = n;
        float sum = 0;
        for (int i = 0; i < 5; ++i) {
            resul[i] = res[i];
            sum += res[i];
        }
        midd_s = sum / 5.0;
    }
    bool T() {
        return (midd_s > 4.2);
    }
    void Inf() {
        cout << a_2 << ' ' << a << ' ' << a_3 << ' ' << num << endl;
    }
};
int main()
{
    vector <Student> Gr;

    string c_1, c_2, c_3;
    int num, flag = 0;
    float lis[5];
    for (int i = 0; i < 10; ++i) {
        cin >> c_1 >> c_2 >> c_3 >> num;
        for (int j = 0; j < 5; ++j) {
            cin >> lis[j];
        }
        Gr.push_back(Student(c_1, c_2, c_3, num, lis));
    }
    for (auto& i : Gr) {
        if ((i).T()) {
            flag = 1;
            (i).Inf();
        }
    }
    if (flag == 0) {
        cout << "not student";
    }
}