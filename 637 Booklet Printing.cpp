#include <cstdio>

int main()
{
    int P;
    
    while (scanf("%d", &P), P)
    {
        printf("Printing order for %d pages:\n", P);
        
        // Only one that does not have a back for each page
        if (P == 1)
        {
            printf("Sheet 1, front: Blank, 1\n");
        }
        
        else
        {
            int numPages = P / 4;
            if (numPages * 4 < P)
                ++numPages;
            
            int numberSkipped = numPages * 4 - P;
            
            for (int i = 0; i < numPages; ++i)
            {
                int frontFirstPage = P - i * 2 + numberSkipped;
                int frontSecondPage = i * 2 + 1;
                
                if (frontFirstPage <= P)
                    printf("Sheet %d, front: %d, %d\nSheet %d, back : %d, %d\n", i + 1, frontFirstPage, frontSecondPage, i + 1, frontSecondPage + 1, frontFirstPage - 1);
                else if (frontFirstPage - 1 <= P)
                    printf("Sheet %d, front: Blank, %d\nSheet %d, back : %d, %d\n", i + 1, frontSecondPage, i + 1, frontSecondPage + 1, frontFirstPage - 1);
                else
                    printf("Sheet %d, front: Blank, %d\nSheet %d, back : %d, Blank\n", i + 1, frontSecondPage, i + 1, frontSecondPage + 1);
            }
        }
    }

}