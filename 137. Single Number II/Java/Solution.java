public class Solution {
    public int singleNumber(int[] nums) {
        int x1 = 0;
        int x2 = 0;
        int mask;
        for (int num : nums) {
            x2 ^= x1 & num;
            x1 ^= num;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
}