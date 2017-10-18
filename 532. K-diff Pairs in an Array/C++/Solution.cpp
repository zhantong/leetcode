class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        int result = 0;
        for (auto &item : counts) {
            if (k == 0) {
                if (item.second >= 2) {
                    result++;
                }
            } else {
                if (counts.find(item.first + k) != counts.end()) {
                    result++;
                }
            }
        }
        return result;
    }
};