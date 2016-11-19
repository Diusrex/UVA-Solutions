#include <iostream>
#include <complex>

using namespace std;

// Geometry from U of A Programming Club Archive, World Finals 2012 doc
const double eps = 1e-7;
typedef complex<double> point;

double cross(const point& a, const point& b)
{
    return imag(conj(a)*b);
}
double dot(const point& a, const point& b)
{
    return real(conj(a)*b);
}

int line_line_inter(point a, point b, point c, point d, point& p)
{
    if (abs(cross(b-a, d-c)) > eps) {
        p = (cross(c - a, d - c) / cross(b - a, d - c)) * (b - a) + a;
        return 1;
    }
    if (abs(cross(b-a, b-c)) > eps)
        return 0;
    return -1;
}

bool seg_seg_intersect(point a, point b, point c, point d)
{
    point p;
    int s = line_line_inter(a, b, c, d, p);
    if (s == 0)
        return false;
    if (s == -1)
    {
        if (dot(a-c, a-d) < eps)
            return true;
        if (dot(b-c, b-d) < eps)
            return true;
        if (dot(c-a, c-b) < eps)
            return true;
        return false;
    }
    if (dot(p-a, p-b) < eps && dot(p-c, p-d) < eps)
        return true;
    return false;
}

bool connected[105];
point start[105], endPoint[105];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            connected[i] = false;
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            start[i] = point(a, b);
            endPoint[i] = point(c, d);
            for (int j = 0; j < i; ++j)
            {
                bool connect = seg_seg_intersect(start[i], endPoint[i], start[j], endPoint[j]);
                if (connect)
                    connected[i] = connected[j] = true;
            }
        }
        
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (!connected[i])
                ++count;
        cout << count << '\n';
    }
}