/*
在這個問題你必須解一個非常簡單的一元一次方程式(不含括號)。像下面這個方程式：

2x - 4 + 5x + 300 = 98x
在這個方程式中一定有一個等號，等號的兩邊各有一個運算式。
運算式為一個或多個項組成，中間用 '+' 或 '-' 連接。運算式中不會有不需要的加或減出現，
例如不會有這樣的運算式：5+-3 或 5--3或 5-+3或5++3。總之就跟你國中剛學代數時的運算式一樣。
每一項要嘛就是一個整數，要嘛就是一個整數後面緊接一個小寫的字元 x 或是單一 x (代表 1x )。
請你找出 x 的值以滿足此方程式。
注意: 方程式也有可能 無解 或是 無限多解，你的程式也必須可以判斷出來。

Input
輸 入的第一列有一個整數代表共有多少筆測資。
每 筆測資一列，就是你要求解的方程式。一列的長度最多255個字元。在方程式中沒有空白，要求的未知數一定是小寫 x ，係數都是整數且範圍為 0~1000(包含)
Output
每 組測資輸出一 列，輸出方程式的解。假如 s 是這個解，請輸出小於或等於  s 的最大整數。例如: 如果s=3.6 ，則輸出3。如果s=-3.6 ，則輸出 -4。
假如方程式沒有解，請輸出 IMPOSSIBLE。如果有無限多解，請輸出 IDENTITY。

Sample Input
6
2x-4+5x+300=98x
x+2=2+x
3x=3x-6
9x=30+6-x
30+6+x=-9x
x+2x+3x-4x+600=4x-3x-100

Sample Output
3
IDENTITY
IMPOSSIBLE
3
-4
-700
*/
#include <iostream>

using namespace std;
class Solution
{
public:
    string solveEquation(string equation)
    {
        int a = 0, b = 0;
        auto found = equation.find("=");
        helper(equation.substr(0, found), true, a, b);
        helper(equation.substr(found + 1), false, a, b);
        if (a == 0 && a == b)
            return "IDENTITY";
        if (a == 0 && a != b)
            return "IMPOSSIBLE";
        // cout<<float(b/a)<<endl;
        int c = float(b / a);
        // cout<< a<<"*"<<b<< endl;
        // cout<<c<<endl;
        if (c<0 && b % a != 0)
            return to_string(c - 1);
        return to_string(c);
    }
    void helper(string e, bool isLeft, int &a, int &b)
    {
        int sign = 1, num = -1;
        e += "+";
        for (int i = 0; i < e.size(); ++i)
        {
            if (e[i] == '-' || e[i] == '+')
            {
                num = (num == -1) ? 0 : (num * sign);
                b += isLeft ? -num : num;
                num = -1;
                sign = (e[i] == '+') ? 1 : -1;
            }
            else if (e[i] >= '0' && e[i] <= '9')
            {
                if (num == -1)
                    num = 0;
                num = num * 10 + e[i] - '0';
            }
            else if (e[i] == 'x')
            {
                num = (num == -1) ? sign : (num * sign);
                a += isLeft ? num : -num;
                num = -1;
            }
        }
    }
};

int main()
{
    int step;
    cin >> step;
    while (step--)
    {
        Solution Sol;
        string S;
        cin >> S;
        cout << Sol.solveEquation(S) << endl;
    }
    return 0;
}