import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Đọc số nguyên n từ đầu vào
        int n = scanner.nextInt();

        // In số lượng tiền tương ứng cho 5000, 2000 và 1000
        System.out.print(n / 5000 + " ");
        n %= 5000;

        System.out.print(n / 2000 + " ");
        n %= 2000;

        System.out.print(n / 1000 + " ");
        n %= 1000;
    }
}
