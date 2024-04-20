/*
給定一個數字N及N個字符串Title ，N代表測資個數，Title表示工作表中出現的列標題，返回其對應的列號。
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
Sample Input:
3
A
AB
ZY
Sample Output:
1
28
701
Constraints:
●	1 <= Title <= 7
●	Title consists only of uppercase English letters.
●	Title is in the range ["A", "FXSHRXW"].
*/
#include <iostream>
using namespace std;
int CN(string s)
{
    int number = 0;

    for (const auto &c : s)
    {
        number *= 26;
        number += c - 'A' + 1;
    }

    return number;
}

int main(void)
{
    int sizes;
    cin >> sizes;
    string col;
    int *result = new int[sizes];
    int i;
    for (i = 1; i <= sizes; ++i)
    {
        cin >> col;
        *(result + i - 1) = CN(col);
    }

    for (i = 1; i <= sizes; ++i)
        cout << *(result + i - 1) << endl;
    delete[] result;
    return 0;
}