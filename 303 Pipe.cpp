#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

// Code from Code Archive 2012 World Finals
typedef complex<double> Point;
const double eps = 0.0000001;

bool Equals(double a, double b)
{
    return fabs(a - b) < eps;
}

bool Equals(Point a, Point b)
{
    return Equals(a.real(), b.real()) && Equals(a.imag(), b.imag());
}

double cross(const Point &a, const Point &b)
{
    return imag(conj(a)*b);
}

double dot(const Point &a, const Point &b)
{
    return real(conj(a)*b);
}

// Returns 1 if intersect, 0 if no intersection, and -1 if coincide
int line_line_inter(Point a, Point b, Point c, Point d, Point &p) {
    if (fabs(cross(b-a, d-c)) > eps)
    {
        p = (cross(c - a, d - c) / cross(b - a, d - c)) * (b - a) + a;
        return 1;
    }
    else if (fabs(cross(b-a, b-c)) > eps)
        return 0;
    return -1;
}

// Start of my code
// This caused a lot of the issues
bool IsContained(double segA, double segB, double p)
{
    return ((segA < p && p < segB) ||
           (segB < p && p < segA)) &&
           !Equals(segA, p) && !Equals(segB, p);
}


bool LineIntersectsSegmentAndPoint(Point lineA, Point lineB, Point segA, Point segB, Point &p)
{
    int val = line_line_inter(lineA, lineB, segA, segB, p);
    
    if (val == 1)
    {
        if (Equals(segA.real(), segB.real()))
            return IsContained(segA.imag(), segB.imag(), p.imag());
        else
            return IsContained(segA.real(), segB.real(), p.real());
    }
    
    // If they are colinear, assume light magically manages to pass along it
    else if (val == -1)
    {
        return false;
    }
    
    return false;
}

int N;
Point allPointsTop[23];
Point allPointsBottom[23];

// Based on the light following this line, how far does it go?
    // Can do that by checking if it intersects with the segment between
double GetPointWillEndAt(Point lineA, Point lineB)
{
    Point intersection;
    
    // Check if it exits the pipe immediately. Only need to check if it intersects with one of the corners
    if (!LineIntersectsSegmentAndPoint(lineA, lineB, allPointsTop[0], allPointsBottom[0], intersection))
    {
        // Possibly intersects on the ends
        // If it does, need to make sure that it doesn't exit the pipe immediately
        if (!Equals(intersection, allPointsTop[0]) && !Equals(intersection, allPointsBottom[0]))
        {
            return allPointsTop[0].real();
        }
    }
    
    
    // For each line segment that the pipe is made of
    // If have reached the end, then stop
    for (int i = 0; i < N - 1; ++i)
    {
        // Top
        if (LineIntersectsSegmentAndPoint(lineA, lineB, allPointsTop[i], allPointsTop[i + 1], intersection))
        {
            return intersection.real();
        }
        
        // Bottom
        if (LineIntersectsSegmentAndPoint(lineA, lineB, allPointsBottom[i], allPointsBottom[i + 1], intersection))
        {
            return intersection.real();
        }
        
        // Ensure it passes through the next gap
            // If it doesn't can say that it exited on the current
        // Intersection is given value that will not be on the endpoints of next gap, since it may not be set
        intersection = allPointsBottom[i];
        if (!LineIntersectsSegmentAndPoint(lineA, lineB, allPointsTop[i + 1], allPointsBottom[i + 1], intersection))
        {
            if (!Equals(intersection, allPointsTop[i + 1]) && !Equals(intersection, allPointsBottom[i + 1]))
            {
                return allPointsTop[i].real();
            }
        }
    }
    
    
    return allPointsTop[N - 1].real();
}

int main()
{
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
        {
            double x, y;
            cin >> x >> y;
            
            allPointsTop[i] = Point(x, y);
            allPointsBottom[i] = Point(x, y-1);
        }
        
        double farthest = allPointsTop[0].real();
        
        // For each pair of points
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                // Try to connect them, for top and bottom
                farthest = max(farthest, GetPointWillEndAt(allPointsTop[i], allPointsBottom[j]));
                farthest = max(farthest, GetPointWillEndAt(allPointsBottom[i], allPointsTop[j]));
            }
        }
        
        if (!Equals(farthest, allPointsTop[N - 1].real()))
            cout << setprecision(2) << fixed << farthest << '\n';
        else
            cout << "Through all the pipe.\n";
    }
}