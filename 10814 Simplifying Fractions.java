import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int N;
        
        N = scanner.nextInt();
        
        while (N-- != 0)
        {
            BigInteger numerator = scanner.nextBigInteger();
            scanner.next(); // Get rid of /
            BigInteger denominator = scanner.nextBigInteger();
            
            BigInteger n1 = numerator;
            BigInteger n2 = denominator;
            while (!n1.equals(BigInteger.ZERO))
            {
                BigInteger temp = n1;
                n1  = n2.mod(n1);
                n2 = temp;
            }
            
            System.out.printf("%s / %s\n", numerator.divide(n2).toString(), denominator.divide(n2).toString());
        }
    }
}