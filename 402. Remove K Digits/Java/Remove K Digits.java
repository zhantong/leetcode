public class Solution {
    public String removeKdigits(String num, int k) {
        int i = 0;
        while (i < num.length() - 1 && k > 0) {
            if (num.charAt(i) > num.charAt(i + 1)) {
                num = num.substring(0, i) + num.substring(i + 1, num.length());
                k--;
                if (i > 0) {
                    i--;
                }
            } else {
                i++;
            }
        }
        while (!num.isEmpty() && k > 0) {
            num = num.substring(0, num.length() - 1);
            k--;
        }
        while (!num.isEmpty() && num.charAt(0) == '0') {
            num = num.substring(1, num.length());
        }
        if (num.isEmpty()) {
            return "0";
        }
        return num;
    }
}