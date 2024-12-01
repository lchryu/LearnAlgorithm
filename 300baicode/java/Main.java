import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine().toLowerCase();
        Map<Character, Integer> m = new HashMap<>();

        // Đếm tần suất xuất hiện của từng ký tự
        for (char c : s.toCharArray()) {
            m.put(c, m.getOrDefault(c, 0) + 1);
        }

        // In ra ký tự và tần suất xuất hiện của nó
        for (char c : s.toCharArray()) { // lấy ra thứ tự xuất hiện
            if (m.containsKey(c)) {
                System.out.print(c + ":" + m.get(c) + " ");
                m.remove(c); // xoá ra khỏi map
            }
        }
    }
}
