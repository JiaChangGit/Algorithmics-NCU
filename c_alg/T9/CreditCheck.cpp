#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int getLoopNum;
    cin >> getLoopNum;
    while (getLoopNum--)
    {
        int n, sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> n;
            for (int j = 3; j >= 0; j--)
            {
                if (j % 2)
                {
                    sum2 += n % 10;
                }
                else
                {
                    int x = 2 * (n % 10);
                    sum1 += (x / 10) + (x % 10);
                }
                n /= 10;
            }
        }
        if ((sum1 + sum2) % 10)
            cout << "Invalid\n";
        else
            cout << "Valid\n";
    }
    return 0;
}