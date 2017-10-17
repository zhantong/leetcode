public class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] counts = new int[26];
        int currentMax = 0;
        char[] str = p.toCharArray();
        for (int i = 0; i < str.length; i++) {
            if (i > 0 && (str[i] - str[i - 1] == 1 || str[i - 1] - str[i] == 25)) {
                currentMax++;
            } else {
                currentMax = 1;
            }
            int index = str[i] - 'a';
            counts[index] = Math.max(counts[index], currentMax);
        }
        int theSum = 0;
        for (int count : counts) {
            theSum += count;
        }
        return theSum;
    }
}