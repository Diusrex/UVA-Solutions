import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
    public static void main (String args[])
    {
        BigInteger sum = new BigInteger("0"), current;
        String line;

        BufferedReader inputHandler = new BufferedReader(new InputStreamReader(System.in));

        try {
            line = inputHandler.readLine();
            while (!line.equals("0")) {
                current = new BigInteger(line);
                
                sum = sum.add(current);
                line = inputHandler.readLine();
            }
        } catch (Exception e) {
            // I don't care java....
        }
        
        System.out.println(sum.toString());
    }

}