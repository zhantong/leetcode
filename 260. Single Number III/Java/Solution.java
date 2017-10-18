public class Solution {
    public int[] singleNumber(int[] nums) {
        int mixedXor = 0;
        for (int num : nums) {
            mixedXor ^= num;
        }
        int diff = mixedXor & (mixedXor - 1) ^ mixedXor;
        int first = 0;
        int second = 0;
        for (int num : nums) {
            if ((diff & num) == 0) {
                first ^= num;
            } else {
                second ^= num;
            }
        }
        return new int[] {first, second};
    }
}