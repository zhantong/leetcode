public class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        boolean hasDot = false;
        boolean hasE = false;
        boolean hasNumber = false;
        boolean hasNumberAfterE = false;
        for (int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if (letter >= '0' && letter <= '9') {
                hasNumber = true;
                if (hasE) {
                    hasNumberAfterE = true;
                }
            } else if (letter == '.') {
                if (hasDot || hasE) {
                    return false;
                }
                hasDot = true;
            } else if (letter == 'e') {
                if (hasE || !hasNumber) {
                    return false;
                }
                hasE = true;
            } else if (letter == '+' || letter == '-') {
                if (i != 0 && s.charAt(i - 1) != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return (!(hasE ^ hasNumberAfterE)) && hasNumber;
    }
}