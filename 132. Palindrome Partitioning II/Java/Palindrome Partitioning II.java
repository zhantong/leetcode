public class Solution {
    public int minCut(String s) {
        int length = s.length();
        int[] cuts = new int[length];
        boolean[][] palindrome = new boolean[length][length];
        for (int i = 0; i < length; i++) {
            int current = i;
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) == s.charAt(j) && (i - j < 2 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = true;
                    current = j == 0 ? 0 : Math.min(current, cuts[j - 1] + 1);
                }
            }
            cuts[i] = current;
        }
        return cuts[length - 1];
    }
}