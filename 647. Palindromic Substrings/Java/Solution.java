class Solution {
    public int countSubstrings(String s) {
        class Utils {
            int result;

            void count(String s, int left, int right) {
                while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                    result++;
                    left--;
                    right++;
                }
            }
        }
        Utils utils = new Utils();
        for (int i = 0; i < s.length(); i++) {
            utils.count(s, i, i);
            utils.count(s, i, i + 1);
        }
        return utils.result;
    }
}