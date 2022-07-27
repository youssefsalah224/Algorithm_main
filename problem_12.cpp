#include <bits/stdc++.h>
using namespace std;

class Point
{
    public:
    double x;
    double y;
};


double Distance(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}


double Min_Distance(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (Distance(P[i], P[j]) < min)
                min = Distance(P[i], P[j]);
    return min;
}
 


int main()
{
    Point P[] = {{10,20}, {30,40}, {50,60}, {70,80}, {90, 100}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The Minimum Distance is " << Min_Distance(P, n);
    return 0;
}
