#include <cstdio>
#include <map>

bool BetterThanOther(int *firstCount, int *secondCount, bool& secondWon)
{
    for (int i = 12; i >= 0; --i)
    {
        if (firstCount[i] && !secondCount[i])
            return true;
        
        
        else if (!firstCount[i] && secondCount[i])
        {
            secondWon = true;
            return false;
        }
    }
    return false;
}

using namespace std;

int main()
{
    map<char, int> cardConversions;
    cardConversions['2'] = 0; cardConversions['3'] = 1; cardConversions['4'] = 2;
    cardConversions['5'] = 3; cardConversions['6'] = 4; cardConversions['7'] = 5;
    cardConversions['8'] = 6; cardConversions['9'] = 7; cardConversions['T'] = 8;
    cardConversions['J'] = 9; cardConversions['Q'] = 10; cardConversions['K'] = 11;
    cardConversions['A'] = 12;
    
    int count[2][13], suitPos, suitPosStart, cardPos, checking, start;
    
    // [p][0 = most, 1 = second]
    // Ordered first by number, then by value
    int topTwoMostCommon[2][2];
    
    bool straight[2], flush[2];
    
    char line[34], suit;
    
    while (gets(line))
    {
        flush[0] = flush[1] = true;
        straight[0] = straight[1] = true;
        
        suitPos = 1;
        cardPos = 0;
        
        topTwoMostCommon[0][0] = topTwoMostCommon[0][1] = topTwoMostCommon[1][0] = topTwoMostCommon[1][1] = -1;
        
        for (int pos(0); pos < 13; ++pos)
            count[0][pos] = count[1][pos] = 0;
            
        for (int p = 0; p < 2; ++p)
        {
            suitPosStart = suitPos;
            suit = line[suitPos];
            suitPos += 3;
            
            
            for (; suitPos <= suitPosStart + 12; suitPos += 3)
                if (line[suitPos] != suit)
                    flush[p] = false;
            
            for (; cardPos < suitPosStart + 12; cardPos += 3)
            {
                ++count[p][cardConversions[line[cardPos]]]; 
            }
            
            start = -1;
            
            for (checking = 12; checking >= 0; --checking)
            {
                // Fails if count > 1
                if (count[p][checking] > 1)
                    straight[p] = false;
                
                if (count[p][checking] == 1 && start == -1)
                    start = checking;
                
                else if (count[p][checking] == 0 && (start != -1 && start - checking <= 4))
                    straight[p] = false;
                    
                if (topTwoMostCommon[p][0] == -1 || count[p][topTwoMostCommon[p][0]] < count[p][checking])
                {
                    topTwoMostCommon[p][1] = topTwoMostCommon[p][0];
                    topTwoMostCommon[p][0] = checking;
                }
                
                else if (topTwoMostCommon[p][1] == -1 || count[p][topTwoMostCommon[p][1]] < count[p][checking])
                    topTwoMostCommon[p][1] = checking;
            }
        }
        
        int firstMostCommon(topTwoMostCommon[0][0]), firstSecondCommon(topTwoMostCommon[0][1]), secondMostCommon(topTwoMostCommon[1][0]), secondSecondCommon(topTwoMostCommon[1][1]);
            
        bool firstWin(false), secondWin(false);
        
        if (flush[0] && straight[0])
        {
            if (flush[1] && straight[1])
            {
                if (firstMostCommon > secondMostCommon)
                    firstWin = true;
                
                else if (firstMostCommon < secondMostCommon)
                    secondWin = true;
            }
            
            else
                firstWin = true;
        }
        
        else if (flush[1] && straight[1])
            secondWin = true;
            
        else if (count[0][firstMostCommon] == 4)
        {
            if (count[1][secondMostCommon] == 4)
            {
                if (firstMostCommon > secondMostCommon)
                    firstWin = true;
                    
                else if (firstMostCommon < secondMostCommon)
                    secondWin = true;
            }
            
            else
                firstWin = true;
        }
        
        else if (count[1][secondMostCommon] == 4)
            secondWin = true;
            
        else if (count[0][firstMostCommon] == 3 && count[0][firstSecondCommon] == 2)
        {
            if (count[1][secondMostCommon] == 3 && count[1][secondSecondCommon] == 2)
            {
                if (firstMostCommon > topTwoMostCommon[1][0] || (firstMostCommon == secondMostCommon && firstSecondCommon > secondSecondCommon))
                    firstWin = true;
                    
                else if (firstMostCommon < topTwoMostCommon[1][0] || (firstMostCommon == secondMostCommon && firstSecondCommon < secondSecondCommon))
                    secondWin = true;
            }
            else
                firstWin = true;
        }
        
        else if (count[1][secondMostCommon] && count[1][secondSecondCommon] == 2)
            secondWin = true;
         
        else if (flush[0])
        {
            if (flush[1])
            {
                firstWin = BetterThanOther(count[0], count[1], secondWin);
            }
            
            else
                firstWin = true;
        }
        
        else if (flush[1])
            secondWin = true;
        
        else if (straight[0])
        {
            if (straight[1])
            {
                if (firstMostCommon > secondMostCommon)
                    firstWin = true;
                    
                else if (firstMostCommon < secondMostCommon)
                    secondWin = true;
            }
            else
                firstWin = true;
        }
        
        else if (straight[1])
            secondWin = true;
            
        else if (count[0][firstMostCommon] == 3)
        {
            if (count[1][secondMostCommon] == 3)
            {
                if (firstMostCommon > secondMostCommon)
                    firstWin = true;
                    
                else if (firstMostCommon < secondMostCommon)
                    secondWin = true;
            }
            else
                firstWin = true;
        }
        
        else if (count[1][secondMostCommon] == 3)
            secondWin = true;
            
        else if (count[0][firstMostCommon] == 2 && count[0][firstSecondCommon] == 2)
        {
            if (count[1][secondMostCommon] == 2 && count[1][secondSecondCommon] == 2)
            {
                if (firstMostCommon > topTwoMostCommon[1][0] || (firstMostCommon == secondMostCommon && firstSecondCommon > secondSecondCommon))
                    firstWin = true;
                    
                else if (firstMostCommon < topTwoMostCommon[1][0] || (firstMostCommon == secondMostCommon && firstSecondCommon < secondSecondCommon))
                    secondWin = true;
                    
                else
                    firstWin = BetterThanOther(count[0], count[1], secondWin);
            }
            else
                firstWin = true;
        }
        
        else if (count[1][secondMostCommon] == 2 && count[1][secondSecondCommon] == 2)
            secondWin = true;
            
        else if (count[0][firstMostCommon] == 2)
        {
            if (count[1][secondMostCommon] == 2)
            {
                if (firstMostCommon > topTwoMostCommon[1][0])
                    firstWin = true;
                    
                else if (firstMostCommon < topTwoMostCommon[1][0])
                    secondWin = true;
                    
                else
                    firstWin = BetterThanOther(count[0], count[1], secondWin);
            }
            else
                firstWin = true;
        }
        
        else if (count[1][secondMostCommon] == 2)
            secondWin = true;
        
        else
            firstWin = BetterThanOther(count[0], count[1], secondWin);
        
        
        if (firstWin)
            printf("Black wins.\n");
        
        else if (secondWin)
            printf("White wins.\n");
        else
            printf("Tie.\n");
                
    }
    

}