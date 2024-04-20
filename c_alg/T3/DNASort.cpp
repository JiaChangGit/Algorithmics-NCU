/*
在一個字串中，「未排序」的程度是以各字元間彼此的大小關係來計算的。例如在字串 DAABEC中，「未排序」的程度為 5，因為D比它右邊的4個字元大，E比它右邊的1個字元大。而字串AACEDGG「未排序」的程度為 1（幾乎是快排序好的，唯一的未排序發生在E和D之間），字串ZYXW「未排序」的程度為 6（剛好是完全排序的相反）。
現在你的任務是為許多的字串來做排序。每個字串中僅含有A,C,G和T這4種字元。排序的原則是根據各字串「未排序」的程度，由小到大輸出。在這裡每個字串的長度均相同。
Input
輸入的第一列有一個整數代表以下有幾組測試資料。每組測試資料的第一列含有2個正整數 n（0 < n <= 50）和 m（0 < m <= 100），n 代表字串的長度，m 代表字串的數目。接下來的 m 列，每列有一個長度為 n 的字串。
第一列及第一組測試資料，以及各組測試資料間均有一空白列。
Output
對每組測試資料按照「未排序」的程度，由小到大輸出各字串。假如有不只2個字串「未排序」的程度相同，則按照它們在輸入中的順序輸出。
各組測試資料之間請輸出一空白列
Sample Input
2
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

2 3
TC
TT
TA
Sample Output
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

TT
TC
TA
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct data
{
    char letter[50];
    int num = 0;
};
bool cmp(data x, data y)
{
    return x.num < y.num;
}
int main()
{
    int test, n, m;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        if (i > 0)
            cout << endl;
        cin >> n >> m;
        struct data g[m];
        data *c = g;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> c[j].letter[k];
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n - 1; k++)
            {
                for (int l = k; l < n; l++)
                {
                    if (int(c[j].letter[k]) > int(c[j].letter[l]))
                        c[j].num++;
                }
            }
        }
        sort(g, g + m, cmp);
        for (int j = 0; j < m; j++)
        {
            if (j > 0)
                cout << endl;
            for (int k = 0; k < n; k++)
            {
                cout << c[j].letter[k];
            }
        }
    }
    return 0;
}