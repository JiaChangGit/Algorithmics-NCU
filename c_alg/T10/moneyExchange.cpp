#include <iostream>
using namespace std;

int main()
{
    int coins[101] = {0}; //硬币面值数组，由于题目给出不超过10种，所以我申请了10。
    int money = 0;       //待凑钱的数值*/
    int kind = 0;        //钱币种类数目*/
    int loopNum;
    cin >> loopNum;
    while (loopNum--)
    {
        cin >> kind; //硬币面值种类数
        cin >> money;
        int* dp=new int[money + 1]; //动态规划数组
        dp[0] = 0;         //初始化第一个元素为0，因为要凑0元需要0个钱币

        for (int k = 0; k < kind; k++)
            cin >> coins[k]; //读入硬币面值，存入数组coins[]
        for (int i = 1; i <= money; i++)
            dp[i] = 999999; //初始化数组dp[],设置dp[i]等于无穷大

        for (int i = 1; i <= money; i++) //从凑1元开始，一直算到money元为止。
            for (int j = 0; j < kind; j++)
                if (i >= coins[j])
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        if (dp[money] == 999999)
            cout << "Impossible" << endl;
        else
            cout << dp[money] << endl;
    }
    return 0;
}