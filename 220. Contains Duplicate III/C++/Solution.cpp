class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0) {
            return false;
        }
        unordered_map<long, long> buckets;
        for (int i = 0; i < nums.size(); i++) {
            long adjustedNum = (long) nums[i] - INT_MIN;
            long bucket = adjustedNum / (t + 1);
            if (buckets.find(bucket) != buckets.end()
                || (buckets.find(bucket - 1) != buckets.end() && abs(adjustedNum - buckets[bucket - 1]) <= t)
                || (buckets.find(bucket + 1) != buckets.end() && abs(adjustedNum - buckets[bucket + 1]) <= t)) {
                return true;
            }
            buckets[bucket] = adjustedNum;
            if (i >= k) {
                buckets.erase(((long) nums[i - k] - INT_MIN) / (t + 1));
            }
        }
        return false;
    }
};