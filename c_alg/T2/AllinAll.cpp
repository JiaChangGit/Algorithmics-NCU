/*
給你2個字串s,t，請你寫一個程式判斷是否s是t的子字串。也就是說當你移走t字串中的某些字元後，剩下的字串就是s。
Input
第一個數字為幾組測資，之後每筆測試資料一列。每列有2個字串，s及t，以空白分隔。
Output
對每一列輸入，請輸出是否s是t的子字串。
Sample Input
5
abc abc
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
Sample Output
Yes
Yes
No
Yes
No
*/
#include <iostream>
#include <string.h>
using namespace std;

bool AllinAll(string s, string t)
{
    int n = 0;
    for (int i = 0; i < t.length() && n < s.length(); i++)
        if (t[i] == s[n])
            n++;
    return n == s.length();
}
int main()
{
    string s, t;
    int size;
    cin >> size;
    bool *resultptr = new bool[size];
    int i;
    for (i = 1; i <= size; ++i)
    {
        cin >> s >> t;
        *(resultptr + i - 1) = AllinAll(s, t);
    }
    for (i = 1; i <= size; ++i)
    {
        if (*(resultptr + i - 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}