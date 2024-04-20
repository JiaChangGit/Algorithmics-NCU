/*
給定一個長度為 n 的索引整數數組 nums。
索引 i 的平均差值是 nums 的前 i +1 個元素的平均值與最後 n - i - 1 個元素的平均值之間的絕對差值。
兩個平均值都應向下捨入到最接近的整數。 返回具有最小平均差的索引。 如果有多個這樣的索引，則返回最小的一個。
Input
輸入的第一列有一個整數代表共有多少筆測資。
每筆測資第一個數字代表陣列有幾個元素n，後面的數字代表陣列nums的元素
Output
最小平均差的索引
Sample input:
2
6 2 5 3 9 5 3
1 0
Sample output:
3
0
Explanation:
The average difference of index 0 is:
|2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
The average difference of index 1 is:
|(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is:
|(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is:
|(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is:
|(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is:
|(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.

The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.


Solution: Prefix / Suffix Sum
Time complexity: O(n)
Space complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums, int vSize)
    {
        int ans = 0;
        int n = vSize;
        long long suffix = accumulate(begin(nums), end(nums), 0LL);
        long long prefix = 0;
        int best = 2147483647;

        for (int i = 0; i < n; ++i)
        {
            prefix += nums[i];
            suffix -= nums[i];
            int cur = abs(prefix / (i + 1) - (i == n - 1 ? 0 : suffix / (n - i - 1)));
            if (cur < best)
            {
                best = cur;
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    int testNum;
    int arrNum;
    int v1tmp;

    cin >> testNum;
    while (testNum--)
    {
        cin >> arrNum;
        vector<int> v1(arrNum);
        for (int i = 0; i < arrNum; i++)
        {
            cin >> v1tmp;
            v1[i] = v1tmp;
        }
        Solution S;
        cout << S.minimumAverageDifference(v1, arrNum) << endl;
    }

    return 0;
}