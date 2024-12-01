import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();  // Read the number of elements
        Map<Integer, Integer> map = new HashMap<>();  // Create a HashMap to store the elements and their frequencies
        
        // Read the N numbers and store their occurrences in the map
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        int q = sc.nextInt();  // Read the number of queries
        
        // For each query, check if the number exists in the map
        for (int i = 0; i < q; i++) {
            int query = sc.nextInt();
            if (map.containsKey(query)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        sc.close();
    }
}
