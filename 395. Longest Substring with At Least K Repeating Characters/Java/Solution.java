public class Solution {
    public int longestSubstring(String s, int k) {
        class Utils {
            int substring(String s, int k, int start, int end) {
                if (start >= end) {
                    return 0;
                }
                int[] counts = new int[26];
                for (int i = start; i < end; i++) {
                    counts[s.charAt(i) - 'a']++;
                }
                int subStart = start;
                int maxLength = -1;
                for (int i = start; i < end; i++) {
                    if (counts[s.charAt(i) - 'a'] < k) {
                        int subLength = substring(s, k, subStart, i);
                        subStart = i + 1;
                        maxLength = Math.max(maxLength, subLength);
                    }
                }
                if (subStart != start) {
                    int subLength = substring(s, k, subStart, end);
                    maxLength = Math.max(maxLength, subLength);
                }
                if (maxLength == -1) {
                    return end - start;
                }
                return maxLength;
            }
        }
        Utils utils = new Utils();
        return utils.substring(s, k, 0, s.length());
    }
}