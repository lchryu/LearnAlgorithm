import java.util.Scanner;

public class Main {

    public static int sumDigit(int n) {
        int s = 0;
        while (n != 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        System.out.println(sumDigit(n) % 10);
        if (sumDigit(n) % 10 == 9) System.out.println("may man");
        else System.out.println("chua may man");
    }
}
