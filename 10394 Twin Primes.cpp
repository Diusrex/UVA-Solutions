#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<pair<int, int> > pairs(100001);
    vector<bool> isPrime(18409202, true);
    
    int pos = 1;
    int previous = 0;
    
    for (long long i = 3; pos <= 100000; i += 2)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j < 18409202; j += i)
            {
                isPrime[j] = false;
            }
            
            if (i == previous + 2)
            {
                pairs[pos].first = previous;
                pairs[pos].second = i;
                ++pos;
                
            }
            
            previous = i;
        }
        
    }
    
    int num;
    
    while (scanf("%d", &num) == 1)
    {
        printf("(%d, %d)\n", pairs[num].first, pairs[num].second);
    }
}