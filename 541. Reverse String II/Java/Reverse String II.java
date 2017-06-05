public class Solution {
    public String reverseStr(String s, int k) {
        class Utils {
            void reverse(char[] str, int start, int end) {
                while (start < end) {
                    char temp = str[start];
                    str[start] = str[end];
                    str[end] = temp;
                    start++;
                    end--;
                }
            }
        }
        Utils utils = new Utils();
        int length = s.length();
        char[] str = s.toCharArray();
        for (int i = 0; i < length; i += 2 * k) {
            if (i + k >= length) {
                utils.reverse(str, i, length - 1);
            } else {
                utils.reverse(str, i, i + k - 1);
            }
        }
        return new String(str);
    }
}