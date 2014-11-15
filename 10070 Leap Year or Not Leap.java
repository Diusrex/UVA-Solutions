import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
    public static void main (String args[])
    {
        BigInteger year;
        
        BufferedReader inputHandler = new BufferedReader(new InputStreamReader(System.in));
        
        boolean first = true;
        
        String line;
        try {
        line = inputHandler.readLine();
        
        while (line != null) {
            if (!first)
                System.out.println();
            first = false;
            
            year = new BigInteger(line);
            boolean isLeapYear = mod(year, 4) && (mod(year, 400) || !mod(year, 100));
            boolean isSpecial = isLeapYear;
            
            if (isLeapYear)
                System.out.println("This is leap year.");
            
            if (mod(year, 15))
            {
                System.out.println("This is huluculu festival year.");
                isSpecial = true;
            }
            
            if (mod(year, 55) && isLeapYear)
                System.out.println("This is bulukulu festival year.");
            
            if (!isSpecial)
                System.out.println("This is an ordinary year.");
            line = inputHandler.readLine();
        }
        } catch (Exception e) {
            // Better not reach here
        }
    }
    
    static boolean mod(BigInteger year, int i) {
        return year.mod(BigInteger.valueOf(i)).compareTo(BigInteger.ZERO)==0;
    }
}