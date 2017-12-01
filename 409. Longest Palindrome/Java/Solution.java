public class Solution {
    public int longestPalindrome(String s) {
        int[] countArray = new int['z' - 'A' + 1];
        int pair = 0;
        boolean isOddExists = false;
        for (char item : s.toCharArray()) {
            countArray[item - 'A']++;
        }
        for (int item : countArray) {
            pair += item / 2;
            if (!isOddExists) {
                isOddExists = item % 2 != 0;
            }
        }
        return pair * 2 + (isOddExists ? 1 : 0);
    }
}