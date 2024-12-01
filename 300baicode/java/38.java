import java.util.Scanner;

public class Main {
     static boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int cnt = 0;
        for (int i = 1; ; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
                cnt++;
            }
            if (cnt == k) break;
        }
    }
}