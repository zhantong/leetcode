class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        int j = 1;
        int length = nums.size();
        while (j < length) {
            if (nums[i] != nums[j]) {
                if ((i + 1) == j) {
                    i++;
                    j++;
                } else {
                    nums[i + 1] = nums[j];
                    i++;
                    j++;
                }
            } else {
                j++;
            }
        }
        return length == 0 ? i : (i + 1);
    }
};