#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int monthNums, numDeprecations, currentDecrease, currentMonth;
    
    double carTotal, downPayment, loanOwed, amountPayedPerMonth;
    
    vector<int> decreaseTime;
    vector<double> decrease;
    
    scanf("%d", &monthNums);
    
    while (monthNums > 0)
    {
        scanf("%lf %lf %d", &downPayment, &loanOwed, &numDeprecations);
        
        amountPayedPerMonth = loanOwed / monthNums;
        
        carTotal = downPayment + loanOwed;
        
        decreaseTime.resize(numDeprecations + 1);
        decrease.resize(numDeprecations + 1);
        
        for (int i = 0; i < numDeprecations; ++i)
            scanf("%d %lf", &decreaseTime[i], &decrease[i]);
        
        decreaseTime[numDeprecations] = 101;
        
        currentDecrease = 0;
        
        carTotal -= carTotal * decrease[currentDecrease];
        
        for (currentMonth = 1; carTotal < loanOwed; ++currentMonth)
        {
            loanOwed -= amountPayedPerMonth;
            
            if (decreaseTime[currentDecrease + 1] == currentMonth)
                ++currentDecrease;
            
            carTotal -= carTotal * decrease[currentDecrease];
        }
        
        --currentMonth;

        if (currentMonth == 1)
            printf("%d month\n", currentMonth);
        else
            printf("%d months\n", currentMonth);
            
        scanf("%d", &monthNums);
    }
}