/*
你現在要折四隻紙鶴，必須選出一張紙出來剪成四個相等的正方形，
並使正方形的面積最大，這樣才能折出四個大小相等且最大的紙鶴。
本題會給你每張紙的大小，你必須從中選出一張紙出來滿足本題的要求。

假如不只一張紙可以滿足你的需求，你只需指出最前面的那一張。

Input
輸入會有許多組測試資料，每組資料的第一個整數N會告訴你接下來有幾張紙，每張紙會有兩個整數表示紙的大小 w, h，當N = 0 時結束。
Output
針對每組測試資料，你必須輸出該組資料中可以做出四隻最大紙鶴的那張紙的編號，第一張紙的編號為1，第二張為2，以此類推。若有重複的答案請輸出一個編號就好，以最小的為準。

Sample Input
3
10 20
40 8
12 12
3
140 122
122 140
100 170
2
120 170
71 500
0
Sample Output
2
1
2
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int w, h;
        double mx = 0.0;
        int mxi = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> w >> h;
            double test = max(min(w, h) / 2.0, max(min<double>(w / 4.0, h), min<double>(w, h / 4.0)));
            if (test > mx)
            {
                mx = test;
                mxi = i;
            }
        }
        cout << mxi + 1 << endl;
    }
}