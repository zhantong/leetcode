class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int result = 0;
        Map<Integer, Integer> memory = new HashMap<>();
        memory.put(0, 1);
        for (int num : nums) {
            sum += num;
            if (memory.containsKey(sum - k)) {
                result += memory.get(sum - k);
            }
            if (!memory.containsKey(sum)) {
                memory.put(sum, 0);
            }
            memory.put(sum, memory.get(sum) + 1);
        }
        return result;
    }
}