import java.util.Scanner;

public class Main {
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numerator = sc.nextInt();
        int denominator = sc.nextInt();

        int _gcd = gcd(numerator, denominator);

        numerator /= _gcd;
        denominator /= _gcd;
        System.out.printf("%d/%d", numerator, denominator);
    }
}