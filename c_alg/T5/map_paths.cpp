/*
在 m x n 網格上有一點A。 A最初位於左上角（即 map[0][0]）。
A試圖移動到右下角B（即 map[m - 1][n - 1]）。 A在任何時間點只能向下或向右移動。
給定兩個整數 m 和 n，返回A可以到達右下角的可能唯一路徑的數量。

A *
* *
* B

A共有三種走法:
1. 右 -> 下 -> 下
2. 下 -> 下 -> 右
3. 下 -> 右 -> 下

input
輸入的第一列有一個整數代表共有多少筆測資。
每筆測資有兩個數m，n代表map大小
output
A可以到達右下角的可能唯一路徑的數量
Sample input:
2
3 2
3 7
Sample output:
3
28
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

int main(){
    int step, m, n;
    cin>> step;
    while(step--){
        cin>>m>>n;
        Solution Sol;
        cout<< Sol.uniquePaths(m, n)<< endl;
    }
    return 0;
}