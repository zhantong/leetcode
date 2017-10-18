class Solution {
public:
    bool makesquare(vector<int> &nums) {
        class Utils {
        public:
            bool square(vector<int> &nums, vector<int> &edges, int start) {
                if (start == nums.size()) {
                    return edges[0] == 0 && edges[1] == 0 && edges[2] == 0 && edges[3] == 0;
                }
                int current = nums[start];
                for (int i = 0; i < edges.size(); i++) {
                    if (edges[i] >= current) {
                        edges[i] -= current;
                        if (square(nums, edges, start + 1)) {
                            return true;
                        }
                        edges[i] += current;
                    }
                }
                return false;
            }
        };
        if (nums.size() < 4) {
            return false;
        }
        int sumNums = 0;
        for (const auto &num : nums) {
            sumNums += num;
        }
        if (sumNums % 4 != 0) {
            return false;
        }
        vector<int> edges(4, sumNums / 4);
        sort(nums.begin(), nums.end(), greater<int>());
        Utils utils;
        return utils.square(nums, edges, 0);
    }
};