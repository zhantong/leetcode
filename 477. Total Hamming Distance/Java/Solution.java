public class Solution {
    public int totalHammingDistance(int[] nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int base = 1 << i;
            int countOne = 0;
            for (int num : nums) {
                if ((base & num) != 0) {
                    countOne++;
                }
            }
            result += countOne * (nums.length - countOne);
        }
        return result;
    }
}