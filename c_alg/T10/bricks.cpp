#include <iostream>
using namespace std;

int main()
{
    int n, loopNum;
    cin >> loopNum;
    while (loopNum--)
    {
        cin >> n;
        int sum = 0;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int avg = sum / n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > avg)
                ans += a[i] - avg;
        }
        cout << ans << "\n";
    }
    return 0;
}