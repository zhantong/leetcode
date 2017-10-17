public class Solution {
    public int findMaximumXOR(int[] nums) {
        int result = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= 1 << i;
            Set<Integer> numsSet = new HashSet<>();
            for (int num : nums) {
                numsSet.add(num & mask);
            }
            int current = result | (1 << i);
            for (int num : numsSet) {
                if (numsSet.contains(num ^ current)) {
                    result = current;
                    break;
                }
            }
        }
        return result;
    }
}