#include <bits/stdc++.h>

#include <iostream>
#define INF 0x3f3f3f3f
#define LL long long
const int N = 10000 + 5;
using namespace std;

struct BIT {  // 樹狀陣列
  int arr[N];
  int Id[N];
  void init() {
    memset(arr, INF, sizeof(arr));
    memset(Id, -1, sizeof(Id));
  }
  int lowbit(int k) { return k & (-k); }
  void update(int pos, int val, int id) {
    while (pos > 0) {
      if (arr[pos] > val) {
        arr[pos] = val;
        Id[pos] = id;
      }
      pos -= lowbit(pos);
    }
  }
  int query(int pos, int m) {
    int minval = INF;
    int ans = -1;
    while (pos <= m) {
      if (minval > arr[pos]) {
        minval = arr[pos];
        ans = Id[pos];
      }
      pos += lowbit(pos);
    }
    return ans;
  }
} B;
struct POS {  // 區域
  int x, y;
  int id;
  bool operator<(const POS &rhs) const {
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
} pos[N];
struct Edge {
  int x, y;
  int dis;
  bool operator<(const Edge &rhs) const { return dis < rhs.dis; }
} edge[N << 2], resEdge[N << 2];
int edgeTot, resEdgeTot;
int father[N];
void build(int n) {  // 在R1區域中建邊
  sort(pos, pos + n);
  int a[N], b[N];
  for (int i = 0; i < n; i++) {
    a[i] = pos[i].y - pos[i].x;
    b[i] = pos[i].y - pos[i].x;
  }
  // 離散化
  sort(b, b + n);
  int num = unique(b, b + n) - b;
  B.init();
  for (int i = n - 1; i >= 0; i--) {
    int poss = lower_bound(b, b + num, a[i]) - b + 1;
    int ans = B.query(poss, num);
    if (ans != -1) {  // 建邊
      edge[edgeTot].x = pos[i].id;
      edge[edgeTot].y = pos[ans].id;
      edge[edgeTot].dis = abs(pos[i].x - pos[ans].x) +
                          abs(pos[i].y - pos[ans].y);  // 曼哈頓距離
      edgeTot++;
    }
    B.update(poss, pos[i].x + pos[i].y, i);
  }
}
void manhattan(int n, int k) {
  for (int dir = 1; dir <= 4; dir++) {  // 左側四個區域
    if (dir == 2 || dir == 4) {         // 變換區域
      for (int i = 0; i < n; i++) swap(pos[i].x, pos[i].y);
    } else if (dir == 3) {  // 變換區域
      for (int i = 0; i < n; i++) pos[i].x = -pos[i].x;
    }
    build(n);  // 建邊
  }
}
int Find(int x) { return father[x] == x ? x : father[x] = Find(father[x]); }
void kruskal(int n, int k) {
  resEdgeTot = 0;
  for (int i = 0; i <= n; i++) father[i] = i;
  sort(edge, edge + edgeTot);
  int cnt = n - k;
  for (int i = 0; i < edgeTot; i++) {
    int x = edge[i].x, y = edge[i].y;
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
      cnt--;
      father[fx] = fy;
      resEdge[resEdgeTot].x = x;
      resEdge[resEdgeTot].y = y;
      resEdge[resEdgeTot].dis = edge[i].dis;
      resEdgeTot++;
    }
  }
}
int main() {
  int loopNum;
  int n;
  cin >> loopNum;
  while (loopNum--) {
    scanf("%d", &n);

    edgeTot = 0;
    resEdgeTot = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &pos[i].x, &pos[i].y);
      pos[i].id = i;
    }
    manhattan(n, 2);
    kruskal(n, 2);
    sort(resEdge, resEdge + resEdgeTot);
    int res = 0;
    for (int i = 0; i < resEdgeTot; i++) res += resEdge[i].dis;
    cout << res << endl;
  }
  return 0;
}
