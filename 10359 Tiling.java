import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        BigInteger two = new BigInteger("2");
        BigInteger[] numbers = new BigInteger[301];
        numbers[0] = new BigInteger("1");
        numbers[1] = new BigInteger("1");
        
        for (int i = 2; i <= 300; ++i) {
            numbers[i] = numbers[i - 1].add(numbers[i - 2].multiply(two));
        }
        
        Scanner scanner = new Scanner(System.in);
        
        
        while (scanner.hasNext()) {
            int num = scanner.nextInt();
            System.out.printf("%s\n", numbers[num].toString());
        }
    }
}