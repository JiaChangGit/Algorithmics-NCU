/*
請利用最近二維點對演算法，解決最近二維點對問題。
以下給定n個二維平面點，找出其中距離最近的二個點的距離，例如：
(5,3) , (9,6) , (5,1) 最近二維點對距離為2則輸出至小數點後3位: 2.000
input
第一行為n代表總共有n組二維點對問題
第二行為m代表此二維點對共有m個點
接下來的m行，每一行都是一個二維點的x,y座標，中間以空白隔開
output
輸出最近的點對距離，並且輸出至小數點後第3位，例如距離為2則輸出2.000

Sample input:
3
2
5 3
9 6
3
5 3
9 6
5 1
4
5 3
9 6
5 1
4 4
Sample output:
5.000
2.000
1.414
*/

// A divide and conquer program in C++
// to find the smallest distance from a
// given set of points.
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
public:
    int x, y;
};

// Needed to sort array of points
// according to X coordinate
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// Needed to sort array of points according to Y coordinate
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// A utility function to find the
// distance between two points
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// A Brute Force method to return the
// smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// A utility function to find
// minimum of two float values
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// A utility function to find the
// distance between the closest points of
// strip of given size. All points in
// strip[] are sorted according to
// y coordinate. They all have an upper
// bound on minimum distance as d.
// Note that this method seems to be
// a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n / 2;
    Point midPoint = P[mid];

    // Consider the vertical line passing
    // through the middle point calculate
    // the smallest distance dl on left
    // of middle point and dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains
    // points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.
    // Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d));
}

// The main function that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    // Use recursive function closestUtil()
    // to find the smallest distance
    return closestUtil(P, n);
}

// Driver code
int main()
{
    int i, j, tmp, step;
    cin >> step;

    int size;
    for (i = 0; i < step; ++i)
    {
        cin >> size;
        Point *ptr = new Point[size];
        for (j = 0; j < size; ++j)
        {
            cin >> tmp;
            (ptr + j)->x = tmp;
            cin >> tmp;
            (ptr + j)->y = tmp;
        }
        cout << fixed<< setprecision(3) << closest(ptr, size)<< endl;
    }

    return 0;
}