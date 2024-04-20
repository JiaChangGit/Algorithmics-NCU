/*
INPUT
第一行是測資個數k
接下來一行一個數字n , 共k行

OUTPUT
請一行一個的輸出每個n的F(n)

SAMPLE INPUT
3
1
10
8

SAMPLE OUTPUT
1
55
21
*/
#include <iostream>
using namespace std;

int main()
{
    long long fib[200];
    int n, i, size;
    cin >> size;
    int *ptr = new int[size];

    fib[1] = 1;
    fib[2] = 1;
    for (i = 3; i <= 200; i = i + 1)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (i = 1; i <= size; ++i)
    {
        cin >> n;
        *(ptr + i - 1) = fib[n];
    }
    for (i = 1; i <= size; ++i)
        cout << *(ptr + i - 1) << endl;

    return 0;
}