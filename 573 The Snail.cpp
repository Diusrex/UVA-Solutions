#include <cstdio>

int main()
{
    int dropDist, decayPercent, dayNum;
    double wellH, climbDist, decayNum, position;
    
    while (scanf("%lf%lf%d%d", &wellH, &climbDist, &dropDist, &decayPercent), wellH != 0)
    {
        position = dayNum = 0;
        decayNum = climbDist / 100.0 * decayPercent;
        
        do {
            position += climbDist;
            
            ++dayNum;
            
            if (position > wellH)
                break;
            
            
            climbDist -= decayNum;
            
            if (climbDist < 0)
                climbDist = 0;
                
            position -= dropDist;
            
        } while (position >= 0);
        
        if (position <= 0)
            printf("failure on day %d\n", dayNum);
        else
            printf("success on day %d\n", dayNum);
    }
    
}