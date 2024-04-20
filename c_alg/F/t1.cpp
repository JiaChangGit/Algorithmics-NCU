#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class Puzzle8
{
public:
    struct Puzzle
    {
        int f[9];
        int space;
        std::string path;

        bool operator<(const Puzzle &p) const
        {
            for (int i = 0; i < 9; i++)
            {
                if (f[i] == p.f[i])
                    continue;
                return f[i] > p.f[i];
            }
            return false;
        }
    };
    Puzzle P_in, P_out;
    bool isTarget(Puzzle p, Puzzle t);
    std::string BFS(Puzzle s, Puzzle t);

private:
    static const int dx[4];
    static const int dy[4];
    static const char dir[4];
};

const int Puzzle8::dx[4] = {-1, 0, 1, 0};
const int Puzzle8::dy[4] = {0, 1, 0, -1};
const char Puzzle8::dir[4] = {'u', 'l', 'd', 'r'};
bool Puzzle8::isTarget(Puzzle8::Puzzle p, Puzzle8::Puzzle t)
{
    for (int i = 1; i < 9 + 1; i++)
    {
        switch (p.f[i - 1])
        {
        case 9:
            cout << 0;
            break;
        default:
            cout << p.f[i - 1];
            break;
        }

        switch (i % 3)
        {
        case 0:
            cout << endl;
            break;
        default:
            cout << " ";
            break;
        }
    }

    for (int i = 0; i < 9; i++)
        if (p.f[i] != t.f[i])
            return false;
    return true;
}
std::string Puzzle8::BFS(Puzzle s, Puzzle t)
{
    std::queue<Puzzle> Q;
    std::map<Puzzle, bool> M;
    Puzzle a, b;
    s.path = "";
    Q.push(s);
    M[s] = true;
    while (Q.empty() != 1)
    {
        a = Q.front();
        Q.pop();
        if (isTarget(a, t))
            return a.path;
        int puzzle_x = a.space / 3;
        int puzzle_y = a.space % 3;

        for (int r = 0; r < 4; r++)
        {
            int tmp_x = puzzle_x + dx[r];
            int tmp_y = puzzle_y + dy[r];
            if (tmp_x < 0 || tmp_y < 0 || tmp_x >= 3 || tmp_y >= 3)
                continue;
            b = a;
            std::swap(b.f[a.space], b.f[tmp_x * 3 + tmp_y]);
            b.space = tmp_x * 3 + tmp_y;
            if (M[b] != 1)
            {
                M[b] = true;
                b.path += dir[r];
                Q.push(b);
            }
        }
    }

    return "NO Path";
}

int main()
{
    Puzzle8 *P;
    for (int i = 0; i < 9; i++)
    {
        cin >> P->P_in.f[i];
        switch (P->P_in.f[i])
        {
        case 0:
            P->P_in.f[i] = 9;
            P->P_in.space = i;
            break;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        cin >> P->P_out.f[i];
        switch (P->P_out.f[i])
        {
        case 0:
            P->P_out.f[i] = 9;
            P->P_out.space = i;
            break;
        }
    }

    P->BFS(P->P_in, P->P_out);
    return 0;
}