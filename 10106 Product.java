import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNext())
        {
            BigInteger X = scanner.nextBigInteger();
            BigInteger Y = scanner.nextBigInteger();
            
            
            System.out.printf("%s\n", X.multiply(Y));
        }
    }
}