/*
給你一個範圍的數，請你寫一個程式找出在這個範圍內的數，哪一個數有最多的除數（就是小於等於這個數，且可以被這個數除盡的數。例如：6有4個除數，分別是1,2,3,6）。數的大小很大，範圍也不小，所以你的程式必須有效率，否則可能無法在幾秒內跑完。
Input
輸入的第一列有一個正整數N，代表以下有幾組測試資料。每組測試資料一列，含有2個正整數L，U，代表某一範圍的數中最小及最大的數。並且 1 <= L <= U <= 1000000000，0 <= U-L <= 10000
Output
對每一組測試資料，找出在範圍內有最多除數的數P（如果有不止一個數有最多除數，請找最小的那個），以及他有多少個除數D。然後依這樣的格式輸出：'Between L and H, P has a maximum of D divisors.。請參考Sample Output。
Sample Input
3
1 10
1000 1000
999999900 1000000000
Sample Output
Between 1 and 10, 6 has a maximum of 4 divisors.
Between 1000 and 1000, 1000 has a maximum of 16 divisors.
Between 999999900 and 1000000000, 999999924 has a maximum of 192 divisors.
*/
#include <iostream>
#include <cmath>
using namespace std;

int ans, divisor;
bool is_prime[40000];

void build_prime_tb()
{
    /*是質數:false, 不是質數:true*/
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i <= sqrt(40000); i++)
    {
        if (!is_prime[i])
        {
            for (int k = 39999 / i, j = i * k; k >= i; k--, j -= i)
            {

                if (!is_prime[k])
                    is_prime[j] = true;
            }
        }
    }
}

void prime_factor(int num)
{ /*質因數分解*/
    int m = (int)(sqrt(num) + 0.001);
    int x = num;
    int tmp = 1, ppow;
    for (int i = 2; i <= m; i++)
    {
        ppow = 0;
        if (!is_prime[i] && x % i == 0)
        {
            ppow = 0;
            while (x % i == 0)
            {
                x /= i;
                ppow++;
            }
            tmp *= ppow + 1;
        }
    }
    if (x > 1)
        tmp *= 2;
    if (tmp > divisor)
        divisor = tmp, ans = num;
}
int main()
{
    int size;
    cin >> size;
    int *inptrL = new int[size];
    int *inptrH = new int[size];
    //int *divisor = new int[size];
    //int *divTh = new int[size];
    int i;
    while (size--)
    {
        ans = 0;
        divisor = 0;
        cin >> *(inptrL + i - 1) >> *(inptrH + i - 1);
        for (int j = *(inptrL + i - 1); j <= *(inptrH + i - 1); ++j)
            prime_factor(j);
        cout << "Between " << *(inptrL + i - 1) << " and " << *(inptrH + i - 1) << ", " << ans << " has a maximum of " << divisor << " divisors." << endl;
    }

    return 0;
}