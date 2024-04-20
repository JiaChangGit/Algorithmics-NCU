/*
現在有個人會將書本所有的頁數做相加，例如一本書假設10頁，就會從1+2+3+4+5+6+7+8+9+10得到55。
如果現在這個人固定會少算一頁，也只知道現在少算後全部相加的結果，請求出他少算的是哪一頁跟原本總共是幾頁。
(Ex:結果是50，就可以知道是原本有10頁，而他少算了第5頁)
(Ex:結果是45，就可以知道原本有10頁，而他少算到第10頁)
(hint:10頁的總頁數是55，11頁的總頁數是66，可以從總頁數的差來求答案)
輸入範例
第一行為測資筆數n
後面n行為相加的結果
輸出範例
每n組測資都有兩個值，輸出少算的是哪一頁跟這本書總共幾頁，
每行最後一個數後面不用空格。

Sample input
2
3
9000

Sample output
3 3
45 134
*/
#include <iostream>

using namespace std;
void AddThePage(int ans1[], int ans2[], int th, int p)
{
    int i = 0;
    while ((i * (i + 1)) / 2 <= p)
    {
        ++i;
        ans1[th] = ((i * (i + 1)) / 2 - p);
        ans2[th] = i;
    };
}
int main()
{
    int size;
    cin >> size;
    int i;
    int *inptr = new int[size];
    int *lackptr = new int[size];
    int *allptr = new int[size];
    for (i = 1; i <= size; ++i)
    {
        cin >> *(inptr + i - 1);
        AddThePage(lackptr, allptr, i - 1, *(inptr + i - 1));
    }
    for (i = 1; i <= size; ++i)
        cout << *(lackptr + i - 1) << " " << *(allptr + i - 1) << endl;
    return 0;
}