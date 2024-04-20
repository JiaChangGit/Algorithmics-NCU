/*
身為一個神偷，除了高超的偷竊技巧外，一眼辨識物品價值及考慮銷贓的情況的能力也都是必須的。
今天身為神偷的你接到任務，要到一個屋內偷竊，並且有一個總價值的目標，而你必須要快速地選出那些偷竊物是你必須要偷竊的目標。
Input
第一行為測資組數 K。
每組第一行會告訴你需要偷的總價值 T 及屋子內有 N 個物品。第二行會有 N 個數，由大到小告訴你物品價值 M。
T、N、M 皆屬於整數，不大於 300。
Output
依照輸入順序，輸出選擇了哪些價值的物品，如果無法達成目標，需要告知無法達成目標。若有多組合可以滿足要求，
則輸出第一種可行的組合即可，格式請見範例。
範例輸入：
5
5 3
4 3 1
10 4
9 8 4 2
90 8
23 10 7 5 4 3 2 1
45 8
44 43 12 10 9 8 4 2
100 10
10 10 10 10 10 10 10 10 10 10
範例輸出：
4 1
8 2
impossible
43 2
10 10 10 10 10 10 10 10 10 10
提示：
邏輯：從最大的開始拿，若沒達到要求則拿下一個，
拿了之後如果超過要求的價值則捨棄再看下一個，impossible 的狀況出現在所有物品加起來都達不到要求的時候。
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int k;
    cin >> k;
    vector<vector<int>> ans;
    ans.resize(k);

    while (--k >= 0)
    {
        int t, n, s = 0;
        vector<int> m;

        cin >> t >> n;
        m.resize(n);

        for (int i = 0; i < m.size(); cin >> m.at(i), i++)
            ;

        while (m.size())
        {
            ans.at(ans.size() - k - 1).resize(0);
            s = 0;
            for (int i = 0; i < m.size(); i++)
            {
                if (s + m.at(i) <= t)
                {
                    s += m.at(i);
                    ans.at(ans.size() - k - 1).push_back(m.at(i));
                }
                if (s == t)
                    break;
            }
            if (s == t)
                break;
            m.erase(m.begin());
        }
        if (s < t)
            ans.at(ans.size() - k - 1).resize(0);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i).size() == 0)
            cout << "impossible\n";
        else
        {
            for (int j = 0; j < ans.at(i).size(); cout << (j ? " " : "") << ans.at(i).at(j), j++)
                ;
            cout << endl;
        }
    }

    return 0;
}