import java.util.Scanner;

public class Main {
    public static boolean isLeapYear(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int month = scanner.nextInt();
        int year = scanner.nextInt();
        int day;

        switch (month) {
            case 1, 3, 5, 7, 8, 10, 12 -> day = 31;
            case 2 -> {
                if (isLeapYear(year)) {
                    day = 29;
                } else {
                    day = 28;
                }
            }
            default -> day = 30;
        }

        System.out.println(day);
    }
}
