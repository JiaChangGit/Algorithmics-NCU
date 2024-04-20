#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

class GradeV
{
public:
    GradeV(){};
    ~GradeV(){};
    void setG(int);
    int getG(int);
    void SortG();

private:
    std::vector<int> grade;
};
void GradeV::setG(int inGrade)
{
    grade.push_back(inGrade);
}
int GradeV::getG(int i)
{
    return grade[i];
}
void GradeV::SortG()
{
    std::sort(grade.begin(), grade.end());
}

int main()
{
    int loopNum;
    cin >> loopNum;
    while (loopNum--)
    {
        GradeV G1;
        int inGrade, gradeTh, i;
        i = 20;
        while ( i--)
        {
            cin >> inGrade;
            G1.setG(inGrade);
        }
        G1.SortG();
        cin>> gradeTh;
        cout << G1.getG((gradeTh-1)) << endl;
    }
    return 0;
}