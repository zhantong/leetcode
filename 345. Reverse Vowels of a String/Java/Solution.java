public class Solution {
    public String reverseVowels(String s) {
        int i = 0;
        int j = s.length() - 1;
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('A');
        vowels.add('E');
        vowels.add('I');
        vowels.add('O');
        vowels.add('U');
        char[] str = s.toCharArray();
        while (i < j) {
            if (!vowels.contains(str[i])) {
                i++;
            } else if (!vowels.contains(str[j])) {
                j--;
            } else {
                if (str[i] != str[j]) {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                i++;
                j--;
            }
        }
        return new String(str);
    }
}