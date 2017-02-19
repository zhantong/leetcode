public class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int index = digits.length - 1;
        while (carry == 1 && index >= 0) {
            if (digits[index] == 9) {
                digits[index] = 0;
            } else {
                digits[index]++;
                carry = 0;
            }
            index--;
        }
        if (digits[0] == 0) {
            digits = new int[digits.length + 1];
            digits[0] = 1;
        }
        return digits;
    }
}