class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current = 0;
            int j = i;
            while (nums[j] >= 0) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
                current++;
            }
            result = max(result, current);
        }
        return result;
    }
};