public class Solution {
    public void wiggleSort(int[] nums) {
        class Utils {
            int partition(int[] nums, int low, int high) {
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

            int kthLargest(int[] nums, int k) {
                Random random = new Random();
                for (int i = 0; i < nums.length; i++) {
                    int j = i + random.nextInt(nums.length - i);
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                int low = 0;
                int high = nums.length - 1;
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
        }
        Utils utils = new Utils();
        int[] copy = Arrays.copyOf(nums, nums.length);
        int medium = utils.kthLargest(copy, copy.length / 2);
        int largeIndex = 1;
        for (int i = 0; i < copy.length; i++) {
            if (copy[i] > medium) {
                nums[largeIndex] = copy[i];
                largeIndex += 2;
            }
        }
        while (largeIndex < copy.length) {
            nums[largeIndex] = medium;
            largeIndex += 2;
        }
        int smallIndex = largeIndex == copy.length ? (largeIndex - 1) : (largeIndex - 3);
        for (int i = 0; i < copy.length; i++) {
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
}