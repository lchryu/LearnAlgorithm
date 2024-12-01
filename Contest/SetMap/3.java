import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Read the number of elements
        int[] a = new int[n];  // Array to store the input values
        Map<Integer, Integer> frequencyMap = new HashMap<>();  // Map to store the frequencies

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            frequencyMap.put(a[i], frequencyMap.getOrDefault(a[i], 0) + 1);
        }

        // Print each element in the order it appears, along with its frequency
        for (int e : a) {
            if (frequencyMap.containsKey(e)) {  // Check if the element exists in the map
                System.out.println(e + " " + frequencyMap.get(e));  // Print the element and its frequency
                frequencyMap.remove(e);  // Remove the element from the map to ensure it is printed only once
            }
        }

        sc.close();
    }
}
