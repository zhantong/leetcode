public class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) {
            return 0;
        }
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 0);
            }
            counts.put(num, counts.get(num) + 1);
        }
        int result = 0;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (k == 0) {
                if (entry.getValue() >= 2) {
                    result++;
                }
            } else {
                if (counts.containsKey(entry.getKey() + k)) {
                    result++;
                }
            }
        }
        return result;
    }
}