class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> counts;
        unordered_map<int, int> starts;
        unordered_map<int, int> ends;
        int maxCount = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (starts.count(num) == 0) {
                starts[num] = i;
                counts[num] = 0;
            }
            counts[num]++;
            ends[num] = i;
            maxCount = max(maxCount, counts[num]);
        }
        int result = INT_MAX;
        for (auto &item : counts) {
            if (item.second == maxCount) {
                result = min(result, ends[item.first] - starts[item.first] + 1);
            }
        }
        return result;
    }
};