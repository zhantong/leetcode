class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> map(maxNum + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i + 1;
        }
        vector<string> result(nums.size());
        int rank = 1;
        for (int i = map.size() - 1; i > -1; i--) {
            int index = map[i];
            if (index > 0) {
                string value;
                if (rank == 1) {
                    value = "Gold Medal";
                } else if (rank == 2) {
                    value = "Silver Medal";
                } else if (rank == 3) {
                    value = "Bronze Medal";
                } else {
                    value = to_string(rank);
                }
                result[index - 1] = value;
                rank++;
            }
        }
        return result;
    }
};