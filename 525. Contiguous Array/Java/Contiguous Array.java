public class Solution {
    public int findMaxLength(int[] nums) {
        int result = 0;
        int[] soFar = new int[nums.length + 1];
        Map<Integer, Integer> memory = new HashMap<>();
        memory.put(0, 0);
        for (int i = 1; i <= nums.length; i++) {
            soFar[i] = soFar[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
            if (!memory.containsKey(soFar[i])) {
                memory.put(soFar[i], i);
            } else {
                result = Math.max(result, i - memory.get(soFar[i]));
            }
        }
        return result;
    }
}