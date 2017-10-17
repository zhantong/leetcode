public class Solution {

    int[] origin;
    int[] nums;

    public Solution(int[] nums) {
        origin = nums;
        this.nums = Arrays.copyOf(nums, nums.length);
    }

    /**
     * Resets the array to its original configuration and return it.
     */
    public int[] reset() {
        return origin;
    }

    /**
     * Returns a random shuffling of the array.
     */
    public int[] shuffle() {
        int length = nums.length;
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            int swapIndex = random.nextInt(length);
            int temp = nums[i];
            nums[i] = nums[swapIndex];
            nums[swapIndex] = temp;
        }
        return nums;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */