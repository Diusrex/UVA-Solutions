#include <cstdio>
#include <map>

int main()
{
    std::map<char, int> suitConversion;
    suitConversion['S'] = 0;
    suitConversion['H'] = 1;
    suitConversion['D'] = 2;
    suitConversion['C'] = 3;
    
    char back[4] = {'S', 'H', 'D', 'C'};
    
    // Is ordered 'S', 'H', 'D', 'C'
    bool ace[4], king[4], queen[4], jack[4], trump[4];
    int count[4], points, specialPoints, pos;
    
    char temp[3];
    
    
    while (scanf("%s", temp) == 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            ace[i] = king[i] = queen[i] = jack[i] = trump[i] = false;
            count[i] = 0;
        }
        
        points = specialPoints = 0; 
            
        for (int i = 0; i < 13; ++i)
        {
            if (i != 0)
                scanf("%s", temp);
            
            pos = suitConversion[temp[1]];
            
            switch (temp[0])
            {
            case 'A':
                ace[pos] = true;
                points += 4;
                break;
                
            case 'K':
                king[pos] = true;
                points += 3;
                break;
                
            case 'Q':
                queen[pos] = true;
                points += 2;
                break;
                
            case 'J':
                jack[pos] = true;
                points += 1;
            }
            
            ++count[pos];
        }
        
        // Subtractions
        for (int i = 0; i < 4; ++i)
        {
            if (ace[i])
                trump[i] = true;
                
            if (king[i] && count[i] < 2)
                --points;
                
            else if (king[i])
                trump[i] = true;
                
            if (queen [i] && count[i] < 3)
                --points;
            
            else if (queen[i])
                trump[i] = true;
                
            if (jack[i] && count[i] < 4)
                --points;
            
            if (count[i] == 2)
                ++specialPoints;
            
            else if (count[i] < 2)
                specialPoints += 2;
        }
        
        if (trump[0] && trump[1] && trump[2] && trump[3] && points >= 16)
            printf("BID NO-TRUMP\n");
            
        else if (points + specialPoints >= 14)
        {
            char output = 'S';
            int max = 0;
            for (int i = 1; i < 4; ++i)
            {
                if (count[i] > count[max])
                {
                    max = i;
                    output = back[i];
                }
                
                
            }
            printf("BID %c\n", output);
        }
        else
            printf("PASS\n");
    }
    
    
}