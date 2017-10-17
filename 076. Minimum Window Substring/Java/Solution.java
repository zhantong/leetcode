public class Solution {
    public String minWindow(String s, String t) {
        int[] memory = new int[128];
        for (char letter : t.toCharArray()) {
            memory[letter]++;
        }
        int count = t.length();
        int minLength = Integer.MAX_VALUE;
        int minStart = 0;
        int start = 0;
        int i = 0;
        while (i < s.length()) {
            char letter = s.charAt(i);
            if (memory[letter] > 0) {
                count--;
            }
            memory[letter]--;
            i++;
            while (count == 0) {
                if (i - start < minLength) {
                    minStart = start;
                    minLength = i - start;
                }
                memory[s.charAt(start)]++;
                if (memory[s.charAt(start)] > 0) {
                    count++;
                }
                start++;
            }
        }
        return minLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLength);
    }
}