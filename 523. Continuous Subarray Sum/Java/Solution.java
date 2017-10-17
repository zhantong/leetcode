public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> memory = new HashMap<>();
        memory.put(0, -1);
        int currentSum = 0;
        for (int i = 0; i < nums.length; i++) {
            currentSum += nums[i];
            if (k != 0) {
                currentSum %= k;
            }
            if (memory.containsKey(currentSum)) {
                if (i - memory.get(currentSum) > 1) {
                    return true;
                }
            } else {
                memory.put(currentSum, i);
            }
        }
        return false;
    }
}