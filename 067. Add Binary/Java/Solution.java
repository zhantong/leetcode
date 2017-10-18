public class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        StringBuilder builder = new StringBuilder();
        while (i >= 0 || j >= 0 || carry != 0) {
            int count = 0;
            if (i >= 0) {
                if (a.charAt(i) == '1') {
                    count++;
                }
                i--;
            }
            if (j >= 0) {
                if (b.charAt(j) == '1') {
                    count++;
                }
                j--;
            }
            count += carry;
            switch (count) {
            case 0:
                builder.append('0');
                carry = 0;
                break;
            case 1:
                builder.append('1');
                carry = 0;
                break;
            case 2:
                builder.append(0);
                carry = 1;
                break;
            case 3:
                builder.append('1');
                carry = 1;
                break;
            }
        }
        return builder.reverse().toString();
    }
}