public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k < 1 || t < 0) {
            return false;
        }
        Map<Long, Long> buckets = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            long adjustedNum = (long)nums[i] - Integer.MIN_VALUE;
            long bucket = adjustedNum / (t + 1);
            if (buckets.containsKey(bucket)
                || (buckets.containsKey(bucket - 1) && Math.abs(adjustedNum - buckets.get(bucket - 1)) <= t)
                || (buckets.containsKey(bucket + 1) && Math.abs(adjustedNum - buckets.get(bucket + 1)) <= t)) {
                return true;
            }
            buckets.put(bucket, adjustedNum);
            if (i >= k) {
                buckets.remove(((long) nums[i - k] - Integer.MIN_VALUE) / (t + 1));
            }
        }
        return false;
    }
}