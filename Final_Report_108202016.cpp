#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::min;

template <typename T>
class AStar
{
public:
    struct Vertex3
    {
        T e[3];
    };
    // node with 3 edges
    Vertex3 v[10];
    T ans = 0;

    // build Vertex3 array from inArr[24]
    void build(T ar[]);
    // get min f[n], f = g + h
    T fV(int);
    // for Vertex compare
    int compare(Vertex3);
};

// build Vertex3 array from inArr[24]
template <typename T>
void AStar<T>::build(T ar[])
{
    int n = 0;
    // for S~F
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 3; ++j)
        {
            v[i].e[j] = ar[n];
            ++n;
        }
    // for G~I
    for (int i = 7; i < 10; ++i)
        v[i].e[0] = ar[i + 14];
}

// for compare Vertex edges, which is smallest
template <typename T>
int AStar<T>::compare(Vertex3 v_)
{
    if (v_.e[0] < v_.e[1] && v_.e[0] < v_.e[2])
        return 0;
    else if (v_.e[1] < v_.e[0] && v_.e[1] < v_.e[2])
        return 1;
    return 2;
}

// get min f[stageNum]
template <typename T>
T AStar<T>::fV(int stageNum)
{
    if (stageNum == 1)
        // f[1]= min(S~A, S~B, S~C)
        ans = min(min(v[0].e[0], v[0].e[1]), v[0].e[2]);
    if (stageNum == 4 || stageNum == 5)
    {
        // there are only one path (from [G, H, I] to [T]), and add it
        for (int i = 7; i < 10; ++i)
            for (int j = 4; j < 7; ++j)
                v[j].e[i - 7] = v[j].e[i - 7] + v[i].e[0];
        stageNum = 3;
        // fV(3)
        return fV(stageNum);
    }
    // get smallest path(h[n]), and add it
    if (stageNum == 3)
    {
        //  get smallest path(from [D, E, F] to [G, H, I]; h(n))
        for (int i = 4; i < 7; ++i)
            switch (compare(v[i]))
            {
            case 0:
                for (int j = 1; j < 4; ++j)
                    v[j].e[i - 4] = v[j].e[i - 4] + v[i].e[0];
                break;
            case 1:
                for (int j = 1; j < 4; ++j)
                    v[j].e[i - 4] = v[j].e[i - 4] + v[i].e[1];
                break;
            case 2:
                for (int j = 1; j < 4; ++j)
                    v[j].e[i - 4] = v[j].e[i - 4] + v[i].e[2];
                break;
            }
        --stageNum;
        // fV(2)
        return fV(stageNum);
    }
    if (stageNum == 2)
    {
        // get smallest path(from [A, B, C] to [D, E, F]; h(n))
        for (int i = 1; i < 4; ++i)
            switch (compare(v[i]))
            {
            case 0:
                v[0].e[i - 1] = v[0].e[i - 1] + v[i].e[0];
                break;
            case 1:
                v[0].e[i - 1] = v[0].e[i - 1] + v[i].e[1];
                break;
            case 2:
                v[0].e[i - 1] = v[0].e[i - 1] + v[i].e[2];
                break;
            }
        --stageNum;
        // fV(1)
        return fV(stageNum);
    }
    return ans;
}

int main()
{
    static int inArr[24];
    AStar<int> *A;
    int stageNum, loopNum;
    // how many test will do
    cin >> loopNum;
    while (loopNum--)
    {
        // get input data(24 edges)
        for (int i = 0; i < 24; ++i)
            cin >> inArr[i];
        // get stage number
        cin >> stageNum;
        // input data to class Astar
        A->build(inArr);
        // print min f[n]
        cout << A->fV(stageNum) << endl;
    }
    return 0;
}