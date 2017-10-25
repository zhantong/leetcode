class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        Map<Integer, Integer> starts = new HashMap<>();
        Map<Integer, Integer> ends = new HashMap<>();
        int maxCount = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (!starts.containsKey(num)) {
                starts.put(num, i);
                counts.put(num, 0);
            }
            counts.put(num, counts.get(num) + 1);
            ends.put(num, i);
            maxCount = Math.max(maxCount, counts.get(num));
        }
        int result = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getValue() == maxCount) {
                result = Math.min(result, ends.get(entry.getKey()) - starts.get(entry.getKey()) + 1);
            }
        }
        return result;
    }
}