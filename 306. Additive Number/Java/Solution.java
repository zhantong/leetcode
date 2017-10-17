public class Solution {
    public boolean isAdditiveNumber(String num) {
        class Utils {
            boolean isAdditive(int second, int third, String num) {
                if (num.charAt(second) == '0' && third - second > 1) {
                    return false;
                }
                int first = 0;
                while (third < num.length()) {
                    long a = Integer.parseInt(num.substring(first, second));
                    long b = Integer.parseInt(num.substring(second, third));
                    String theSum = String.valueOf(a + b);
                    if (!num.substring(third).startsWith(theSum)) {
                        return false;
                    }
                    first = second;
                    second = third;
                    third += theSum.length();
                }
                return true;
            }
        }
        Utils utils = new Utils();
        for (int second = 1; second < num.length(); second++) {
            if (num.charAt(0) == '0' && second > 1) {
                continue;
            }
            for (int third = second + 1; third < num.length(); third++) {
                if (second <= num.length() - third && third - second <= num.length() - third) {
                    if (utils.isAdditive(second, third, num)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}