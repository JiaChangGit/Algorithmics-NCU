#include <iostream>
#include <vector>
#include <algorithm>

#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define INF 0x1f1f1f1f
using namespace std;

map<string, int> nmap;
int dis[100][100], n, m;
int getCityIndex(string p)
{
    if (nmap.find(p) == nmap.end())
    {
        int s = nmap.size();
        nmap[p] = s;
    }
    return nmap[p];
}
void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                cout << dis[i][j];
                break;
            }
            if (dis[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int a, b, w;
    string x, y;
    cin >> n >> m;
    memset(dis, 0x1f, sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        a = getCityIndex(x);
        b = getCityIndex(y);
        dis[a][b] = w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][k] == INF || dis[k][j] == INF)
                    continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    print(n);
}