public class Solution {
    public int lengthOfLastWord(String s) {
        int length = 0;
        int index = s.length() - 1;
        while (index >= 0 && s.charAt(index) == ' ') {
            index--;
        }
        while (index >= 0 && s.charAt(index) != ' ') {
            index--;
            length++;
        }
        return length;
    }
}