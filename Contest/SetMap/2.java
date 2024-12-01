import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Read the number of elements
        TreeMap<Integer, Integer> frequencyMap = new TreeMap<>();  // TreeMap to store numbers and their frequencies

        // Read the input numbers and store frequencies in the map
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Output the numbers and their frequencies in ascending order (automatically sorted by TreeMap)
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }

        sc.close();
    }
}
