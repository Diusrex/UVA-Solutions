import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        
 
        BigInteger fib[] = new BigInteger[5001];
        fib[0] = BigInteger.valueOf(0);
        fib[1] = BigInteger.valueOf(1);
        
        int n = 2;
        
        for (; n < 5001; ++n)
            fib[n] = fib[n - 1].add(fib[n - 2]);
        
        Scanner scanner = new Scanner(System.in);
        
        
        while (scanner.hasNext()) {
            int num = scanner.nextInt();
            System.out.printf("The Fibonacci number for %d is %s\n", num, fib[num].toString());
        }
    }
}