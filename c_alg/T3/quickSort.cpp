/*
Pivot都是取最右邊的元素

最後一個數後面不用空格。

Sample input
85 24 63 50 17 51 96 58
Sample output
85 24 63 50 17 51 96 58
51 24 63 50 17 85 96 58
51 24 17 50 63 85 96 58
51 24 17 50 58 85 96 63
17 24 51 50 58 85 96 63
17 24 50 51 58 85 96 63
17 24 50 51 58 63 96 85
17 24 50 51 58 63 85 96
*/
#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> &v1)
{
    vector<int>::iterator it;
    for (it = v1.begin(); it != (v1.end() - 1); ++it)
        cout << *it << " ";
    cout << *it;
    cout << endl;
}
void Quick(vector<int> &v1, int lb, int rb)
{
    if (lb >= rb)
        return;
    int piv = v1[rb];
    int l = lb;
    int r = rb - 1;
    while (true)
    {
        if (v1[l] < piv && l < rb)
            ++l;
        else if (v1[r] >= piv && r > lb)
            --r;
        else if (l < r)
        {
            swap(v1[l], v1[r]);
            Print(v1);
        }
        else
            break;
    }
    //if (v1[rb] < v1[l])
    //{
        swap(v1[rb], v1[l]);
        Print(v1);
    //}
    Quick(v1, lb, l - 1);
    Quick(v1, l + 1, rb);
    return;
}
int main()
{
    vector<int> v1;
    int tmp;
    while (cin >> tmp)
    {
        v1.push_back(tmp);
        if (cin.get() == '\n')
            break;
    }
    Print(v1);
    Quick(v1, 0, v1.size() - 1);
    return 0;
}