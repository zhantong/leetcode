public class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> memory = new HashMap<>();
        for (int num : nums) {
            if (!memory.containsKey(num)) {
                memory.put(num, 0);
            }
            memory.put(num, memory.get(num) + 1);
        }
        int result = 0;
        for (int key : memory.keySet()) {
            if (memory.containsKey(key + 1)) {
                result = Math.max(result, memory.get(key) + memory.get(key + 1));
            }
        }
        return result;
    }
}