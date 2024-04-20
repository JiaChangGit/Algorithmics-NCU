import java.math.BigInteger;
import java.util.Scanner;

public class BigExponentialAddtion {
    private static Scanner input;

    public static void main(String[] args) {
        input = new Scanner(System.in);
        while (input.hasNext()) {
            System.out.println(execute(input.nextInt(), input.nextInt()));
        }
    }

    private static BigInteger execute(Integer poll, Integer poll2) {
        BigInteger a = new BigInteger(String.valueOf("2"));
        return a.pow(poll).add(a.pow(poll2));
    }
}