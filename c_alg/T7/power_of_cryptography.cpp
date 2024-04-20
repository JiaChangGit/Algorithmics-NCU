/*
給你兩個整數 n（n >= 1）和 p（p >=1），你必須寫一個程式來計算出 p 的正 n 次方根。
在這個問題裡，p 皆可表成 k^n 的形式，其中 k 為整數。（k也就是你的程式所要求的）

Input
第一行有一個數字代表接下來有幾組測資
每組測試資料有2個數，第1個整數 n（1 <= n <= 200），第2個整數 p（1 <= p <= 10^101）。
並且存在一個整數 k，（1 <= k <= 10^9），使得 k^n=p。

Output
每組測試資料請輸出 k。

Sample Input
3
2 16
3 27
7 4357186184021382204544

Sample Output
4
3
1234
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double  n = 0, p = 0, k = 0;
    int dataNum;
    cin >> dataNum;
    while (dataNum--)
    {
        cin >> n >> p;
        k = exp(log(p) / n);
        cout << k << endl;
    }

    return 0;
}
