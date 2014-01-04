#include <cstdio>
#include <vector>

int main()
{
    std::vector<bool> prime(1000000, true);
    std::vector<int> primeNums(78499);
    int pos = 0;
    
    for (int i = 2; pos < 78498; ++i)
        if (prime[i])
        {
            primeNums[pos++] = i;
            
            for (int x = i * 2; x < 1000000; x += i)
                prime[x] = false;
        }
        
    primeNums[pos] = 1000001;
    
    int num, numFactors;
    
    
    while (scanf("%d", &num), num)
    {
        numFactors = 0;
        for (int i = 0; primeNums[i] <= num; ++i)
        {
            if (num % primeNums[i] == 0)
                ++numFactors;
        }
        
        printf("%d : %d\n", num, numFactors);
    }
    
}