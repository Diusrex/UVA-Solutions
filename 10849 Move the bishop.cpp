#include <cstdio>
#include <cmath>

int main()
{    int T;
    scanf ("%d", &T);
 
    while ( T-- ) {
        int t, n;
        scanf ("%d %d", &t, &n);
 
        while ( t-- ) {
            int a [4];
            bool possible(true);
            for ( int i = 0; i < 4; i++ ) {
                scanf ("%d", &a [i]);
                if ( a [i] < 1 || a [i] > n ) possible = false;
            }
 
            if ( !possible ) { printf ("no move\n"); continue; }
             
            int diff1 = std::abs (a[0] - a[2]);
            int diff2 = std::abs (a[1] - a[3]);
 
            if (a[0] == a[2] && a[1] == a[3]) 
                printf ("0\n");
                
            else if (diff1 == diff2) 
                printf ("1\n");
                
            else if (diff1 % 2 == 0 && diff2 % 2 == 0) 
                printf ("2\n");
                
            else if (diff1 % 2 == 1 && diff2 % 2 == 1) 
                printf ("2\n");
                
            else 
                printf ("no move\n");
        }
    }
 
    return 0;
}