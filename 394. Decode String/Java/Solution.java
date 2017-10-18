public class Solution {
    int index = 0;
    public String decodeString(String s) {
        StringBuilder builder = new StringBuilder();
        while (index < s.length() && s.charAt(index) != ']') {
            char letter = s.charAt(index);
            if (Character.isDigit(letter)) {
                int count = 0;
                while (index < s.length() && Character.isDigit(s.charAt(index))) {
                    count = count * 10 + Character.getNumericValue(s.charAt(index));
                    index++;
                }
                index++;
                String subString = decodeString(s);
                index++;
                for (int i = 0; i < count; i++) {
                    builder.append(subString);
                }
            } else {
                builder.append(letter);
                index++;
            }
        }
        return builder.toString();
    }
}