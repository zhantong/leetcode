class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        class Utils {
            boolean partition(int[] nums, int[] currents, int target, int start) {
                if (start == -1) {
                    return true;
                }
                for (int i = 0; i < currents.length; i++) {
                    if (currents[i] + nums[start] <= target) {
                        currents[i] += nums[start];
                        if (partition(nums, currents, target, start - 1)) {
                            return true;
                        }
                        currents[i] -= nums[start];
                    }
                }
                return false;
            }
        }
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        Arrays.sort(nums);
        Utils utils = new Utils();
        return utils.partition(nums, new int[k], target, nums.length - 1);
    }
}