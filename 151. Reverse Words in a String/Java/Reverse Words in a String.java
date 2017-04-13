public class Solution {
    public String reverseWords(String s) {
        class Utils {
            void reverse(char[] s, int i, int j) {
                while (i < j) {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
        }
        int i = 0;
        int j = 0;
        char[] letters = s.toCharArray();
        while (j < letters.length && letters[j] == ' ') {
            j++;
        }
        while (j < letters.length) {
            if (letters[j] != ' ' || (letters[j] == ' ' && j < letters.length - 1 && letters[j + 1] != ' ')) {
                letters[i] = letters[j];
                i++;
            }
            j++;
        }
        int length = i;
        Utils utils = new Utils();
        utils.reverse(letters, 0, length - 1);
        i = 0;
        for (j = 0; j < length; j++) {
            if (j + 1 == length || letters[j + 1] == ' ') {
                utils.reverse(letters, i, j);
                i = j + 2;
            }
        }
        return String.valueOf(letters, 0, length);
    }
}