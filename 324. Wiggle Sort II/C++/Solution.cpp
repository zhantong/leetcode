class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        class Utils {
        public:
            int partition(vector<int> &nums, int low, int high) {
                int pivot = nums[low];
                while (low < high) {
                    while (low < high && nums[high] >= pivot) {
                        high--;
                    }
                    nums[low] = nums[high];
                    while (low < high && nums[low] <= pivot) {
                        low++;
                    }
                    nums[high] = nums[low];
                }
                nums[low] = pivot;
                return low;
            }

            int kthLargest(vector<int> &nums, int k) {
                random_shuffle(nums.begin(), nums.end());
                int low = 0;
                int high = nums.size() - 1;
                while (low < high) {
                    int index = partition(nums, low, high);
                    if (index == k) {
                        break;
                    } else if (index > k) {
                        high = index - 1;
                    } else {
                        low = index + 1;
                    }
                }
                return nums[k];
            }
        };
        Utils utils;
        vector<int> copy(nums);
        int medium = utils.kthLargest(copy, copy.size() / 2);
        int largeIndex = 1;
        for (int i = 0; i < copy.size(); i++) {
            if (copy[i] > medium) {
                nums[largeIndex] = copy[i];
                largeIndex += 2;
            }
        }
        while (largeIndex < copy.size()) {
            nums[largeIndex] = medium;
            largeIndex += 2;
        }
        int smallIndex = largeIndex == copy.size() ? (largeIndex - 1) : (largeIndex - 3);
        for (int i = 0; i < copy.size(); i++) {
            if (copy[i] < medium) {
                nums[smallIndex] = copy[i];
                smallIndex -= 2;
            }
        }
        while (smallIndex >= 0) {
            nums[smallIndex] = medium;
            smallIndex -= 2;
        }
    }
};