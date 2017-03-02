class Solution {
public:
    vector<int> origin;
    vector<int> nums;

    Solution(vector<int> nums) {
        origin = nums;
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int swapIndex = rand() % length;
            int temp = nums[i];
            nums[i] = nums[swapIndex];
            nums[swapIndex] = temp;
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */