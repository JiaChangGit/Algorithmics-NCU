/*
給你一個範圍 a 到 b ，請你找出 a 與 b 之間所有奇數的和。
例如：範圍 [3, 9] 中所有奇數的和就是 3 + 5 + 7 + 9 = 24 。

Input
輸入的第一列有一個整數 T （1≦T≦100），代表以下有多少組測試資料。
每組測試資料為兩列，包含兩個數 a 與 b （0≦a≦b≦100）。
Output
每組測試資料輸出一列，內容為 a 及 b 間所有奇數的和。

Sample Input
2
1
5
3
5
Sample Output
Case 1: 9
Case 2: 8
*/
#include <iostream>

using namespace std;

int Odd(int a, int b)
{
    int sum=0;
    int i;
    if (a % 2 == 0)
        i = a + 1;
    else
        i = a;
    for (i; i<= b; i = i+2){
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int set_sizes = 0;
    cin >> set_sizes;
    int a = 0, b = 0;
    int *stored = new int[set_sizes];
    int i;
    for (i = 1; i <= set_sizes; ++i)
    {
        cin >> a >> b;
        *(stored + i - 1) = Odd(a, b);
    }
    for (i = 1; i <= set_sizes; ++i)
    {
        cout << "Case " << i << ": " << *(stored + i - 1) << endl;
    }
    delete[] stored;
    return 0;
}