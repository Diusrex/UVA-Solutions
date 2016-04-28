import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    static final int MaxOverallSize = 10005, MaxSubstrSize = 105;

    static BigInteger[][] numOccurances = new BigInteger[MaxOverallSize][MaxSubstrSize];
    
    static String mainstr;
    static String substr;

    public static void main (String args[])
    {
        
        Scanner scanner = new Scanner(System.in);
        
        
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            mainstr = scanner.next();
            substr = scanner.next();
        
            for (int i = 0; i < mainstr.length(); ++i)
                for (int j = 0; j < substr.length(); ++j)
                    numOccurances[i][j] = null;
                
            System.out.printf("%s\n", GetNumOccurances(0, 0).toString());
        }
    }
    
    static BigInteger GetNumOccurances(int mainstrPos, int substrPos) {
        if (substrPos == substr.length())
            return BigInteger.ONE;
        else if (mainstrPos == mainstr.length())
            return BigInteger.ZERO;
        
        if (numOccurances[mainstrPos][substrPos] == null)
        {
            BigInteger occurances = GetNumOccurances(mainstrPos + 1, substrPos);
            
            if (mainstr.charAt(mainstrPos) == substr.charAt(substrPos))
            {
                occurances = occurances.add(GetNumOccurances(mainstrPos + 1, substrPos + 1));
            }
            
            numOccurances[mainstrPos][substrPos] = occurances;
        }
        
        return numOccurances[mainstrPos][substrPos];
    }
}