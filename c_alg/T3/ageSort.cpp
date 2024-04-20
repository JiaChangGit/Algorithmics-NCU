/*你有所有城市的人的年齡資料，而且這城市的人們都大於1歲，且都不會活超過100歲。現在你有個簡單的任務以升冪去排序所有的年齡

Input
接下來會有很多筆的資料，每筆資料從輸入n 開始 (0 < n < 2000000)，n代表著城市全部的人數，
下一行將會有n個數代表著每個人的年齡，當輸入n=0時將會結束。

Output
每筆資料輸出一行n個數代表這城市所有的年齡而且以升冪排序，並且用空白分開，最後一個數後面不用空格。

Sample Input
5
3 4 2 1 5
6
2 3 2 3 1 7
0

Sample Output
1 2 3 4 5
1 2 2 3 3 7
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> result;
    vector<int> counter;
    vector<int>::iterator it, its;
    counter.push_back(0);
    int length, i, tmp, tmpf;
    int size = 0;
    while (cin >> length)
    {
        if (length == 0)
            break;
        counter.push_back(length);
        for (i = 1; i <= length; ++i)
        {
            cin >> tmp;
            result.push_back(tmp);
        }
        ++size;
    }
    its = result.begin() + counter[0];
    for (i = 0; i < size; ++i)
    {
        sort(its, its + counter[i + 1]);
        for (it = its; it != its + counter[i + 1] - 1; ++it)
            cout << *it << " ";
        cout << *it << endl;
        its = its + counter[i + 1];
    }

    return 0;
}