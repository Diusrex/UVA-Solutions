#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    int classTests[3];
    
    for (int t = 1; t <= T; ++t)
    {
        int t1, t2, final, attendance;
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &final, &attendance, classTests, classTests + 1, classTests + 2);
        
        // Sorted 0 <= 1 <= 2
        sort(classTests, classTests + 3);
        
        int total = t1 + t2 + final + attendance + (classTests[1] + classTests[2]) / 2;
        char grade;
        
        if (total >= 90)
            grade = 'A';
        else if (total >= 80)
            grade = 'B';
        else if (total >= 70)
            grade = 'C';
        else if (total >= 60)
            grade = 'D';
        else
            grade = 'F';
        
        printf("Case %d: %c\n", t, grade);
    }
}