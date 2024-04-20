/*
Write an algorithm to input an integer n and output (decide) if n is a happy number.

例如32→3^2+2^2=13
13→1^2+3^2=10
10→1^2+0^2=1
可以稱32為快樂數
Input的第一個數字為測資個數
Output為Happy或Not Happy
例:
Input:
3
28
32
87

Output:
Happy
Happy
Not Happy
*/
#include <iostream>
#include <set>

using namespace std;

bool isHappy(int num)
{
    set<int> s;

    while (num != 1)
    {

        int t = 0;
        while (num)
        {
            t += (num % 10) * (num % 10);
            num /= 10;
        }
        num = t;
        if (s.count(num))
        {
            break;
        }
        else
        {
            s.insert(num);
        }
    }
    return (num == 1);
}

int main()
{
    int num = 0;
    int sizes = 0;
    cin >> sizes;
    bool *result = new bool[sizes];
    int i;
    for (i = 1; i <= sizes; ++i)
    {
        cin >> num;
        *(result + i - 1) = isHappy(num);
    }
    for (i = 1; i <= sizes; ++i)
    {
        if (*(result + i - 1))
            cout << "Happy" << endl;
        else
            cout << "Not Happy" << endl;
    }

    return 0;
}

/*
用 set 記錄出現過的數字.

每產生一個快樂數. 就判斷它是否在 set 中. 若存在就退出循環.

若不存在就加入 set .

循環結束的條件還有 新產生的快樂數 是1.
*/