class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        class Utils {
        public:
            int search(vector<int> &nums, int target) {
                int low = 0;
                int high = nums.size() - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (nums[mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return low;
            }
        };
        if (nums.size() == 0) {
            return vector<int> {-1, -1};
        }
        Utils utils;
        int low = utils.search(nums, target);
        int high = utils.search(nums, target + 1);
        high--;
        if (low < nums.size() && nums[low] == target) {
            return vector<int> {low, high};
        }
        return vector<int> {-1, -1};
    }
};