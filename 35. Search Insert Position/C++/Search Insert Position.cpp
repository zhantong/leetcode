class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            }
        }
        return nums[low] >= target ? low : (low + 1);
    }
};