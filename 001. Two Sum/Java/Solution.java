public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> needs = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (needs.containsKey(num)) {
                return new int[] {needs.get(num), i};
            }
            needs.put(target - num, i);
        }
        return null;
    }
}