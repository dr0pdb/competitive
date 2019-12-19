#include<bits/stdc++.h>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

class Point    {
public:
    int x, y;

    Point() {}

    Point(int _x, int _y) {
        x = _x; y = _y;
    }

    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point
Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

stack<Point> grahamScan(vector<Point> points)    {
    int N = points.size();
    stack<Point> hull;

    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points.begin()+1, points.end(), POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}

int main()  {
    vector<Point> points = {{2, 0}, {1, 1}, {2, 2}, {2, 4}, {3,3}, {4,2}};

    stack<Point> hull = grahamScan(points);
    while (!hull.empty())   {
        Point p = hull.top();
        hull.pop();

        printf("(%d, %d)\n", p.x, p.y);
    }

    return 0;
}
