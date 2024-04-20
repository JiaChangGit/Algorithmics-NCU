/*
Input
第一行請輸入測資比數N
每一筆的測資都會有兩行，第一行為總長度L (0 ≤ L ≤ 50)，
第二行為從1到L的排列組合
現在要將此序列由小到大重新排列。
Output
每組測資請輸出"Optimal swapping takes S swaps." S為swap次數
Sample Input
3
3
1 3 2
4
4 3 2 1
2
2 1
Sample Output
Optimal swapping takes 1 swaps.
Optimal swapping takes 6 swaps.
Optimal swapping takes 1 swaps.
*/
/*
Write an algorithm
using the pseudo code to input integers n and m, and output all n's factors
larger than m and less than n.
*/
#include <iostream>
using namespace std;

int bubbleSwap(int length) {
  int swap_time = 0;
  int *lengthptr = new int[length];
  int i, j;
  for (i = 1; i <= length; ++i) {
    cin >> *(lengthptr + i - 1);
  }
  for (i = 1; i < length; ++i) {
    for (j = 1; j <= length - i; ++j)
      if (*(lengthptr + j - 1) > *(lengthptr + j)) {
        swap(*(lengthptr + j - 1), *(lengthptr + j));
        ++swap_time;
      }
  }
  return swap_time;
}

int main() {
  int size = 0;
  int length = 0;
  cin >> size;
  int *sizeptr = new int[size];
  int i;
  for (i = 1; i <= size; ++i) {
    cin >> length;
    *(sizeptr + i - 1) = bubbleSwap(length);
  }
  for (i = 1; i <= size; ++i)
    cout << "Optimal swapping takes " << *(sizeptr + i - 1) << " swaps."
         << endl;

  return 0;
}
