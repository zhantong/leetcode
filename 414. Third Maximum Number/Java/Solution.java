public class Solution {
    public int thirdMax(int[] nums) {
        long first = Long.MIN_VALUE;
        long second = Long.MIN_VALUE;
        long third = Long.MIN_VALUE;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num >= third && num < second) {
                third = num;
            }
        }
        if (third == Long.MIN_VALUE) {
            return (int) first;
        }
        return (int) third;
    }
}