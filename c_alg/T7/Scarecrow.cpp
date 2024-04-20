/*
Taso 有一塊條狀的田地。他計劃在下一季種植不同的作物。但是這個地區有很多烏鴉，Taso 怕他們會吃掉這些作物，因此他決定在田地的不同位置放置稻草人。
田地可以用 1 × N 的格子模擬。有些部分是不毛之地無法種植作物。一個稻草人除了所在的格子外也保護其左側及右側緊的格子。
已知田地的描述，要保護所有可用田地最少需要幾個稻草人？
Input
輸入開始有一整數 T（T ≤ 100），表示測資筆數。
每筆測資第一行有一整數 N（0 < N < 100）。下一行有 N 個字元以描述田地。點（.）表示良田，井號（#）表示不毛之地。
Output
對於每筆測資，先輸出測資編號，再輸出需放置的稻草人數量。
範例輸入：
3
3
.#.
11
...##....##
2
##
範例輸出：
Case 1: 1
Case 2: 3
Case 3: 0
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> ans;

    while (--n >= 0)
    {
        int i, sum = 0;
        cin >> i;
        vector<char> f;
        f.resize(i);

        while (--i >= 0)
            cin >> f.at(f.size() - i - 1);

        for (int j = 0; j < f.size(); j++)
        {
            if (f.at(j) == '.')
            {
                j += 2;
                sum++;
            }
        }
        ans.push_back(sum);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << "Case " << i + 1 << ": " << ans.at(i) << endl;
    return 0;
}