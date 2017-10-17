public class Solution {
    public boolean judgeSquareSum(int c) {
        int left = 0;
        int right = (int) Math.sqrt(c);
        while (left <= right) {
            int current = left * left + right * right;
            if (current == c) {
                return true;
            } else if (current < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
}