#include <cstdio>

const unsigned int FullDaySeconds = 86400;
const unsigned int HalfDaySeconds = 43200;
const unsigned int SecondsInMin = 60;
const unsigned int SecondsInHour = 3600;
const unsigned int HalfDayMin = HalfDaySeconds / SecondsInMin;

int main()
{
    int k, m;
    
    while (scanf("%d%d", &k, &m) == 2)
    {
        unsigned int diff = k > m ? k - m : m - k;
        
        // The 30 seconds makes it round automatically
        unsigned int numSeconds = (HalfDaySeconds * (FullDaySeconds - k) / diff) % 43200 + 30;
        
        unsigned int hour = numSeconds / SecondsInHour % 12;
        unsigned int min = numSeconds / SecondsInMin % 60;

        printf("%d %d %02d:%02d\n", k, m, hour == 0 ? 12 : hour, min);
    }
}
