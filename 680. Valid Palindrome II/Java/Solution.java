class Solution {
    public boolean validPalindrome(String s) {
        class Utils {
            boolean isPalindrome(String s, int left, int right) {
                while (left < right) {
                    if (s.charAt(left) != s.charAt(right)) {
                        return false;
                    }
                    left++;
                    right--;
                }
                return true;
            }
        }
        int left = 0;
        int right = s.length() - 1;
        Utils utils = new Utils();
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return utils.isPalindrome(s, left + 1, right) || utils.isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
}