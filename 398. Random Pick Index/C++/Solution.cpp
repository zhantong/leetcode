class Solution {
public:
    vector<int> nums;

    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int count = 1;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (rand() % count == 0) {
                    result = i;
                }
                count++;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */