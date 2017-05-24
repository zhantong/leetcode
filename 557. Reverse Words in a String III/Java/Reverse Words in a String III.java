public class Solution {
    public String reverseWords(String s) {
        int length = s.length();
        char[] str = s.toCharArray();
        int i = 0;
        while (i < length && str[i] == ' ') {
            i++;
        }
        int j = i;
        while (j < length) {
            while (j < length && str[j] != ' ') {
                j++;
            }
            int low = i;
            int high = j - 1;
            while (low < high) {
                char temp = str[low];
                str[low] = str[high];
                str[high] = temp;
                low++;
                high--;
            }
            while (j < length && str[j] == ' ') {
                j++;
            }
            i = j;
        }
        return new String(str);
    }
}