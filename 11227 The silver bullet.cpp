#include <iostream>
#include <complex>
#include <set>

using namespace std;

typedef complex<double> point;
const double eps = 1e-8;

bool Equal(double a, double b)
{
    return fabs(a - b) <= eps;
}

struct Compare
{
    bool operator()(const point &a, const point &b) const
    {
        if (!Equal(a.real(), b.real()))
            return a.real() < b.real();
        return a.imag() < b.imag();
    }
};

double cross(const point &a, const point &b)
{
    return imag(conj(a)*b);
}

double dot(const point &a, const point &b)
{
    return real(conj(a)*b);
}


bool line_line_coincide(point base, point b, point c)
{
    return fabs(cross(b-base, c-base)) <= eps;
}

int N;
set<point, Compare> allPoints;

int GetBestCount()
{
    // Can always kill at least one
    int best = 1;
    for (set<point, Compare>::iterator i = allPoints.begin(); i != allPoints.end(); ++i)
    {
        set<point, Compare>::iterator j = i; ++j;
        
        for (; j != allPoints.end(); ++j)
        {
            // Current line is i, j
            int current = 0;
            for (set<point, Compare>::iterator k = allPoints.begin(); k != allPoints.end(); ++k)
                if (line_line_coincide(*i, *j, *k))
                    ++current;
            best = max(best, current);
        }
    }
    
    return best;
}

int main()
{
    int T;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        allPoints.clear();
        cin >> N;
        
        while (N--)
        {
            double x, y;
            cin >> x >> y;
            
            
            allPoints.insert(point(x, y));
        }
        
        cout << "Data set #" << t << " contains ";
        if (allPoints.size() == 1)
        {
            cout << "a single gnu\n";
        }
        else
        {
            cout << allPoints.size() << " gnus, out of which a maximum of " << GetBestCount() << " are aligned.\n";
        }
    }
}