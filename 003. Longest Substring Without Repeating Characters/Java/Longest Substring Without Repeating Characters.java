public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> memory = new HashMap<>();
        int result = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if (memory.containsKey(letter)) {
                j = Math.max(j, memory.get(letter) + 1);
            }
            memory.put(letter, i);
            result = Math.max(result, i - j + 1);
        }
        return result;
    }
}