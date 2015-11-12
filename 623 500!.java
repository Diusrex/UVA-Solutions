import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    static BigInteger allFacs[];
    public static void main (String args[])
    {
        allFacs = new BigInteger[1005];
        allFacs[0] = new BigInteger("1");
        for (int i = 1; i <= 1000; ++i)
        {
            allFacs[i] = allFacs[i -1].multiply(BigInteger.valueOf(i));
        }
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNextInt())
        {
            int i = scanner.nextInt();
            
            System.out.printf("%d!\n%s\n", i, allFacs[i]);
        }
    }
}