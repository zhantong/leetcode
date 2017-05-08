class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        class Utils {
        public:
            vector<int> maxNumberLengthK(vector<int> &nums, int k) {
                vector<int> result(k);
                int index = 0;
                int length = nums.size();
                for (int i = 0; i < length; i++) {
                    while (index > 0 && result[index - 1] < nums[i] && length - i >= k - (index - 1)) {
                        index--;
                    }
                    if (index < k) {
                        result[index] = nums[i];
                        index++;
                    }
                }
                return result;
            }

            void merge(const vector<int> &nums1, const vector<int> &nums2, vector<int> &result) {
                int i = 0;
                int j = 0;
                while (i < nums1.size() && j < nums2.size()) {
                    if (greater(nums1, i, nums2, j)) {
                        result.push_back(nums1[i]);
                        i++;
                    } else {
                        result.push_back(nums2[j]);
                        j++;
                    }
                }
                if (i == nums1.size()) {
                    while (j < nums2.size()) {
                        result.push_back(nums2[j]);
                        j++;
                    }
                } else {
                    while (i < nums1.size()) {
                        result.push_back(nums1[i]);
                        i++;
                    }
                }
            }

            bool greater(const vector<int> &nums1, int start1, const vector<int> &nums2, int start2) {
                while (start1 < nums1.size() && start2 < nums2.size() && nums1[start1] == nums2[start2]) {
                    start1++;
                    start2++;
                }
                if (start1 == nums1.size() && start2 == nums2.size()) {
                    return true;
                }
                if (start1 == nums1.size()) {
                    return false;
                }
                if (start2 == nums2.size()) {
                    return true;
                }
                return nums1[start1] > nums2[start2];
            }
        };
        Utils utils;
        vector<int> result(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i <= nums1.size() && k - i <= nums2.size()) {
                vector<int> current;
                utils.merge(utils.maxNumberLengthK(nums1, i), utils.maxNumberLengthK(nums2, k - i), current);
                if (utils.greater(current, 0, result, 0)) {
                    result = current;
                }
            }
        }
        return result;
    }
};