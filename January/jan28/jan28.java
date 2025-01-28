import java.util.*;

public class Permutations {
    public static void generatePermutations(char[] s, List<String> result, int index) {
        // Base case: If index reaches the end, add the current permutation
        if (index == s.length) {
            result.add(new String(s));
            return;
        }

        Set<Character> used = new HashSet<>(); // Set to track characters used at this level

        for (int i = index; i < s.length; i++) {
            if (used.contains(s[i])) continue; // Skip duplicates
            used.add(s[i]); // Mark the character as used
            swap(s, index, i); // Swap
            generatePermutations(s, result, index + 1); // Recurse
            swap(s, index, i); // Backtrack
        }
    }

    private static void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    public static List<String> findPermutation(String s) {
        List<String> result = new ArrayList<>();
        generatePermutations(s.toCharArray(), result, 0);
        return result;
    }

    public static void main(String[] args) {
        System.out.println(findPermutation("AAB"));
    }
}
